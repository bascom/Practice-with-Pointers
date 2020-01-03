// Practice with Pointers_4_2 - Jan 2 2020.cc
// Matthew C. Bascom

// The below running list of file names are "on point" with the subject matter of pointers.
// I took a tangent into comparing memory usage with 2_3 through 2_7. 

// Completed Practice with Pointers_4_1.cc at "2020-01-02 18:01:03 PST" | Thurs., Jan 2, 2020.
// Completed Practice with Pointers_3_1.cc at "2020-01-02 17:27:13 PST" | Thurs., Jan 2, 2020.
// Completed Practice with Pointers_2_2.cc at "2020-01-02 14:14:42 PST" | Thurs., Jan 2, 2020.
// Completed Practice with Pointers_2_1.cc at "2019-12-30 20:58:38 PST" | Mon., Dec 30, 2019.
// Completed Practice with Pointers_1_1.cc at 00:56 (12:56AM) | Monday, December 23, 2019
// Completed "Practice with Pointers_1_2.cc" at "2019-12-28 07:11:20 PST" | Sat., Dec 28, 2019
// Completed "Practice with Pointers_1_3_cc" at "2019-12-28 09:33:35 PST" ... complete with bug.

// Iteration 4_2 is just like 4_1 programatically, an illustration of string tokenization,
// but cleaner and without the irrelevant comments. See:
// Breedlove, Seevers, and Albert chapter 12 slide deck, available at learnbydoing.com

// There are 127 slides corresponding to the chapter 12 deck. 
// The following slides will guide this script: { (66), (63), 57, (43), (22) }
   // (63) - Passing pointers by reference. 
   // (66) - Passing pointers by pointer. *** Start here. *** 
   // (43) - string tokenization
   // (22) - passing by pointer - nested functions. DONE. (12/30/2019)
   // 57 - ? - revisit...The new operator for dynamically allocating arrays.

// This shell command labels each block of assembly code with its corresponding line in c++:
// c++ -S -fverbose-asm file.cc -o out.s

/* * * * * * * * * * * * * * * * * * * * *
 * What does this program do?
 * 
 * This code, 4_2, tokenizes a hard-coded string by using the StringTokSample function.
 * * * * * * * * * * * * * * * * * * * * */


/**************************
 * Illustration: 
 * User input and output: 
 * 
 * (shell)$ ./out_4_1
 *  
 * Our string to be tokenized is the character array textTitle
 * and contains the following string: C++: Learn by Doing
 * 
 * The tokens are:
 * C++:
 * Learn
 * by
 * Doing
 * 
 * After strtok - textTitle = C++:
 **************************/

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::strcpy;
using std::endl;

// Function prototypes / declarations.
void StringTokSample();

int BUFFER_LENGTH = 256;


int main(){

StringTokSample(); 

return 0;

} // end main.

// Definitions.

void StringTokSample(){
    char textTitle[] = "C++: Learn by Doing";
    char * p_token = nullptr;

    cout << "Our string to be tokenized is the character array textTitle\n"
         << "and contains the following string: " << textTitle
         << "\n\nThe tokens are:\n";

    // Begin Tokenization:
    p_token = strtok(textTitle, " "); 
                                     // Notice the (" ") space delimiter.
    // Continue tokenizing until p_token becomes NULL.
    while(p_token != NULL){
        cout << p_token << '\n';

        // Get next token, or NULL nullptr.
        p_token = strtok(NULL, " ");

    } // End while(p_token != NULL) loop.
    
    cout << "\nAfter strtok - textTitle = " << textTitle << endl;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
