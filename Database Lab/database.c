/*
 - Student Name: ##############
 - Student No: 012295724
 - Date: 12/1/2020
 - IDE version: XCode Version 12.0 (12A7209)
 - OS version: MacOS Catalina (10.15.6)
 - Lab Assignment: Database Lab
 */

/*
 PROBLEM STATEMENT
 *
 *      This lab will focus on the use and manipulation of structures. Each section of the lab should be designed within its own function, passing parameters as necessary. You are to construct a C program, database. c, which will retrieve and manipulate a company's payroll database, payfile.txt. The data for each employee should be read into a struct containing the following field identifiers:
 *
 *      ///////
 *      * first     7 char max
 *      * initial   1 char max
 *      * last      9 char max
 *      * street    16 char max
 *      * city      11 char max
 *      * state     2 cha max
 *      * zip       5 char max
 *      * age       int
 *      * sex       1 char max (M/F)
 *      * tenure    int representing years of employment
 *      * salary    double representing weekly salary
 *      ///////
 *
 *      Your program should perform each of the operations indicated below. Be sure to clearly label your output for each section. Remember, each section of the lab should be designed within its own function, passing parameters as necessary.
 *
 *      a) Read data for employees into an array of structures.
 *      b) Output the contents of each structure into an easily read format, similar to the format of the input file.
 *      c) Output the first and last name of all men on the payroll.
 *      d) Output the first and last name of the highest paid woman on the payroll.
 *      e) Output the first and last name of the lowest paid man on the payroll.
 *      f) Output the average salary for all the employees.
 *      g) Output the first and last name of all women earning less than the average salary.
 *      h) Output to three decimal places the ratio of the number of men above the average salary to the number men below the average salary.
 *      i) Output the first and last name of all employees who make more than $35,000 per year, have been with the company for at least 5 years, and who are over 30 years old.
 *      j) Give a 10% raise to all employees who make less than $350.00 per week and output the first and last name and new salary for each of the employees who received the raise.
 *      k) (Extra Credit) Sort the structures according to zip codes and output the first and last name and zip code for each of the employees.
 *
 *      Here is a C function, strsub(), that grabs a substring, sub, from a string, buf, given the start and end index within the string.
 *
 *      ///////
 *      void strsub(char buf[], char sub[], int start, int end) {
 *          int i, j;
 *
 *          for(j=0, i=start; i<=end; i++, j++) {
 *              sub[j] = buf[i];
 *          }
 *          sub[j] = '\0';
 *      }
 *      ///////
 *
 *      This function might be useful when you read a line of data from the file and need to grab the different information from the line of data to place into the fields of the struct. Remember that arrays use zero-based indexing.
 *
 *      ///////
 *      #define MAX_BUFFER 100
 *
 *      ...
 *
 *      while(!feof(fp)){
 *          fgets(buf, MAX_BUFFER, fp)
 *          strsub(buf, workers[i].first, 0, 6);
 *          strsub(buf, workers[i].initial, 8, 8);
 *          strsub(buf, workers[i].last, 10, 18);
 *          ...
 *          ...
 *      }
 *      ///////
 *
 *      The following three functions from the C library, stdlib.h and string.h, might be useful for this lab:
 *
 *      ///////
 *      atoi() - converts a string to an integer
 *      atof() - converts a string to a float
 *      strcmp() - compares two strings
 *      ///////
 *
 *      For the extra credit portion of the lab you will need to modify the sorting algorithm that we looked at to work with structs
 *
 *
 
 ANALYSIS
 *
 *  INPUTS
 *     1. payfile.txt
 *  OUTPUTS
 *     1. the contents of each structure in an easily read format
 *     2. first and last name of all men on the payroll
 *     3. first and last name of the highest paid woman on the payroll
 *     4. first and last name of the lowest paid man on the payroll
 *     5. average salary for all the employees
 *     6. first and last name of all women earning less than the average salary
 *     7. ratio of the number of men above the average salary to the number men below the average salary
 *     8. the first and last name of all employees who make more than $35,000 per year, have been with the company for at least 5 years, and who are older than 30
 *     9. the first and last name and new salary for each employees that received a raise
 *  CONSTRAINTS
 *     1. program should perform each of the operations indicated
 *     2. clearly label output for each section
 *     3. each section of the lab should be designed within its own function, passing parameters as necessary
 *  FORMULAS
 *     1. none
 
 DESIGN (List all the first-level steps and then step-wise refine each main step with one or more sub-steps)
 *
 *  1. readData() | Read data for employees into an array of structures | Section A
 *      1.1. open stream to file
 *      1.2. read each line of data from file using gets, iterate until EOF using {{ while(!feof()) }}
 *      1.3. fill in structure with data
 *          1.3.1. use strsub function to copy sections of gets string
 *          1.3.2. store int and double values using atoi() and atof()
 *  2. printPayroll() | Output the contents of each structure into an easily read format, similar to the format of the input file | Section B
 *      2.1. iterate through array
 *      2.2. print using control  strings and payroll[i].feild format
 *  3. nameAllMen() | Output the first and last name of all men on the payroll | Section C
 *      3.1. iterate through array
 *      3.2. if payroll[i].sex equals 'M', print payroll[i].first and payroll[i].last
 *  4. highestWoman() | Output the first and last name of the highest paid woman on the payroll | Section D
 *      4.1. iterate through array
 *      4.2. if .sex equals 'F', compare .salary to stored salary
 *      4.3. if .salary is greater than stored salary, store position
 *      4.4. after entrie array done, print payroll[i].first and payroll[i].last of last stored position
 *  5. lowestMan() | Output the first and last name of the lowest paid man on the payroll | Section E
 *      5.1. iterate through array
 *      5.2. if .sex equals 'M', compare .salary to stored salary
 *      5.3. if .salary is less than stored salary, store position
 *      5.4. after entrie array done, print payroll[i].first and payroll[i].last of last stored position
 *  6. avgSalary() | Output the average salary for all the employees | Section F
 *      6.1. iterate through array and add each salary to sum
 *      6.2. divide by number of employees
 *  7. belowAvgWomen() | Output the first and last name of all women earning less than the average salary | Section G
 *      7.1. iterate through array
 *      7.2. if .sex equals 'F' and .salary is less than average then print payroll[i].first and payroll[i].last
 *  8. ratioMen() | Output to three decimal places the ratio of the number of men above the average salary to the number men below the average salary | Section H
 *      8.1. iterate through array
 *      8.2. if .sex equals 'M', compare .salary to average salary
 *      8.3. if greater than, add 1 to above count
 *      8.4. if less than, add 1 to below count
 *      8.5. divide above count by below count to get the ratio
 *  9. richBoomers() | Output the first and last name of all employees who make more than $35.000 per year, have been with the company for at least 5 years, and who are over 30 years old | Section I
 *      9.1. iterate through array
 *      9.2. if .age is greater than 30,
 *      9.3. if .salary times 52 weeks is greater than 35,000,
 *      9.4. if .tenure is greater than or equal to 5 years
 *      9.5. print payroll[i].first and payroll[i].last
 *  10. giveRaise() | Give a 10% raise to all employees who make less than $350.00 per week and output the first and last name and new salary for each of the employees who received the raise | Section J
 *      10.1. iterate through array
 *      10.2. if .salary is less than $350.00 per week
 *      10.3. calculate 10% of current salary
 *      10.4. add raise amount to current salary and set to current salary
 *      10.5. print payroll[i].first and payroll[i].last and payroll[i].salary
 
 
 TEST CASE (Predict the output result of your program)
 *
 *  Test Case 1
 *     Identify the Input (What does the application need from the user or some other source?)
 *        - payfile.txt:
 *                  ADA     A AGUSTA    33 BABBAGE ROAD  LOVELACE    GB 19569 28 F 2 350.50
 *                  ISSAC   A ASIMOV    99 FICTION WAY   AMHERST     MA 63948 58 M 6 423.88
 *                  HUMPHRY R BOGART    71 SAM STREET    HOLLYWOOD   CA 48482 56 M 5 366.00
 *                  ALBERT  G EINSTEIN  94 ENERGY WAY    PRINCETON   NJ 47474 67 M 8 780.00
 *                  EMMYLOU L HARRIS    66 COUNTRY ROAD  NASHVILLE   TN 72647 38 F 2 767.42
 *                  JAMES   T KIRK      11 SPACE STREET  VULCAN      CA 82828 46 M 1 235.70
 *                  TED     L KOPPEL    55 ABC PLACE     WASHINGTON  DC 37376 48 M 9 909.44
 *                  DAVID   T LETTERMAN 14 WNBC AVENUE   NEW YORK    NY 19338 47 M 5 445.65
 *                  STEVIE  R NICKS     31 MUSIC ROAD    CHICAGO     IL 23459 38 F 8 460.88
 *                  MONTY   P PYTHON    76 SILLY STREET  LONDON      GB 80939 44 M 2 320.50
 *                  ROGER   R RABBIT    15 LOONEY TOONS  HOLLYWOOD   CA 91343 24 M 4 259.53
 *                  SALLY   W RIDE      21 COLUMBIA WAY  HOUSTON     TX 91123 30 F 9 707.80
 *                  ROD     Q SERLING   11 TWLIGHT ZONE  SAN DIEGO   CA 93939 56 M 1 440.00
 *                  LUKE    R SKYWALKER 43 MILKY WAY     NEW YORK    NY 12343 35 M 5 660.00
 *     Identify the Output (What is the result the application will produce given the input provided?)
 *        - output:
 *                   Employee Name 		Street 			City 	  State	  Zip	Age Sex Tenure	Salary
 *                  ----------------------------------------------------------------------------------
 *                  ADA     A AGUSTA   	33 BABBAGE ROAD LOVELACE   	GB 	 19569	 28	 F	  2		350.50
 *                  ISSAC   A ASIMOV   	99 FICTION WAY  AMHERST    	MA 	 63948	 58	 M	  6		423.88
 *                  HUMPHRY R BOGART   	71 SAM STREET   HOLLYWOOD  	CA 	 48482	 56	 M	  5		366.00
 *                  ALBERT  G EINSTEIN 	94 ENERGY WAY   PRINCETON  	NJ 	 47474	 67	 M	  8		780.00
 *                  EMMYLOU L HARRIS   	66 COUNTRY ROAD NASHVILLE  	TN 	 72647	 38	 F	  2		767.42
 *                  JAMES   T KIRK     	11 SPACE STREET VULCAN     	CA 	 82828	 46	 M	  1		235.70
 *                  TED     L KOPPEL   	55 ABC PLACE    WASHINGTON 	DC 	 37376	 48	 M	  9		909.44
 *                  DAVID   T LETTERMAN	14 WNBC AVENUE  NEW YORK   	NY 	 19338	 47	 M	  5		445.65
 *                  STEVIE  R NICKS    	31 MUSIC ROAD   CHICAGO    	IL 	 23459	 38	 F	  8		460.88
 *                  MONTY   P PYTHON   	76 SILLY STREET LONDON     	GB 	 80939	 44	 M	  2		320.50
 *                  ROGER   R RABBIT   	15 LOONEY TOONS HOLLYWOOD  	CA 	 91343	 24	 M	  4		259.53
 *                  SALLY   W RIDE     	21 COLUMBIA WAY HOUSTON    	TX 	 91123	 30	 F	  9		707.80
 *                  ROD     Q SERLING  	11 TWLIGHT ZONE SAN DIEGO  	CA 	 93939	 56	 M	  1		440.00
 *                  LUKE    R SKYWALKER	43 MILKY WAY    NEW YORK   	NY 	 12343	 35	 M	  5		660.00
 *                  ----------------------------------------------------------------------------------
 *
 *                  Male Employees:
 *                  ISSAC   ASIMOV
 *                  HUMPHRY BOGART
 *                  ALBERT  EINSTEIN
 *                  JAMES   KIRK
 *                  TED     KOPPEL
 *                  DAVID   LETTERMAN
 *                  MONTY   PYTHON
 *                  ROGER   RABBIT
 *                  ROD     SERLING
 *                  LUKE    SKYWALKER
 *
 *                  Highest Paid Female Employee:
 *                  EMMYLOU HARRIS
 *
 *                  Lowest Paid Male Employee:
 *                  JAMES   KIRK
 *
 *                  Average Salary:
 *                  $509.09 per week
 *
 *                  Female Employees Making Less Than The Average Salary:
 *                  ADA     AGUSTA
 *                  STEVIE  NICKS
 *
 *                  Ratio of Men Making Above The Average Salary To Men Making Below The Average Salary:
 *                  0.429
 *
 *                  Employees Making 35,000/year, Older Than 30, and Tenure Greater Than 5:
 *                  ALBERT  EINSTEIN
 *                  TED     KOPPEL
 *                  SALLY   RIDE
 *
 *                  Employees Who Received a 10% Raise (including new salary):
 *                  JAMES   KIRK     	$259.27
 *                  MONTY   PYTHON   	$352.55
 *                  ROGER   RABBIT   	$285.48
 *
 
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//-->> Global Variables
FILE *fp;
FILE *fpay;

#define MAX_BUFFER 100
#define MAX_EMPLOYEE 20 // maximum number of employees
#define PRINT_PAYROLL_FIRST_LINE " Employee Name \t\tStreet \t\t\tCity \t  State\t  Zip\tAge Sex Tenure\tSalary" // first line output from printPayroll function
#define PRINT_PAYROLL_DASH_LINE  "----------------------------------------------------------------------------------" // second and last lines output from printPayroll function
#define PRINT_PAYROLL_PRINT_FORM "%s %c %s\t%s\%s\t%s \t %s\t %d\t %c\t  %d\t\t%6.2lf\n" //printf output for printPayroll function

typedef struct {
    char first[8];   // 7 char max
    char initial;    // 1 char max
    char last[10];   // 9 char max
    char street[17]; // 16 char max
    char city[12];   // 11 char max
    char state[3];   // 2 cha max
    char zip[6];     // 5 char max
    int age;         // int
    char sex;        // 1 char max (M/F)
    int tenure;      // int representing years of employment
    double salary;   // double representing weekly salary
} Employee;

Employee payroll[MAX_EMPLOYEE]; // declare array payroll of struct Employee

char male = 'M'; // defines male as character M for easier control statements (better code readbility)
char female = 'F'; // defines female as character F for easier control statements (better code readbility)

//-->> Function Prototypes
int readFile(void); // Reads data for employees into an array of structures using gets; Returns number of employees as int
void strsub(char buffer[], char sub[], int start, int end); // Takes the string to be copied (buf), the destination of the string (sub), the position of buf from which to start copying, and end position as arguments; Copies specified section of buf to sub and adds null terminator; Returns nothing
void printPayroll(int num); // Takes int numEmployees as argument; Outputs the employee data in an easily read format; Returns nothing
void nameAllMen(int num); // Takes int numEmployees as argument; Outputs the first and last name of all men on the payroll; Returns nothing
void highestWoman(int num); // Takes int numEmployees as argument; Outputs the first and last name of the highest paid woman on the payroll; Returns nothing
void lowestMan(int num); // Takes int numEmployees as argument; Outputs the first and last name of the lowest paid man on the payroll; Returns nothing
double avgSalary(int num); // Takes int numEmployees as argument; Outputs the average salary for all the employees; Returns average salary
void belowAvgWomen(int num, double avg); // Takes int numEmployees and averagePay as arguments; Output the first and last name of all women earning less than the average salary; Returns nothing
void ratioMen(int num, double avg); // Takes int numEmployees and averagePay as arguments; Output to three decimal places the ratio of the number of men above the average salary to the number men below the average salary; Returns nothing
void richBoomers(int num); // Takes int numEmployees as argument; Outputs the first and last name of all employees who make more than $35,000 per year, have been with the company for at least 5 years, and who are over 30 years old; Returns nothing
void giveRaise(int num); // Takes int numEmployees as argument; Gives a 10% raise to all employees who make less than $350.00 per week and outputs the first and last name and new salary for each of the employees who received the raise; Returns nothing

//-->> Function Definitions

// -- Main -- //
int main(int argc, const char * argv[]) {
    //-->> File Setup
    // Set output file (csis.txt)
    fp = fopen("/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Database/csis.txt","w");
    if(!fp) { // Error checkpoint
        printf("Can't open %s\n", "csis.txt");
        exit(1);
    }
    //-->> Local Variables
    
    //-->> Start Of Executables
    
    int numEmployees = readFile();                 // Reads data for employees into an array of structures using gets; Returns number of employees as int
    
    printPayroll(numEmployees);                    // Passes Takes int numEmployees as argument; Outputs the employee data in an easily read format; Returns nothing
    
    nameAllMen(numEmployees);                      // Passes int numEmployees as argument; Outputs the first and last name of all men on the payroll; Returns nothing
    
    highestWoman(numEmployees);                    // Passes int numEmployees as argument; Outputs the first and last name of the highest paid woman on the payroll; Returns nothing
    
    lowestMan(numEmployees);                       // Passes int numEmployees as argument; Outputs the first and last name of the lowest paid man on the payroll; Returns nothing
    
    double averagePay = avgSalary(numEmployees);   // Passes int numEmployees as argument; Outputs the average salary for all the employees; Returns average salary
    
    belowAvgWomen(numEmployees, averagePay);       // Passes int numEmployees and averagePay as arguments; Output the first and last name of all women earning less than the average salary; Returns nothing
    
    ratioMen(numEmployees, averagePay);            // Passes int numEmployees and averagePay as arguments; Output to three decimal places the ratio of the number of men above the average salary to the number men below the average salary; Returns nothing
    
    richBoomers(numEmployees);                     // Passes int numEmployees as argument; Outputs the first and last name of all employees who make more than $35,000 per year, have been with the company for at least 5 years, and who are over 30 years old; Returns nothing
    
    giveRaise(numEmployees);                       // Passes int numEmployees as argument; Gives a 10% raise to all employees who make less than $350.00 per week and outputs the first and last name and new salary for each of the employees who received the raise; Returns nothing
    
    
    //-->> End Of Program
    putchar('\n'); //formating
    return 0;
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



// -- Read File Data -- //
// Reads data for employees into an array of structures using gets.
// Returns: the number of employees on the payroll file
int readFile(void){
    //-->> File Setup
    fpay = fopen("/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Database/payfile.txt","r"); //Opens stream to input txt file
    if(!fpay) { // Error checkpoint
        printf("Can't open %s\n", "payfile.txt");
        exit(1);
    }
    //-->> Local Variables
    int i = 0;
    char buffer[MAX_BUFFER], age[3], tenure[2], salary[7];
    
    //-->> Start Of Executables
    while(!feof(fpay)){
        fgets(buffer, MAX_BUFFER, fpay);
        strsub(buffer, payroll[i].first, 0, 6);     // copy buffer (from 00 to 06) to first of employee at payroll position i
        strsub(buffer, &payroll[i].initial, 8, 8);  // copy buffer (from 08 to 08) to initial of employee at payroll position i
        strsub(buffer, payroll[i].last, 10, 18);    // copy buffer (from 10 to 18) to last of employee at payroll position i
        strsub(buffer, payroll[i].street, 20, 35);  // copy buffer (from 20 to 35) to street of employee at payroll position i
        strsub(buffer, payroll[i].city, 37, 47);    // copy buffer (from 37 to 47) to city of employee at payroll position i
        strsub(buffer, payroll[i].state, 49, 50);   // copy buffer (from 49 to 50) to state of employee at payroll position i
        strsub(buffer, payroll[i].zip, 52, 56);     // copy buffer (from 52 to 56) to zip of employee at payroll position i
        strsub(buffer, age, 58, 59);                // copy buffer (from 58 to 59) to char array age
        payroll[i].age = atoi(age);                 // convert char array age to integer and set to int age of employee at payroll position i
        strsub(buffer, &payroll[i].sex, 61, 61);    // copy buffer (from 61 to 61) to sex of employee at payroll position i
        strsub(buffer, tenure, 63, 63);             // copy buffer (from 63 to 63) to char array tenure
        payroll[i].tenure = atoi(tenure);           // convert char array age to integer and set to int tenure of employee at payroll position i
        strsub(buffer, salary, 65, 70);             // copy buffer (from 65 to 70) to char array salary
        payroll[i].salary = atof(salary);           // convert char array salary to float and set to double salary of employee at payroll position i
        i++; // incement payroll position
        
    }
    //-->> End Of Function
    fclose(fpay); //closes stream
    return i;
}



// -- Print Payroll List -- //
// Outputs the employee data in an easily read format
// Param 1: int numEmployees, the number of employees on the payroll file
// Returns: None
void printPayroll(int num){
    //-->> Local Variables
    
    //-->> Start Of Executables
    puts(PRINT_PAYROLL_FIRST_LINE); fputs(PRINT_PAYROLL_FIRST_LINE, fp); putc('\n', fp);
    puts(PRINT_PAYROLL_DASH_LINE); fputs(PRINT_PAYROLL_DASH_LINE, fp); putc('\n', fp);
    for(int i=0; i < num; i++){
        printf( PRINT_PAYROLL_PRINT_FORM,
               payroll[i].first,   // %s     - prints first of employee at payroll position i
               payroll[i].initial, // %c     - prints initial of employee at payroll position i
               payroll[i].last,    // %s     - prints last of employee at payroll position i
               payroll[i].street,  // %s     - prints street of employee at payroll position i
               payroll[i].city,    // %s     - prints city of employee at payroll position i
               payroll[i].state,   // %s     - prints state of employee at payroll position i
               payroll[i].zip,     // %s     - prints zip of employee at payroll position i
               payroll[i].age,     // %d     - prints age of employee at payroll position i
               payroll[i].sex,     // %c     - prints sex of employee at payroll position i
               payroll[i].tenure,  // %d     - prints tenure of employee at payroll position i
               payroll[i].salary); // %6.2lf - prints 6 character with 2 point precision of salary of employee at payroll position i
        fprintf(fp, PRINT_PAYROLL_PRINT_FORM, payroll[i].first, payroll[i].initial, payroll[i].last, payroll[i].street, payroll[i].city, payroll[i].state, payroll[i].zip, payroll[i].age, payroll[i].sex, payroll[i].tenure, payroll[i].salary); //prints to csis.txt file
    }
    puts(PRINT_PAYROLL_DASH_LINE); fputs(PRINT_PAYROLL_DASH_LINE, fp); putc('\n', fp);
    //-->> End Of Function
}



// -- Name All Men -- //
// Outputs the first and last name of all men on the payroll.
// Param 1: int numEmployees, the number of employees on the payroll file
// Returns: None
void nameAllMen(int num){
    //-->> Local Variables
    int i;
    char *firstLine = "\nMale Employees:";
    //-->> Start Of Executables
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    for(i=0; i < num; i++){
        if(payroll[i].sex == male){ // if
            printf("%s %s\n", payroll[i].first, payroll[i].last); fprintf(fp, "%s %s\n", payroll[i].first, payroll[i].last); // prints first and last name
        }
    }
    fputc('\n', fp);
    //-->> End Of Function
    
}


// -- Highest Paid Female -- //
// Outputs the first and last name of the highest paid woman on the payroll
// Param 1: int numEmployees, the number of employees on the payroll file
// Returns: None
void highestWoman(int num){
    //-->> Local Variables
    int i, j;
    char *firstLine = "\nHighest Paid Female Employee:";
    //-->> Start Of Executables
    for(j=-1, i=0; i < num; i++){ // iterates through all structres
        if(payroll[i].sex == female){ // if employee is female
            if(j==-1){ // if j has not been set yet
                j=i; // set to position of first female
            }
            else{ //if j has been set
                if(payroll[i].salary > payroll[j].salary){// if salary is greater than the current saved salary
                    j=i; // then set that employee as highest
                }
            }
        }
    }
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    printf("%s %s\n", payroll[j].first, payroll[j].last); fprintf(fp, "%s %s\n", payroll[j].first, payroll[j].last); // prints first and last name
    //-->> End Of Function
    
}


// -- Lowest Paid Male -- //
// Outputs the first and last name of the lowest paid man on the payroll
// Param 1: int numEmployees, the number of employees on the payroll file
// Returns: None
void lowestMan(int num ){
    //-->> Local Variables
    int i, j;
    char *firstLine = "\nLowest Paid Male Employee:";
    //-->> Start Of Executables
    for(j=-1, i=0; i < num; i++){ // iterates through all structres
        if(payroll[i].sex == male){ // if employee is male
            if(j==-1){ // if j has not been set yet
                j=i; // set to position of first male
            }
            else{ //if j has been set
                if(payroll[i].salary < payroll[j].salary){ // if salary is less that the current saved salary
                    j=i; // then set that employee as lowest
                }
            }
        }
    }
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    printf("%s %s\n", payroll[j].first, payroll[j].last); fprintf(fp, "%s %s\n", payroll[j].first, payroll[j].last); // prints first and last name of lowest paid man
    //-->> End Of Function
    
}


// -- Average Salary -- //
// Outputs the average salary for all the employees
// Param 1: int numEmployees, the number of employees on the payroll file
// Returns: average salary (double)
double avgSalary(int num){
    //-->> Local Variables
    int i;
    double sum = 0, avg;
    char *firstLine = "\nAverage Salary:";
    //-->> Start Of Executables
    for(i=0; i < num; i++){
        sum += payroll[i].salary;
    }
    avg = (double) (sum / num);
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    printf("$%6.2lf per week\n", avg); fprintf(fp, "$%6.2lf per week\n", avg);
    //-->> End Of Function
    return avg;
}


// -- Women Below Average Salary -- //
// Output the first and last name of all women earning less than the average salary
// Param 1: int numEmployees, the number of employees on the payroll file
// Param 2: average salary
// Returns: None
void belowAvgWomen(int num, double avg){
    //-->> Local Variables
    int i;
    char *firstLine = "\nFemale Employees Making Less Than The Average Salary:";
    //-->> Start Of Executables
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    for(i=0; i < num; i++){
        if(payroll[i].sex == female){ // if sex is equal to 'F'
            if(payroll[i].salary < avg){ // if payroll less than average
                printf("%s %s\n", payroll[i].first, payroll[i].last); fprintf(fp, "%s %s\n", payroll[i].first, payroll[i].last); // prints first and last name
            }
        }
    }
    //-->> End Of Function
    
}


// -- Ratio of Men -- //
// Output to three decimal places the ratio of the number of men above the average salary to the number men below the average salary
// Param 1: int numEmployees, the number of employees on the payroll file
// Param 2: average salary
// Returns: None
void ratioMen(int num, double avg){
    int numAbove = 0, numBelow = 0, i;
    float ratio;
    char *firstLine = "\nRatio of Men Making Above The Average Salary To Men Making Below The Average Salary:";
    //-->> Start Of Executables
    for(i=0; i < num; i++){
        if(payroll[i].sex == male){
            if(payroll[i].salary < avg){ // if man makes above salary
                ++numBelow; // increment
            } else { // if man makes above salary
                ++numAbove; // increment
            }
        }
    }
    ratio = (double) numAbove / numBelow; // calc ratio: # of men above /  # of men below
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    printf("%.3lf\n", ratio); fprintf(fp, "%.3lf\n", ratio);
    //-->> End Of Function
    
}


// -- Rich Boomers -- //
// Output the first and last name of all employees who make more than $35,000 per year, have been with the company for at least 5 years, and who are over 30 years old.
// Param 1: int numEmployees, the number of employees on the payroll file
// Returns: None
void richBoomers(int num){
    //-->> Local Variables
    int i;
    char *firstLine = "\nEmployees Making 35,000/year, Older Than 30, and Tenure Greater Than 5:";
    //-->> Start Of Executables
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    for(i=0; i < num; i++){
        if(payroll[i].age >= 30){
            if((52 * payroll[i].salary) > 35000){ // if employee makes more than $35,000 per year (multiply per week salary by
                if(payroll[i].tenure >= 5){ // if employee has been with the company for at least 5 years
                    printf("%s %s\n", payroll[i].first, payroll[i].last); fprintf(fp, "%s %s\n", payroll[i].first, payroll[i].last); // prints first and last name
                }
            }
        }
    }
    //-->> End Of Function
    
}


// -- 10% Raise -- //
// Gives a 10% raise to all employees who make less than $350.00 per week and outputs the first and last name and new salary for each of the employees who received the raise.
// Param 1: int numEmployees, the number of employees on the payroll file
// Returns: None
void giveRaise(int num){
    //-->> Local Variables
    int i;
    double raise;
    char *firstLine = "\nEmployees Who Received a 10% Raise (including new salary):"; //section title
    //-->> Start Of Executables
    puts(firstLine); fputs(firstLine, fp); fputc('\n', fp); // print section title
    for(i=0; i < num; i++){ // iterates through all employees
        if(payroll[i].salary < 350){         // if employee makes less than $350.00 per week
            raise = .10 * payroll[i].salary; // calculate 10% of current salary
            payroll[i].salary += raise;      // adds raise amount to current salary and sets to current salary
            printf("%s %s\t$%6.2lf\n", payroll[i].first, payroll[i].last, payroll[i].salary); fprintf(fp, "%s %s\t$%6.2lf\n", payroll[i].first, payroll[i].last, payroll[i].salary); // prints first and last name and new salary
        }
    }
    //-->> End Of Function
    
}

