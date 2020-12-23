/*
 - Student Name: ###########
 - Student No: 012295724
 - Date: 11/1/2020
 - IDE version: XCode Version 12.0 (12A7209)
 - OS version: MacOS Catalina (10.15.6)
 - Lab Assignment: Statistics Lab
 */

/*
 PROBLEM STATEMENT
 *
 *         TEST SCORES = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 }
 *
 *  a) Write a C program, stats.c, that initializes an array at compile time with the test scores shown above and outputs the test scores, five per line.
 *
 *  b) Sort the test scores into ascending order and output the scores, five per line.
 *
 *  c) Calculate and output the frequency distribution chart as shown above. Note that the scores are listed in decreasing value within the table.
 *
 *  d) Output the percentage of passing and failing test scores to one decimal place. Scores below 60 are failing.
 *
 *  e) Calculate and output the mean of the test scores to one decimal place.
 *
 *  f) Output the mode of the test scores.
 *
 *  g) The median of a list of numbers is that element such that when the numbers are arranged  in ascending or descending order, half the elements lie above it and half below. This can happen only when there are an odd number of elements in the list. If the array contains an even number of items, the median is the average of the two numbers in the middle (to one decimal place). Your program should output the median of the test scores given to one decimal place. (Note: Your program should determine on its own whether there is an odd or even number of test scores).
 *
 *  Note that each section of the lab should be designed within its own function, passing parameters as necessary. Be sure to use the set of test data given above in your program and be sure you input the data in the order given.
 *
 *  Remember that the main() function should appear as the first function in the program. Be sure to use function prototypes for each of the functions that are used in your program.
 *
 
 ANALYSIS
 *
 *  INPUTS
 *     1. 30 test scores
 *  OUTPUTS
 *     a) output the test scores, five per line
 *     b) output the test scores in ascending order, five per line
 *     c) output the frequency distribution chart
 *     d) output the percentage of passing and failing test scores to one decimal place
 *     e) output the mean of the test scores to one decimal place
 *     f) output the mode of the test scores
 *     g) output the median of the test scores given to one decimal place
 *  CONSTRAINTS
 *     1. each section of the lab should be designed within its own function
 *  FORMULAS
 *     1. formula
 
 DESIGN (List all the first-level steps and then step-wise refine each main step with one or more sub-steps)
 *
 *  1. Section A
 *     1.1. initializes an array in main with the test scores
 *     1.2. calculate the number of ellements in the array
 *     1.3. create a function { five_out() } that outputs the test scores, five per line.
 *          1.3.1. make a for loop that runs through all the test scores, printing each one
 *          1.3.2. add an incremental counter variable to the for loop
 *          1.3.3. add an if statement that prints a newline character and resets the counter after it reaches 5
 *  2. Create function for Section B
 *     2.1. sort the test scores into ascending order
 *          2.1.1. copy the test scores to a new array
 *          2.1.2. apply qsort()
 *                 2.1.2.1. Use { if p < q; return p > q } for the compare function
 *                 2.1.2.2.
 *     2.2. use five_out() to output the test scores
 *  3. Create a function for Section C { frequency() }
 *     3.1. Calculate the frequency of each score
 *          3.1.1. Create frequency array
 *     3.2.
 *  4. Create a function for Section D { percentage() }
 *      4.1. count the number of scores below 60 (failing scores)
 *      4.2. calculate percent passing
 *          4.2.1. subtract the number of failing scores from the total number of scores
 *          4.2.2. divide that by the total number of scores and multiply by 100
            4.2.3. print result
 *      4.3. calculate percent failing
 *          4.3.1. divide the number of failing scores by the total number of scores and multiply by 100
 *          4.3.2. print result
 *  5. Create a function for Section E { mean() }
 *      5.1. iterate to find the sum
 *      5.2. divide by total number of scores
 *      5.3. print result
 *  6. Create a function for Section F { mode() }
 *      6.1. iterate through frequency array to find the index of the highest value (most frequent)
 *      6.2. print the value of that index of the srted array
 *  7. Create a function for Section G { median() }
 *      7.1. determine if array is even or odd
 *          7.1.2. if the remainder of the total number of scores divided by 2 equals 0, the number of scores is even
 *      7.2. Calculate the median
 *          7.2.1. if even, take the average of the two middle numbers
 *          7.2.2. if odd, the median is at the index of total number of scores divided by 2
 
 TEST CASE (Predict the output result of your program)
 *
 *  Test Case 1
 *     Identify the Input (What does the application need from the user or some other source?)
 *        - Scores from main():
 *             int scores[] = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 }
 *     Identify the Output (What is the result the application will produce given the input provided?)
 *
 *            Section A | Output in Original Order, Five Per Line
 *
 *            90    85    100   50    50
 *            85    60    70    55    55
 *            80    95    70    60    95
 *            80    100   75    70    95
 *            90    90    70    95    50
 *            65    85    95    100   65
 *
 *
 *            Section B | Sort in Ascending Order, Five Per Line
 *
 *            50    50    50    55    55
 *            60    60    65    65    70
 *            70    70    70    75    80
 *            80    85    85    85    90
 *            90    90    95    95    95
 *            95    95    100   100   100
 *
 *
 *            Section C | Frequency Distribution Chart
 *
 *            score    frequency
 *            -----    ---------
 *            100        3
 *             95        5
 *             90        3
 *             85        3
 *             80        2
 *             75        1
 *             70        4
 *             65        2
 *             60        2
 *             55        2
 *             50        3
 *
 *
 *            Section D | Percent Passing and Failing
 *
 *            Passing: 83.3%
 *            Failing: 16.7%
 *
 *
 *            Section E | Mean of Scores
 *
 *            Mean = 77.5
 *
 *
 *            Section F | Mode of Scores
 *
 *            Mode = 95
 *
 *
 *            Section G | Median of Scores
 *
 *            Median = 80.0
 *
 *
 
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
FILE *fp;


//-->> Function Prototypes
void five_out(int buffer[], int size); // Accepts an array and the size of array as arguments and prints the array, five elements per line, tab seperated
void sort(int buffer[], int sorted_buffer[], int size); // Takes scores array and sorted array and int size as arguments and applies qsort(), stores sorted values in sorted_buffer array
int compare(const void *p, const void *q); // part of qsort() in the sort function, sorts array in increasing order. Returns: { -1 if p < q }{ 0 if p = q }{ 1 if p > q }
void frequency(int buffer[], int freq_buffer[], int size); // Takes sorted and freq arrays and int size as arguments, and prints the frequency of the elements in the sorted array into two columns (score and frequency)
void percent(int buffer[], int size); // Takes scores array and size of array as arguments and outputs percent of scores above and below 60 (percent passing and percent failing)
void mean(int buffer[], int size); // Takes scores array and frequency array and int size as arguments and prints the average of the test scores
void mode(int buffer[], int freq_buffer[], int size); // Takes scores array and frequency array and int size as arguments and prints the most frequent test scores
void median(int buffer[], int size); // Takes scores array and size of array as arguments and outputs the median of the test scores given to one decimal place

//-->> Global Variables

// None

//-->> Function Definitions

// -- Main -- //
int main(int argc, const char * argv[]) {
    fp = fopen("/Users/josephkirven/Documents/Palomar/Fall 2020/Classes/CSCI 112/compsci112/compsci112/Labs/Statistics/csis.txt","w"); //Sets output file
    //-->> Local Variables
    
    int scores[] = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95, 80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 };
    int size = sizeof(scores) / sizeof(scores[0]); // calculates number of elements in the array by taking the size of the entire array and dividing by the size of the individual elements
    int sorted[size], // array to store the sorted scores
        freq[size]; // int array to store the frequency
   //-->> Start Of Executables
    
    /* Section A (print) */
    printf("Section A | Output in Original Order, Five Per Line\n\n"); fprintf(fp, "Section A | Output in Original Order, Five Per Line\n\n");
    five_out(scores, size); // passes the scores array by reference, outputs five items per line, returns nothing (void)
    
    /* Section B (sort) */
    sort(scores, sorted, size); // passes scores and sorted arays by reference and int size, sorts the scores in accending order using qsort(), stores sorted values in sorted array, returns nothing (void)
    five_out(sorted, size); // passes the sorted array by reference, outputs five items per line, returns nothing (void)
    
    /* Section C (frequency) */
    frequency(sorted, freq, size); // passes sorted and freq arrays by reference and int size, calculates the frequency of elements in sorted, stores frequency values to freq, print frequency table with scores in descending order, returns nothing (void)
    
    /* Section D (pass/fail percentage) */
    percent(scores, size); // passes scores by reference and int size, calculates pecent of score that is above (pass) and below (fail) 60%, prints percentages, returns nothing (void)
    
    /* Section E (mean) */
    mean(scores, size); // passes scores by reference and int size, calculates average of scores, prints result, returns nothing (void)
    
    /* Section F (mode) */
    mode(sorted, freq, size); // passes scores and freq by reference and int size, finds and prints the most frequent test score, returns nothing (void)
    
    /* Section G (median) */
    median(sorted, size); // passes scores by reference and int size, prints median, returns nothing (void)
    
    //-->> End Of Program
    puts("\n"); fputs("\n", fp);
    fclose(fp);

}


