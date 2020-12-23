/*
 - Student Name: #############
 - Student No: 012295724
 - Date: 11/13/2020
 - IDE version: XCode Version 12.2 (12B45b)
 - OS version: MacOS Catalina (10.15.6)
 - Lab Assignment: String Manipulation Lab
 */

/*
 PROBLEM STATEMENT
 *  Write a program that contains the following:
 *
 *      a) A function that replaces the contents of a string with the string reversed.
 *
 *      b) A function that takes a string as an argument and removes the spaces from the string.
 *
 *      c) A function that outputs the command-line arguments in reverse order.
 *
 *  Remember that the main ()function should appear as the first function in the program. Be sure to use function prototypes for each of the functions that are used in your program.
 *
 
 ANALYSIS
 *
 *  INPUTS
 *     1. string
 *  OUTPUTS
 *     1. string reversed
 *     2. string without spaces
 *     3. command-line arguments in reverse order
 *  CONSTRAINTS
 *     1. the main ()function should appear as the first function in the program
 *     2. use function prototypes for each of the functions that are used in your program
 *  FORMULAS
 *     1. none
 
 DESIGN (List all the first-level steps and then step-wise refine each main step with one or more sub-steps)
 *
 *  1. reverse_str() | function that replaces the contents of a string with the string reversed
 *     1.1. takes first command-line argument as function argument
 *     1.2. iterate through the array from the back and the front
 *  2. rm_spaces() | remove spaces from argument string
 *     2.1. takes second command-line argument as function argument
 *     2.2. iterate through the array
 *     2.3. only copy to second array if char is not a space
 *  3. cl_args_reverse() | outputs the command-line arguments in reverse order
 *     3.1. iterate using a decrement and print the command line arguments
 *
 
 TEST CASE (Predict the output result of your program)
 *
 *  Test Case 1
 *     Identify the Input (What does the application need from the user or some other source?)
 *        - this is the first string
 *        - this is the second string
 *     Identify the Output (What is the result the application will produce given the input provided?)
 *        - gnirts tsrif eht si siht
 *        - thisisthesecondstring
 *
 *        - Argument [2] is : this is the second string
 *        - Argument [1] is : this is the first string
 *
  
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
//-->> Global Variables
FILE *fp;

//-->> Function Prototypes

void reverse_str(const char buffer[]); // takes character array as argument, replaces the contents of a string with the string reversed, prints the result
void rm_spaces(const char buffer[]); // takes character array as argument, removes the spaces from a string, prints the result
void cl_args_reverse(int argc, const char * argv[]); // takes argc and argv array as arguments, prints argv in reverse order

//-->> Function Definitions

// -- Main -- //
int main(int argc, const char * argv[]) {
    //-->> File Setup
    fp = fopen("/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/String Manipulation/csis.txt","w"); //Sets output file
    if(!fp) { //Error checkpoint
        printf("Can't open %s\n", "csis.txt");
        exit(1);
    }
    //-->> Local Variables
   
    // None
    
    //-->> Start Of Executables
    reverse_str(argv[1]); // passes first command line argument as function argument, replaces the contents of a string with the string reversed, prints the result
    
    rm_spaces(argv[2]); // passes second command line argument as function argument, removes the spaces from a string, prints the result
    
    cl_args_reverse(argc, argv); // passes number of command line argument and the array of command line arguments by reference, prints command line arguments in reverse order

    //-->> End Of Program
    putchar('\n'); // for formatting csis.txt file
    fclose(fp);
    return 0;
}


// -- Reverse String -- //
// replaces the contents of a string with the string reversed and prints the result
// Param 1: string as char array from argv[1]
// Returns: None
void reverse_str(const char buffer[]){
    //-->> Local Variables
    int
        i = (int) (strlen(buffer) - 1), //sets i to the max position in the buffer
        j = 0; 
    char c, reversed[strlen(buffer)]; // create new char array to preserve contents of buffer (argv[1])
    //-->> Start Of Executables
    reversed[strlen(buffer)] = '\0'; //set the string to be null terminated
    while (i > j)
    {
        c = (char) buffer[i]; // copies buffer[i]
        reversed[i] = buffer[j];
        reversed[j] = c; // pastes buffer[i]
        i--;
        j++;
    }
    puts(reversed); fputs(reversed, fp);
    fputc('\n', fp); // for formatting csis file
    //-->> End Of Function

}


// -- Remove Spaces (Whitespace) -- //
// removes the spaces from a string and prints the result
// Param 1: string as char array from argv[2]
// Returns: None
void rm_spaces(const char buffer[]){
    //-->> Local Variables
    char spaceless[strlen(buffer)];
    int i, j;
    //-->> Start Of Executables
    for(i = 0, j = 0; i <= (int) strlen(buffer) - 1; i++){
        if(!isspace(buffer[i])){ // if element is not a space,
            spaceless[j] = buffer[i]; // copy to spaceless
            j++;
        }
    }
    puts(spaceless); fputs(spaceless, fp); fputc('\n', fp);
    //-->> End Of Function
}


// -- Command Line Arguments Revresed -- //
// prints command line arguments in reverse order
// Param 1: argument count (argc)
// Param 2: argument char array
// Returns: None
void cl_args_reverse(int argc, const char * argv[]){
    //-->> Start Of Executables
    while(--argc){ // while argc does not equal 0 / decrement argc
        printf("\nArgument [%d] is : %s", argc, argv[argc]); fprintf(fp, "\nArgument [%d] is : %s", argc, argv[argc]); // print argv in reverse order
    }
    //-->> End Of Function
}
