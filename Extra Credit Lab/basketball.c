/*
 - Student Name: ##########
 - Student No: ##########
 - Date: 12/10/2020
 - IDE version: XCode Version 12.0 (12A7209)
 - OS version: MacOS Catalina (10.15.6)
 - Lab Assignment: Extra Credit Lab
 */

/*
 PROBLEM STATEMENT
 *  Read basketball data from scores.txt and do the following
 *      - Store data in an array of structs
 *      - Output the data in an easily read format
 *      - Output the team with the highest score
 *      - Output the team names sorted by points
 *      - Output the team names sorted by home games won
 *      - Output the teams that played their last game in November
 *
 *
 *  scores.txt has format:
 *      ///////
 *      * name               22 char max
 *      * games played       int
 *      * won at home        int
 *      * lost at home       int
 *      * won away           int
 *      * lost away          int
 *      * date of last game  8 char max, in mm.dd.yy format
 *      ///////
 
 ANALYSIS
 *
 *  INPUTS
 *     1. scores.txt
 *
 *  OUTPUTS
 *     1. the data in an easily read format
 *     2. the team with the highest score
 *     3. the team names sorted by points
 *     4. the team names sorted by home games won
 *     5. the teams that played their last game in November
 *
 *  CONSTRAINTS
 *     1. none
 *  FORMULAS
 *     1. none
 
 DESIGN (List all the first-level steps and then step-wise refine each main step with one or more sub-steps)
 *
 *  1. allocate the memory for the struct
 *     1.1. count newline characters in file
 *  2. read data from file
 *     2.1. use gets to read each line
 *     2.2. use strsub to copy from gets string to feilds in struct
 *  3. print the scores
 *     3.1. print a title line
 *     3.2. print each field using control strings
 *  4. highest team
 *      4.1. iterate through array of structs
 *      4.2. compare point to last stored team's points, store if greater than
 *      4.3. print name of last stored position
 *  5. sort teams by points
 *      5.1. create temporay struct and sort it using qsort
 *      5.2. print team names in order
 *  6. sort teams by home games won
 *      6.1. create temporay struct and sort it using qsort
 *      6.2. print team names in order
 *  7. print teams that played their last game in November
 *      7.1. if last game month = 11
 *      7.2. then print team name

 
 TEST CASE (Predict the output result of your program)
 *
 *  Test Case 1
 *     Identify the Input (What does the application need from the user or some other source?)
 *          scores.txt:
 *              Golden State Warriors  25 12  0 10  3 11/01/2020
 *              LA Lakers              25 11  2  9  3 11/14/2020
 *              UIUC Fighting Illini   26 13  1  6  6 11/15/2020
 *              Boston College Eagles  26  9  4  8  5 11/20/2020
 *              ND Fighting Irish      26 11  2  4  9 12/05/2020
 *     Identify the Output (What is the result the application will produce given the input provided?)
 *              Team                     G      WH     LH     WA     LA      Won     Lost      Points    Last Game
 *              Golden State Warriors    25     12      0     10      3      22        3         47      11/1/2020
 *              LA Lakers                25     11      2      9      3      20        5         45      11/14/2020
 *              UIUC Fighting Illini     26     13      1      6      6      19        7         45      11/15/2020
 *              Boston College Eagles    26      9      4      8      5      17        9         43      11/20/2020
 *              ND Fighting Irish        26     11      2      4      9      15       11         41      12/5/2020
 *
 *
 *              Highest Scoring Team:
 *              Golden State Warriors
 *
 *              Teams Sorted by Total Points
 *              ND Fighting Irish
 *              Boston College Eagles
 *              LA Lakers
 *              UIUC Fighting Illini
 *              Golden State Warriors
 *
 *              Teams Sorted by Home Games Won
 *              Boston College Eagles
 *              ND Fighting Irish
 *              LA Lakers
 *              Golden State Warriors
 *              UIUC Fighting Illini
 *
 *              Teams that Last Played in Nov:
 *              Boston College Eagles
 *              LA Lakers
 *              Golden State Warriors
 *              UIUC Fighting Illini

 *
 
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//-->> Global Variables
FILE *fp;
FILE *fin;

typedef struct{
    int month; // mm
    int day; // dd
    int year; // yyyy
} Date;

typedef struct {
    char name[23]; // name of the basketball club
    int games; //
    int homeWins, homeLosses;
    int awayWins, awayLosses;
    int totalWins, totalLosses;
    int totalPoints;
    Date lastGame;
} Stats;

Stats *scoresTable;
#define SCORES_TXT "/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Basketball/scores.txt"
#define CSIS_TXT "/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Basketball/csis.txt"
#define MAX_BUFFER 53


//-->> Function Prototypes
int  allocateMem(void); // Dynamically allocates memory for array of Stats structs; Returns the number of lines
void strsub(char [], char [], int, int); // Takes the string to be copied (buf), the destination of the string (sub), the position of buf from which to start copying, and end position as arguments; Copies specified section of buf to sub and adds null terminator; Returns nothing
void readScores(void); // reads the .txt file and saves the contents into scoresTable array; Returns nothing
void printScores(int); // Takes int as argument; Outputs the data in easily readable format; Returns nothing
void highestTeam(int); // Takes int as argument; Outputs the name of the team with the highest total points; Returns nothing
void sortedPoints(int); // Takes int as argument; Output the team names sorted by points; Returns nothing
int  comparePoints(const void *p, const void *q); // part of qsort() in the sortedPoints function, sorts array in increasing order. Returns: { -1 if p < q }{ 0 if p = q }{ 1 if p > q }
void sortedHGW(int); // Takes int as argument; Output the team names sorted by home games won; Returns nothing
int  compareHGW(const void *p, const void *q); // part of qsort() in the sortedHGW function, sorts array in increasing order. Returns: { -1 if p < q }{ 0 if p = q }{ 1 if p > q }
void playedNov(int); // Takes int as argument; Output the teams that played their last game in November; Returns nothing

//-->> Function Definitions

// -- Main -- //
int main(int argc, const char * argv[]) {
    //-->> File Setup
    fp = fopen( CSIS_TXT ,"w"); //Opens straem to output file
    if(!fp) {
        printf("Can't open %s\n", "csis.txt");
        exit(1);
    }
    //-->> Local Variables
    
    
    
    //-->> Start Of Executables
    int numTeams = allocateMem(); //  Dynamically allocates memory for array of Stats structs; Returns the number of lines (teams)

    readScores(); // reads the .txt file and saves the contents into scoresTable array; Returns nothing
    
    printScores(numTeams); // Passes numTeams to function; Output the data in an easily read format; Returns nothing
    
    highestTeam(numTeams); // Passes numTeams to function; Output the team with the highest score; Returns nothing
    
    sortedPoints(numTeams); // Passes numTeams to function; Output the team names sorted by points; Returns nothing
    
    sortedHGW(numTeams); // Passes numTeams to function; Output the team names sorted by home games won; Returns nothing
    
    playedNov(numTeams); // Passes numTeams to function; Output the teams that played their last game in November; Returns nothing
    
    //-->> End Of Program
    fclose(fp);
    return 0;
}

// -- Allocate Memory -- //
// Dynamically allocates memory for array of Stats structs
// Param 1: <#None#>
// Param 2:
// Returns: <#None#>
int allocateMem(void){
    //-->> File Setup
    fin = fopen( SCORES_TXT ,"r"); //Opens stream to input file
    if(!fin) {
        printf("Can't open %s\n", "scores.txt");
        exit(1);
    }
    //-->> Local Variables
    int num = 1; //will be used to dynamically allocate memory for scoresTable (array of structs)
    char c;

    //-->> Start Of Executables
    while ( (c = fgetc(fin)) != EOF ){  // get a character until EOF
            if (c == '\n'){ //if it's a newline character
                    num++; // then increase memory allocation for scoresTable array
            }
    }
    scoresTable = (Stats *) malloc(sizeof(Stats) * (num)); // allocating enough memory to store the data from .txt file
    if (scoresTable == NULL){
        printf("Memory allocation error\n");
        exit(1);
    }
    //-->> End Of Function
    fclose(fin); // close the stream
    return num;
}


// -- Copy Section Of String to String-- //
// Copies each element of buffer between start and end to sub and adds null terminator
// Param 1: buffer char array (from fgets), the string to be copied
// Param 2: char array sub, the destination of string
// Param 3: int start, the position from which to start copying
// Param 4: int end, the position at which to stop copying
// Returns: None
void strsub(char buf[], char sub[], int start, int end) {
    int i, j;

    for(j=0, i=start; i<=end; i++) {
        sub[j] = buf[i];
        j++;
    }
    sub[j] = '\0';
}


// -- Read Data -- //
// reads data from input file into scoresTable array of struct
// Param 1: None
 // Returns: numTeams
void readScores(void){
    //-->> File Setup
    fin = fopen( SCORES_TXT ,"r"); //Opens stream to input file
    if(!fin) {
        printf("Can't open %s\n", "scores.txt");
        exit(1);
    }
    //-->> Local Variables
    int i = 0;
    char buffer[MAX_BUFFER], games[3], homeWins[3], homeLosses[3], awayWins[3], awayLosses[3], month[3], day[3], year[5];
    
    //-->> Start Of Executables
    while(!feof(fin)){
        fgets(buffer, MAX_BUFFER, fin);
        
        strsub(buffer, scoresTable[i].name, 0, 21);     // copy buffer (from 00 to 21) to name of team stats at scoresTable position i
        strsub(buffer, games, 23, 24);                  // copy buffer (from 23 to 24) to char array games
        scoresTable[i].games = atoi(games);             // convert char array games to integer and set to int games of team stats at scoresTable position i
        strsub(buffer, homeWins, 26, 27);               // copy buffer (from 26 to 27) to char array games
        scoresTable[i].homeWins = atoi(homeWins);       // convert char array homeWins to integer and set to int awayWins of team stats at scoresTable position i
        strsub(buffer, homeLosses, 29, 30);             // copy buffer (from 29 to 30) to char array homeLosses
        scoresTable[i].homeLosses = atoi(homeLosses);   // convert char array homeLosses to integer and set to int homeLosses of team stats at scoresTable position i
        strsub(buffer, awayWins, 32, 33);               // copy buffer (from 32 to 33) to char array awayWins
        scoresTable[i].awayWins = atoi(awayWins);       // convert char array awayWins to integer and set to int awayWins of team stats at scoresTable position i
        strsub(buffer, awayLosses, 35, 36);             // copy buffer (from 35 to 36) to char array salary
        scoresTable[i].awayLosses = atoi(awayLosses);   // convert char array awayLosses to integer and set to int awayLosses of team stats at scoresTable position i
        strsub(buffer, month, 38, 39);                  // copy buffer (from 38 to 39) to char array month
        scoresTable[i].lastGame.month = atoi(month);    // convert char array month to integer and set to int month of lastGame of team stats at scoresTable position i
        strsub(buffer, day, 41, 42);                    // copy buffer (from 41 to 42) to char array day
        scoresTable[i].lastGame.day = atoi(day);        // convert char array day to integer and set to int day of lastGame of team stats at scoresTable position i
        strsub(buffer, year, 44, 47);                   // copy buffer (from 44 to 47) to char array year
        scoresTable[i].lastGame.year = atoi(year);      // convert char array year to integer and set to int year of lastGame of team stats at scoresTable position i
        scoresTable[i].totalWins = scoresTable[i].homeWins + scoresTable[i].awayWins;               // set totalWins to the sum of homeWins and awayWins
        scoresTable[i].totalLosses = scoresTable[i].homeLosses + scoresTable[i].awayLosses;         // set totalLosses to the sum of homeLosses and awayLosses
        scoresTable[i].totalPoints = (scoresTable[i].totalWins * 2) + scoresTable[i].totalLosses;   // set totalPoint to the sum of the totalLosses and double the totalWins
        i++; // increment scoresTable position
        
    }
    //-->> End Of Function
    fclose(fin); //closes stream
}


// -- Print Scores -- //
// Prints stats of all teams
// Param 1: number of teams
// Returns: None
void printScores(int num){
    //-->> Local Variables
    int i;
    char *firstLine = "Team                     G      WH     LH     WA     LA      Won     Lost      Points    Last Game";
    //-->> Start Of Executables
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp);
    for (i = 0; i < num; i++){//for every element in scoresTable, print the variables stored
        printf("%-22s%5d  %5d  %5d  %5d  %5d   %5d    %5d      %5d      %2d/%d/%4d\n",
               scoresTable[i].name,
               scoresTable[i].games,
               scoresTable[i].homeWins,
               scoresTable[i].homeLosses,
               scoresTable[i].awayWins,
               scoresTable[i].awayLosses,
               scoresTable[i].totalWins,
               scoresTable[i].totalLosses,
               scoresTable[i].totalPoints,
               scoresTable[i].lastGame.month,
               scoresTable[i].lastGame.day,
               scoresTable[i].lastGame.year);
        fprintf(fp, "%-22s%5d  %5d  %5d  %5d  %5d   %5d    %5d      %5d      %2d/%d/%4d\n",
                scoresTable[i].name,
                scoresTable[i].games,
                scoresTable[i].homeWins,
                scoresTable[i].homeLosses,
                scoresTable[i].awayWins,
                scoresTable[i].awayLosses,
                scoresTable[i].totalWins,
                scoresTable[i].totalLosses,
                scoresTable[i].totalPoints,
                scoresTable[i].lastGame.month,
                scoresTable[i].lastGame.day,
                scoresTable[i].lastGame.year);
    }
    //-->> End Of Function
}


// -- Highest Scoring Team -- //
// Output the team with the highest score
// Param 1: number of teams
// Returns: None
void highestTeam(int num){
    //-->> Local Variables
    int i, j;
    char *firstLine = "\n\nHighest Scoring Team:";
    //-->> Start Of Executables
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp);
    for(i=0, j=i+1; i<num; i++){
        if(scoresTable[i].totalPoints > scoresTable[j].totalPoints){
            j=i;
        }
    }
    puts(scoresTable[j].name); fputs(scoresTable[j].name, fp); fputc('\n', fp);
    //-->> End Of Function
}




// -- Sorted by Points  -- //
// Output the team names sorted by points
// Param 1: number of teams
// Returns: None
void sortedPoints(int num){
    //-->> Local Variables
    char *firstLine = "\nTeams Sorted by Total Points";
    Stats *temp = malloc(sizeof(scoresTable));
    temp = scoresTable;
    //-->> Start Of Executables
    qsort(temp, num, sizeof(Stats), comparePoints);
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp);
    for(int i = 0; i < num; i++){
        printf("%s\n", temp[i].name); fprintf(fp, "%s\n", temp[i].name);
    }
    //-->> End Of Function
}

// -- Compare for Sort by Home Games Won -- //
// part of qsort() in the sortedHGW function | sorts array in increasing order
// Returns: • -1 if p < q
//          •  0 if p = q
//          •  1 if p > q
int comparePoints(const void *p, const void *q){
    if(((Stats *)p)->totalPoints < ((Stats *)q)->totalPoints) {
        return -1;
    }
    return ((Stats *)p)->totalPoints > ((Stats *)q)->totalPoints;
}



// -- Sorted by Home Games Won  -- //
// Output the team names sorted by home games won
// Param 1: number of teams
// Returns: None
void sortedHGW(int num){
    //-->> Local Variables
    char *firstLine = "\nTeams Sorted by Home Games Won";
    Stats *temp = malloc(sizeof(scoresTable));
    temp = scoresTable;
    //-->> Start Of Executables
    qsort(temp, num, sizeof(Stats), compareHGW);
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp);
    for(int i = 0; i < num; i++){
        printf("%s\n", temp[i].name); fprintf(fp, "%s\n", temp[i].name);
    }
    //-->> End Of Function
}

// -- Compare for Sort by Home Games Won -- //
// part of qsort() in the sortedHGW function | sorts array in increasing order
// Returns: • -1 if p < q
//          •  0 if p = q
//          •  1 if p > q
int compareHGW(const void *p, const void *q){
    if(((Stats *)p)->homeWins < ((Stats *)q)->homeWins) {
        return -1;
    }
    return ((Stats *)p)->homeWins > ((Stats *)q)->homeWins;
}



// -- Last Played in November -- //
// Outputs the teams that played their last game in November
// Param 1: number of teams
// Returns: None
void playedNov(int num){
    //-->> Local Variables
    char *firstline = "\nTeams that Last Played in Nov:";
    //-->> Start Of Executables
    puts(firstline); fputs(firstline, fp); fputc('\n', fp);
    for(int i = 0; i < num; i++){
        if(scoresTable[i].lastGame.month == 11){
            puts(scoresTable[i].name); fputs(scoresTable[i].name, fp); fputc('\n', fp);
        }
    }
}