// -- Output Five Scores -- //
// Prints five array elements with tab seperator then inserts newline character
// Param 1: array to print
// Param 2: size of array
// Returns: None
void five_out(int buffer[], int size){
    for(int i = 0, counter = 1; i < size; ++i){
        if(counter > 4){ // if the counter is greater than 4 (ie 5) a newline char is added after the fifth item
            printf("%d\n", buffer[i]); fprintf(fp, "%d\n", buffer[i]);
            counter = 1;
        }
        else { // runs for the first 4 items on each line with a tab space between them so that it looks purty
            printf("%d\t", buffer[i]); fprintf(fp, "%d\t", buffer[i]);
            ++counter;
        }
    }
}


// -- Sort (Section B) -- //
// Sorts the scores in accending order using qsort()
// Param 1: scores array
// Param 2: size of scores array
// Param 3:
// Returns: none
void sort(int buffer[], int sorted_buffer[], int size) {
    printf("\n\nSection B | Sort in Ascending Order, Five Per Line\n\n"); fprintf(fp, "\n\nSection B | Sort in Ascending Order, Five Per Line\n\n");
    for(int i = 0; i < size; i++){ // make copy of buffer to preserve contents of buffer
        sorted_buffer[i] = buffer[i]; //copy buffer to sorted_buffer
    }
    qsort(sorted_buffer, size, sizeof(int), compare); // runs qsort() on sorted_buffer for t
}


