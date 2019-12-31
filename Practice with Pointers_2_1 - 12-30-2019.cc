// Practice with Pointers_2_1 - 12-30-2019.cc
// Matthew C. Bascom

// Completed Practice with Pointers_2_1.cc at "2019-12-30 20:58:38 PST" | Mon., Dec 30, 2019.
// Completed Practice with Pointers_1_1.cc at 00:56 (12:56AM) | Monday, December 23, 2019
// Completed "Practice with Pointers_1_2.cc" at "2019-12-28 07:11:20 PST" | Sat., Dec 28, 2019
// Completed "Practice with Pointers_1_3_cc" at "2019-12-28 09:33:35 PST" ... complete with bug.

// In iteration 2_1, I will begin working through illustrations presented in the 
// Breedlove, Seevers, and Albert chapter 12 slide deck, available at learnbydoing.com

// There are 127 slides corresponding to the chapter 12 deck. 
// The following slides will guide this script: { 66, 63, 57, 43, *22* }
   // 63 - Passing pointers by reference.
   // 63 - Passing pointers by pointer.
   // 43 - string tokenization
   // 22 - passing by pointer - nested functions. *** Start here. *** DONE.
   // 57 - ? - revisit...The new operator for dynamically allocating arrays.

// This note will carry over until I actually test this inquiry!
// I want to start studying how changes to my code correspond to changes in assembly
// Referring to screenshot '2019-11-29 15-04-03.png',
// This shell command labels each block of assembly code with its corresponding line in c++:
// c++ -S -fverbose-asm file.cc -o out.s

/* * * * * * * * * * * * * * * * * * * * *
 * What does this program do?
 * This program is a really great illustration of passing pointers to a function.
 * Below I assume the slide (p.22/127) is correct, and it is. With that assumption,
 * I go about describing how I understand the code flow, and observe that DisplayFraction
 * is, in fact, called twice. This is correct. And *how* that function is called appears
 * slightly different on the slide, as its call within GetFraction uses a dereference operator 
 * and its call directly from main does not. The only change I would make to the actual slide,
 * I made here in my implementation of the code, and that is to use "p_" when naming a 
 * pointer to a datatype, instead of naming a pointer like it's any other variable.
 * 
 * What to do with the rest of my last free Monday before returning to school??
 * It would be fun to implement this program using classes and giving the functions 
 * into their own header and program files...
 * * * * * * * * * * * * * * * * * * * * */


/**************************
 * Illustration: 
 * User input and output: 
 * 
 * (shell)$ ./out_2_1 
 * 
 * Enter numerator: 234
 * Enter denominator: 456
 * 234 / 456
 * 234 / 456
 **************************/

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::strcpy;
using std::endl;
                             // First assembly test. In assembly, what's the difference between
                             // using endl and '\n'? If I use it once, how much longer is the 
                             // compiled program? If I use it twice, is there any difference?
                         


// function prototypes / declarations.
 void GetFraction(int * p_numer, int * p_denom); 
 
 void FormatNegative(int * p_numer, int * p_denom);
 
 void DisplayFraction(int numer, int denom);

// Try to think in terms of TDD. I want to use these functions to print a fraction.
// The user is prompted for the numerator and denominator via the GetFraction function.
// Within GetFraction, the FormatNegative function tests the user input to see if 
// two negative numbers were entered and if the denominator is negative...
// Finally, GetFraction calls one more function, DisplayFraction, to print the 
// formated input. 

// I'm betting that this slide has issues. So to clarify the situation, I'm working 
// through this example. But I'll first try to think through the illustration as it's presented.

// Slide 22 is a bit lopsided. What I *think* it says is GetFraction takes the address
// of the variable using the address-of & when called. The GetFraction definition, in turn,
// uses the dereferencing * operator, which accesses the data of the specified type. 
// Once in GetFraction, the pointer variable - without the dereference - is passed into
// FormatNegative, which has the power to modify the variables. Finally, DisplayFraction
// passes the value of the pointers using the dereferencing operator and is called within
// GetFraction....though GetFraction is called twice - once from main and once within
// GetFraction. Here goes.....That's my understanding assuming everything on the slide is right.

int main(){
    
    int numer = 0, denom = 0;

    // These are calls, not declarations!
    GetFraction(&numer, &denom);
    DisplayFraction(numer, denom);

return 0;

} // end main.


// Definitions.
 void GetFraction(int * p_numer, int * p_denom){

     cout << "Enter numerator: ";
     cin >> *p_numer;
     cout << "Enter denominator: ";
     cin >> *p_denom;

     FormatNegative(p_numer, p_denom);
     DisplayFraction(*p_numer, *p_denom);

 }
 
 void FormatNegative(int * p_numer, int * p_denom){
     if(*p_numer < 0 && *p_denom < 0){
         *p_numer = abs(*p_numer);
         *p_denom = abs(*p_denom);
     }
     else if(*p_denom < 0){
         *p_numer *= *p_numer;
         *p_denom = abs(*p_denom); 
     }
 } // end FormatNegative definition.
 
 void DisplayFraction(int numer, int denom){
     cout << numer << " / " << denom << endl;
 } // end DisplayFraction definition.

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
