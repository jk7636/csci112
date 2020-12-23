/*
 - Student Name: Joseph Kirven
 - Student No: 012295724
 - Date: 10/2/2020
 - IDE version: XCode Version 12.0 (12A7209)
 - OS version: MacOS Catalina (10.15.6)
 - Lab Assignment: Wages Lab
 */

/*
 PROBLEM STATEMENT
 *  Write a c program that calculates an employees gross pay, taxes, and net pay. The program should calculate overtime pay, if necessary. Overtime is paid as time and a half for each hour worked over 40 hours.
 *  Salary w/o overtime pay:
 *      wages = hours * payrate
 *  Salary w/ overtime pay:
 *      wages = (40 * payrate) + (hours - 40) * 1.5 * payrate
 *  Taxes are calculated as follows:
 *      20% on the first $200
 *      25% on the next $250
 *      30% on the remaining gross pay
 *  For each run of the program, prompt the user for both hours and payrate.
 *
 *  Run 1:
 *      hours = 28.5
 *      payrate = 22.75
 *  Run 2:
 *      hours = 63.75
 *      payrate = 35.25
 
 ANALYSIS
 *
 *  INPUTS
 *      1. hours
 *      2. payrate
 *  OUTPUTS
 *      1. net pay
 *      2. taxes
 *      3. gross pay
 *  CONSTRAINTS
 *      1. Overtime is paid as time and a half for each hour worked over 40 hours.
 *      2. Be able to run the program for multiple employees without changing code
 *  FORMULAS
 *      1. Salary w/o overtime pay: (Formula 1)
 *              wages = hours * payrate
 *      2. Salary w/ overtime pay: (Formula 2)
 *              wages = (40 * payrate) + ((hours - 40) * 1.5 * payrate)
 
 DESIGN (List all the first-level steps and then step-wise refine each main step with one or more sub-steps)
 *
 *  1. Get the employee's hours and pay
 *      1.1. Ask for hours hours worked [hours]
 *      1.2. Ask for payrate in dollars/hour [payrate]
 *  2. Calculate salary [wages]
 *      2.1. Determine if employee worked overtime
 *          2.1.1. If they worked over 40 hours, use Formula 1
 *          2.1.2. If they worked under 40 hours, use Formula 2
 *      2.2. Use chosen formula to calculate salary and store to wages
 *      2.3. Print wages as gross pay
 *  3. Calculate Taxes
 *      3.1. Set remainingPay = wages
 *      3.2. Apply 20% on the first $200
 *          3.2.1. set taxes to 20% of $200 = $40
 *          3.2.2. Subtract $200 from remainingPay and set to remainimgPay
 *          3.2.3. set netTaxes to taxes (40)
 *      3.3. Apply 25% on the next $250
 *          3.3.1. set taxes to 25% of $250 = $62.5
 *          3.3.2. Subtract $250 from remainingPay and set to remainimgPay
 *          3.3.3. set netTaxes = taxes + netTaxes
 *      3.4. Apply 30% on the remaining gross pay
 *          3.4.1. set taxes to 30% of remainingPay
 *          3.4.2. set netTaxes = taxes + netTaxes
 *      3.5. Print netTaxes as total tax
 *  4. Calculate net pay
 *      4.1. Set netPay = wages - netTaxes
 *      4.2. print net pay



 
 TEST CASE (Predict the output result of your program)
 *
 *  Test Case 1
 *      Identify the Input (What does the application need from the user or some other source?)
 *          - hours = 28.5
 *          - payrate = 22.75
 *      Identify the Output (What is the result the application will produce given the input provided?)
 *          - net pay = $486.36
 *          - taxes = $158.6
 *          - gross pay = $648.37
 *  Test Case 2
 *      Identify the Input (What does the application need from the user or some other source?)
 *          - hours = 63.75
 *          - payrate = 35.25
 *      Identify the Output (What is the result the application will produce given the input provided?)
 *          - net pay = $486.36
 *          - taxes = $158.6
 *          - gross pay = $648.375
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
FILE *fp;

//-->> Function Prototypes
float calcWages(float hours, float payrate);
float calcTaxes(float wages);
float calcPay(float wages, float netTaxes);

//-->> Global Variables

float hours, payrate, wages, netPay, netTaxes;// Declare all global float variables

//-->> Function Definitions
// -- Main -- //
int main(int argc, const char * argv[]) {
    fp = fopen("/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Wages/csis2.txt","w"); //Sets output file
    //-->> Start Of Executables
    printf("Input Hours: "); fprintf(fp, "Input Hours: "); //Prints prompt to console and csis.txt file
    scanf("%f", &hours); // Gets hours from employee
    fprintf(fp, "%f", hours); // Prints response to csis.txt file
    printf("Input Payrate: "); fprintf(fp, "\nInput Payrate: "); //Prints prompt to console and csis.txt file
    scanf("%f", &payrate); // Gets payrate from employee
    fprintf(fp, "%f", payrate); // Prints response to csis.txt file
    calcWages(hours, payrate); //Calls calcWages function with hours and payrate as inputs
    printf("\nGross Pay:\t$%.2f\n", wages); fprintf(fp, "\nGross Pay:\t$%.2f\n", wages); //Prints wages to console and csis.txt file as Gross Pay
    calcTaxes(wages); // Calls calcTaxes function with wages as the input
    printf("Taxes:\t\t$%.2f\n", netTaxes); fprintf(fp, "Taxes:\t\t$%.2f\n", netTaxes); //Prints netTaxes to console and csis.txt file as Taxes
    calcPay(wages, netTaxes); //Calls calcPay function with wages and netTaxes as inputs
    printf("Net Pay:\t$%.2f\n", netPay); fprintf(fp, "Net Pay:\t$%.2f\n", netPay); //Prints netnetPay to console and csis.txt file as Net Pay
    //-->> End Of Program
    fclose(fp);
    return 0;
}

// -- Calculate Wages -- //
// Determines if employee worked overtime and calculates wages using appropiate formula
// Inputs: hours and payrate (floats)
// Output: wages (float)
float calcWages(float hours, float payrate){
    if (hours >= 40) { // If employee has worked overtime, then:
        wages = (40 * payrate) + ((hours - 40) * 1.5 * payrate); // (Formula 2) Calculates wages with overtime
    } else { // If employee has not worked overtime, then:
        wages = hours * payrate; // (Formula 1) Calculates wages without overtime
    }
    return wages;
}
// -- Calculate Taxes -- //
// Calculates taxes of the wages. Applies 20% on the first $200, 25% on the next $250, and 30% on the remaining gross pay.
// Inputs: wages (float)
// Output: net taxes (float)
float calcTaxes(float wages){
    //-->> Local Variables
    float taxes, remainingPay = wages;
    netTaxes = 0.0f;
    // -- Apply 20% on the first $200
    taxes = .2 * 200;
    remainingPay = remainingPay - 200;
    netTaxes = netTaxes + taxes;
    // -- Apply 25% on the next $250
    taxes = .25 * 250;
    remainingPay = remainingPay - 250;
    netTaxes = netTaxes + taxes;
    // -- Apply 30% on the remaining gross pay
    taxes = .3 * remainingPay;
    netTaxes = netTaxes + taxes;
    return netTaxes;
}
// -- Calculate Net Pay -- //
// Calculates net pay by subtracting the net taxes from the wages.
// Inputs: wages and netTaxes (floats)
// Output: netPay (float)
float calcPay(float wages, float netTaxes){
    netPay = wages - netTaxes;
    return netPay;
}