// -- Compare for Sort (Section B) -- //
// part of qsort() in the sort function | sorts array in increasing order
// Returns: • -1 if p < q
//          • 0 if p = q
//          • 1 if p > q
int compare(const void *p, const void *q) {
    if (*(int *)p < *(int *)q) {
        return -1;
    }
    return *(int *)p > *(int *)q;
}


// -- Frequency (Section C) -- //
// Calculate and output a frequency distribution chart
// // Param 1: sorted scores array
// Param 2: size of scores array
// Returns: frequency array
void frequency(int buffer[], int freq_buffer[], int size){
    printf("\n\nSection C | Frequency Distribution Chart\n\n"); fprintf(fp, "\n\nSection C | Frequency Distribution Chart\n\n");
    int count, i, j;
    for(i = 0; i < size; i++){
        count = 1; // resets the count value
        for(j = i + 1; j < size; j++){
            if(buffer[i] == buffer[j]){ // iterates through the rest of the array for a match
                count++;
                freq_buffer[j] = -1; // for every occurance of the element except the first one, the corresponding position on the freq_buffer array is
            }                        // set to -1 after counting it so that the freq number lines up with the first occurance of the repeated element
        }
        if(freq_buffer[i] != -1){ // if position does not correspond to repeated element (ie position corresponds to first occurance of number) then:
            freq_buffer[i] = count; // set that position to the 0
        }
    }
    printf("score\tfrequency\n-----\t---------\n"); fprintf(fp, "score\tfrequency\n-----\t---------\n");
    for (i = size-1; i >= 0 ; i--){
        if(freq_buffer[i] != -1){
            printf("%4d\t%5d\n", buffer[i], freq_buffer[i]); fprintf(fp, "%4d\t%5d\n", buffer[i], freq_buffer[i]);
        }
    }
}


