// Practice with Pointers_3_1 - Jan 2 2020.cc
// Matthew C. Bascom

// The below running list of file names are "on point" with the subject matter of pointers.
// I took a tangent into comparing memory usage with 2_3 through 2_7. Here in 3_1 I continue
// with the priority subject, that of pointers.

// Completed Practice with Pointers_3_1.cc at "2020-01-02 17:27:13 PST" | Thurs., Jan 2, 2020.
// Completed Practice with Pointers_2_2.cc at "2020-01-02 14:14:42 PST" | Thurs., Jan 2, 2020.
// Completed Practice with Pointers_2_1.cc at "2019-12-30 20:58:38 PST" | Mon., Dec 30, 2019.
// Completed Practice with Pointers_1_1.cc at 00:56 (12:56AM) | Monday, December 23, 2019
// Completed "Practice with Pointers_1_2.cc" at "2019-12-28 07:11:20 PST" | Sat., Dec 28, 2019
// Completed "Practice with Pointers_1_3_cc" at "2019-12-28 09:33:35 PST" ... complete with bug.

// Iteration 3_1, is an illustration of passing a pointer to a function by pointer. See:
// Breedlove, Seevers, and Albert chapter 12 slide deck, available at learnbydoing.com

// There are 127 slides corresponding to the chapter 12 deck. 
// The following slides will guide this script: { *66*, (63), 57, 43, (22) }
   // (63) - Passing pointers by reference. 
   // *66* - Passing pointers by pointer. *** Start here. *** 
   // 43 - string tokenization
   // (22) - passing by pointer - nested functions. DONE. (12/30/2019)
   // 57 - ? - revisit...The new operator for dynamically allocating arrays.

// This shell command labels each block of assembly code with its corresponding line in c++:
// c++ -S -fverbose-asm file.cc -o out.s

/* * * * * * * * * * * * * * * * * * * * *
 * What does this program do?
 * 
 * This program passes a character type pointer to a function by pointer.
 * Further, the function that takes the char pointer dynamically allocates 
 * an array for taking in a user input character string.
 * 
 * What to do before returning to school on January 6??
 * It would be fun to implement (program 2.2) using classes and placing the functions 
 * into their own header and program files...
 * * * * * * * * * * * * * * * * * * * * */


/**************************
 * Illustration: 
 * User input and output: 
 * 
 * (shell)$ ./out_3_1
 *  
 * Please enter a string: Passing a char pointer by pointer to GetString. And Matt is supercool.
 * Passing a char pointer by pointer to GetString. And Matt is supercool.
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
                         



 // The deprecated prototype declaration below, made use in 2_2 of this series, 
 // is passing a Pointer by reference:
 // void GetString(char *& str);

// Function prototypes / declarations.
void GetString(char ** str);

int BUFFER_LENGTH = 256;

// Try to think in terms of TDD. I really need to watch that TDD video again...but trying:

// I want a function to take a user-input string using dynamic memory allocation.
// In this file, the "new" keyword is used to dynamically allocate the array.
// But that's not TDD...if I simply call a GetString function from main, the program
// will fail because GetString must be declared above main and defined below.

// Within main, I will need an actual variable to pass into my GetString function 
// so that GetString has something to modifiy, seeing that the function itself returns void.

// In order for the function to successfully modify the variable, it must be passed by reference.

// I want to use these functions to print a fraction.
// The user is prompted for the numerator and denominator via the GetFraction function.
// Within GetFraction, the FormatNegative function tests the user input to see if 
// two negative numbers were entered and if the denominator is negative...
// Finally, GetFraction calls one more function, DisplayFraction, to print the 
// formated input. 

int main(){
    
char * p_str = nullptr;
                     // Initialize the character pointer p_str to nullptr.
GetString(&p_str);
                     // GetString takes the actual pointer and passes the 
                     // pointer into GetString.

//GetString(*p_str);     // Error: a ref type of "char*&" ... cannot be initialized with type char.
//GetString(&p_str);   // Error: Initial value of reference to non-const must be an lvalue.

cout << '\n' << p_str << endl;
delete[] p_str;                     
                     // Notice the dynamically allocated character array is 
                     // deleted using brackets ([],) the same way it was 
                     // dynamically allocated within the call to GetString.

return 0;

} // end main.


// Definitions.
void GetString(char ** str){

    char buffer[BUFFER_LENGTH];
    
    cout << "Please enter a string: ";

    cin.ignore(cin.rdbuf() -> in_avail());

    cin.getline(buffer, BUFFER_LENGTH);
    
    cin.clear();
    cin.ignore(cin.rdbuf() -> in_avail());

    /* * * * * * * * * * * * * * * * * * * * * * * * * 
     * Below, new initialized memory that is the length
     * of the buffer plus one extra space for the null 
     * character. Recall, a variable for setting the 
     * buffer size was set as a global variable and 
     * initialized above main.
     * 
     * In addition, buffer (above) is used to create a temporary
     * local array to receive user input; The "new" keyword
     * is then used to dynamically create an array exactly 
     * big enough for the string that was entered, plus null.
     * The string is then copied from buffer to the new string.
     * 
     * WARNING: "Dynamically allocated memory is only destroyed
     * when it is deleted: The address here will still be valid
     * even after the function has ended. 
     * Refer to Seever & Breedlove (2010) Sec. 12.10 p. 420-421.
     * * * * * * * * * * * * * * * * * * * * * * * * */

    *str = new char[strlen(buffer) + 1];
    strcpy(*str, buffer);


}   // end GetString function definition.


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
