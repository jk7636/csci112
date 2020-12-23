/*
 - Student Name: ##############
 - Student No: 012295724
 - Date: 11/20/2020
 - IDE Version: XCode Version 12.0 (12A7209)
 - OS version: MacOS Catalina (10.15.6)
 - Lab Assignment: Cipher Lab
 */

/*
 PROBLEM STATEMENT
 *      You will create a program, cipher.c, which will encode a message by shifting each letter some number of places.
 *
 *      Your program should first call a function, processFile () , which reads a message from a file (congress.txt) into a very large character array. The function should convert all of the letters into uppercase characters. You may discard all the punctuation marks, digits, blanks, and anything else from the input string.
 *
 *      Your program should then accept the amount to shift as an input to a function, cipher(). The input parameter should be 13, although for your testing purposes, you can simplify things by using a shift of 1. Your function should encode each letter by shifting it the correct amount, and put the encoded letters into null-terminated array of characters.
 *
 *    Finally, you should create a function, outputCode (), which outputs the final encoded message in blocks of five letters, ten blocks per line. The last line may be shorter than five blocks, and the last block may be shorter than five letters.
 *
 *    Be sure that your final program submission shows the result of a shift of 13.
 *
 
 ANALYSIS
 *
 *  INPUTS
 *     1. cipher shift
 *  OUTPUTS
 *     1. encoded message as blocks
 *  CONSTRAINTS
 *     1. convert all of the letters into uppercase characters
 *     2. discard all the punctuation marks, digits, blanks, and anything else from the input string
 *     3. encode each letter by shifting it the correct amount
 *     4. outputs the final encoded message in blocks of five letters, ten blocks per line
 *  FORMULAS
 *     1. none
 
 DESIGN (List all the first-level steps and then step-wise refine each main step with one or more sub-steps)
 *
 *  1. processFile()
 *     1.1. read text from congress.txt into character array
 *          1.1.1.
 *     1.2. convert all letters into uppercase characters
 *     1.3. discard punctuation marks, digits, blanks, and anything else
 *  2. cipher()
 *     2.1. accept the amount to shift as an input to a function (13)
 *          2.1.1. use scanf in main() to get cipher shift
 *     2.2. encode each letter by shifting it the correct amount
 *     2.3. put the encoded letters into null-terminated array of characters
 *  3. outputCode()
 *     3.1. output final encoded message ten blocks per line
 *     3.2. blocks of five letters
 
 
 TEST CASE (Predict the output result of your program)
 *
 *  Test Case 1
 *     Identify the Input (What does the application need from the user or some other source?)
 *        - Shift = 1
 *     Identify the Output (What is the result the application will produce given the input provided?)
 *        - DPOHS FTTTI BMMNB LFOPM BXSFT QFDUJ OHBOF TUBCM JTINF OUPGS
 *          FMJHJ POPSQ SPIJC JUJOH UIFGS FFFYF SDJTF UIFSF PGPSB CSJEH
 *          JOHUI FGSFF EPNPG TQFFD IPSPG UIFQS FTTPS UIFSJ HIUPG UIFQF
 *          PQMFQ FBDFB CMZUP BTTFN CMFBO EUPQF UJUJP OUIFH PWFSO NFOUG
 *          PSBSF ESFTT PGHSJ FWBOD FT
 
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
/*-->> Global Variables */

FILE *fp; // csis.txt
FILE *fr; // file read

/*-->> Function Prototypes */

void processFile(char buffer[], int *size);
void cipher(char contents[], char encoded[], int size, int shift);
void outputCode(char buffer[], int size);


/*-->> Function Definitions */

// -- Main -- //
int main(int argc, const char * argv[]) {
    //-->> File Setup
    fp = fopen("/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Cipher - EC/csis.txt","w"); //Sets output file
    if(!fp) {
        printf("Can't open %s\n", "csis.txt");
        exit(1);
    }
    //-->> Local Variables
    int size, shift;
    char rawContent[1000]; // buffer array for reading contents of text file, limits text files to 10000 characters
    
    //-->> Start Of Executables
    processFile(rawContent, &size); //sets buffer
    char contents[size], // char array for letters read from text file
         encoded[size]; // char array for encoded letters
    strncpy(contents, rawContent, size);
    printf("Cipher Shift Amount: "); fprintf(fp, "Cipher Shift Amount: "); //prints prompt
    scanf("%d", &shift); // gets input and stores to shift
    putchar('\n'); fprintf(fp, "%d\n", shift);
    cipher(contents, encoded, size, shift);
    outputCode(encoded, size);
    //-->> End Of Program
    fclose(fp);
    return 0;
}
// -- Process File -- //
// reads a message from a file (congress.txt) into a very large character array. The function should convert all of the letters into uppercase characters. You may discard all the punctuation marks, digits, blanks, and anything else from the input string
// Param 1: content array, allows function to read up to 10000 characters
// Param 2: pointer to int for size of array need
// Returns: array of letters from file
void processFile(char content[], int *size){
    //-->> File Setup
    fr = fopen("/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Cipher - EC/congress.txt", "r"); // opens the source text file as read-only
    if(!fr) { // checks if file successfully opened
        printf("Can't open %s\n", "congress.txt");
        exit(1); // stops program if file didn't open
    }
    //-->> Local Variables
    char c;
    int i = 0;
    
    //-->> Start Of Executables
    while( (c = getc(fr)) != EOF) { // reads each letter of the file untill it reaches EOF
        if(isalpha(c)){ // only adds character to buffer if it is a letter
            content[i] = toupper(c); // converts lowercase letters to upper
            ++i;
        }
    }
    *size = i; // sets the number of elements in array to the number of iterations (works b/c increment is after iteration)
    
    //-->> End Of Function
    fclose(fr);
}


// -- Cipher -- //
// encodes the string using a ceaser cipher with the user-defined shift
// Param 1: contents array
// Param 2: encoded char array
// Param 3: size of contents array
// Param 4: user defined shift from scanf
// Returns: None
void cipher(char buffer[], char encoded[], int size, int shift){
    //-->> Local Variables
    int i, limit;
    //-->> Start Of Executables
    for(i=0; i < size; i++){
        limit = 90 - shift; // 90 == (int) 'Z'; limit makes sure it loops fram Z to A
        if (buffer[i] <= limit){
            encoded[i] = (char) (buffer[i] + shift);
        } else {
            encoded[i] = (char) (buffer[i] + shift - 26);
        }
    }
    //-->> End Of Function

}

// -- Output Code -- //
// outputs the final encoded message in blocks of five letters, ten blocks per line
// Param 1: array to print
// Param 2: size of array
// Returns: None
void outputCode(char buffer[], int size){
    //-->> Local Variables
    int i, letter = 1, blocks=1;
    //-->> Start Of Executables
    for(i = 0; i < size; ++i){
        if(blocks <= 9){
            if(letter <= 4){
                printf("%c", buffer[i]); fprintf(fp, "%c", buffer[i]);
                ++letter;
            }
            else {
                printf("%c ", buffer[i]); fprintf(fp, "%c ", buffer[i]);
                letter = 1; // resets letter count
                ++blocks;
            }
        }
        else{
            if(letter <= 4){
                printf("%c", buffer[i]); fprintf(fp, "%c", buffer[i]);
                ++letter;
            }
            else {
                printf("%c", buffer[i]); fprintf(fp, "%c", buffer[i]);
                letter = 1; // resets letter count
                printf("\n"); fprintf(fp, "\n");
                blocks = 1; // resets block count
            }
        }
    }
    //-->> End Of Function
    printf("\n"); fprintf(fp, "\n");
}