// -- Pass/Fail Percentage (Section D) -- //
// Output the percentage of passing and failing test scores to one decimal place. Scores below 60 are failing.
// Param 1: scores array
// Param 2: size of scores array
// Returns: None
void percent(int buffer[], int size){
    printf("\n\nSection D | Percent Passing and Failing\n\n"); fprintf(fp, "\n\nSection D | Percent Passing and Failing\n\n");
    float pass, fail, fail_count = 0;
    for(int i = 0; i < size; i++){
        if(buffer[i] < 60){ // count the number of scores below 60
            ++fail_count;
        }
    }
    pass = ((size - fail_count)/size)*100; // size - fail_count = number of remaining scores (passing scores)
    fail = (fail_count/size)*100;
    printf("Passing: %3.1f%%\nFailing: %3.1f%%\n", pass, fail); fprintf(fp, "Passing: %3.1f%%\nFailing: %3.1f%%\n", pass, fail);
}


// -- Mean (Section E) -- //
// output the mean of the test scores to one decimal place
// Param 1: scores array
// Param 2: size of scores array
// Returns: None
void mean(int buffer[], int size){
    printf("\n\nSection E | Mean of Scores\n\n"); fprintf(fp, "\n\nSection E | Mean of Scores\n\n");
    int sum = 0;
    for(int i = 0; i < size; i++){ // add each element to the sum
        sum += buffer[i];
    }
    float mean = (float)sum / size;
    printf("Mean = %.1f\n", mean); fprintf(fp, "Mean = %.1f\n", mean);
}


// -- Mode (Section F) -- //
// output the mode of the test scores
// Param 1: sorted array
// Param 2: frequency array
// Param 3: size of scores array
// Returns: None
void mode(int buffer[], int freq_buffer[], int size){
    printf("\n\nSection F | Mode of Scores\n\n"); fprintf(fp, "\n\nSection F | Mode of Scores\n\n");
    int i, j = 0;
    for(i = size-1; i >= 0; i--){
        if(freq_buffer[i] > freq_buffer[j]){ //finds the position of the most frequent number
            j=i;
        }
    }
    printf("Mode = %d\n", buffer[j]); fprintf(fp, "Mode = %d\n", buffer[j]);
}


// -- Median (Section G) -- //
// outputs the median of the test scores given to one decimal place
// Param 1: scores array
// Param 2: size of scores array
// Returns: None
void median(int buffer[], int size){
    printf("\n\nSection G | Median of Scores\n\n"); fprintf(fp, "\n\nSection G | Median of Scores\n\n");
    float median;
    if(size % 2 == 0){ // array has even number of items
        median = (buffer[(size-1)/2] + buffer[size/2]) / 2.0; // average of the two middle numbers
    }
    else{ // array has odd number of items
        median = buffer[size/2]; // middle number
    }
    printf("Median = %.1f\n", median); fprintf(fp, "Median = %.1f\n", median);
}
