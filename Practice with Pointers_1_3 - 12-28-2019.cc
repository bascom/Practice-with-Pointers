// Practice with Pointers_1_3 - 12-28-2019.cc
// Matthew C. Bascom
// Completed Practice with Pointers_1_1.cc at 00:56 (12:56AM) | Monday, December 23, 2019
// Completed "Practice with Pointers_1_2.cc" at "2019-12-28 07:11:20 PST" | Sat., Dec 28, 2019
// Completed "Practice with Pointers_1_3_cc" at "2019-12-28 09:33:35 PST" ... complete with bug.

// Reference: Chapter 12 - Albert and Breedlove - First Indian Edition 2010

// I want to start studying how changes to my code correspond to changes in assembly
// Referring to screenshot '2019-11-29 15-04-03.png',
// This shell command labels each block of assembly code with its corresponding line in c++:
// c++ -S -fverbose-asm file.cc -o out.s

// This is a working example of p.408 "Example" 12.7.3 "Subtracting Addresses."
// The code provided in the book is just the function declaration. I fill in the blanks...

/* * * * * * * * * * * * * * * * * * * * *
 * What does this function do?
 * 
 *   "This function finds the first instance of a character ch in the cString str.
 *   The function then returns the index of the specified character, or -1 if the 
 *   character is not found."
 * 
 * This function subtracts addresses. As stated in the text:
 * 
 *   "Since addresses are numbers, we can subtract two addresses.
 *   This concept, coupled with the knowledge that arrays are contiguous 
 *   blocks of memory, is what makes this function work."
 * 
 * * * * * * * * * * * * * * * * * * * * */


/**************************
 * Illustration: 
 * User input and output: 
 * 
 *   Enter a word: supercool
 *   Enter a character to locate with that word: c
 *   The output of the CharAt function is:
 *   5
 *   The output of the CharAtNoCast function is:
 *   5
 *   The output of the CharAtAddress function is:
 *   0x7ffc48831168
    * 
    * A closer look illustrates a bug:
    * 
    *   Enter a word: supercool
    *   Enter a character to locate with that word: s
    *   The output of the CharAt function is:
    *   0
    *   The output of the CharAtNoCast function is:
    *   0
    *   The output of the CharAtAddress function is:
    *   0x7ffe16649ef8
    *   The address of the actual character array user_word is: 
    *   0x7ffe16649f2e
    * 
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
                         

// CharAt Function Declaration.
int CharAt(char * str, char ch);

float CharAtNoCast(char * str, char ch);

char ** CharAtAddress(char * str, char ch);


int main(){
    
    char user_word[10];   
    char character_to_locate;
                         // WOW. At first I forgot to specify the number of elements in the 
                         // to hold in the character vector! Epic fail.
                        
    cout << "Enter a word: ";
    cin >> user_word;

    cout << "Enter a character to locate with that word: ";
    cin >> character_to_locate;

// DeleteString( user_word, start_pos, num_char);
// StrCpy(moved_word, user_word);

cout << "The output of the CharAt function is:" << '\n'
     << CharAt(user_word, character_to_locate) << '\n'
     << "The output of the CharAtNoCast function is:" <<'\n'
     << CharAtNoCast(user_word, character_to_locate) << '\n'
     << "The output of the CharAtAddress function is:" <<'\n'
     << CharAtAddress(user_word, character_to_locate) << '\n'
     << "The address of the actual character array user_word is: " <<'\n'
     << &user_word << '\n';

         // How do I take the difference of two hex values? This attempt failed:

         // << "&user_word - CharAtAddress():" << '\n'
         // << &user_word - CharAtAddress(user_word, character_to_locate);
             // error: invalid operands of types ‘char (*)[10]’ and ‘char**’ to binary ‘operator-’
             //  << &user_word - CharAtAddress(user_word, character_to_locate);

return 0;

}


// CharAt Function Definition.

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Notice the use of static_cast.
 * According to Albert & Breedlove p. 159,
 *   "...type casting can be used to force a value to be converted 
 *   from one type to another...However, the change may not always be 
 *   considered safe...There are often very valid reasons why...care 
 *   should be taken when using type casting."
 * 
 * Which makes me wonder what is returned without the cast?
 * Answer: It appears the correct integer is returned without the cast.
 * This is true whether the new CharAtNoCast function is defined as 
 * returning either a float or an int. Ah, but that's if return_val is 
 * defined within CharAtNoCast as an int....If I change return_val's 
 * declaration to float, does the output change? No.
 * 
 * What if I want to return the actual address? I did, with the 
 * CharAtAddress function. Though proceed with caution...I should test
 * to see if it's returning the address of the desired first character 
 * or the actual array. Let's check!
 * 
 * Some of my favorite outcomes of this exercise were the compile errors.
 * 
 *   Practice with Pointers_1_3 - 12-28-2019.cc:155:23: 
 *   error: cannot convert ‘char**’ to ‘char*’ in assignment
 *          return_val = &cur;
 * 
 * I had no idea to use char ** until the compiler told me so!
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int CharAt(char * str, char ch){

    char * cur = str;
    int return_val = -1;

    while(*cur != '\0' && *cur != ch){
        cur++;
    }  // end while loop.

    if(*cur != '\0'){
        return_val = static_cast<int> (cur - str);
    }
    
    return return_val;
} // end CharAt function definition.

float CharAtNoCast(char * str, char ch){

    char * cur = str;
    float return_val = -1;

    while(*cur != '\0' && *cur != ch){
        cur++;
    }  // end while loop.

    if(*cur != '\0'){
        return_val = (cur - str);
    }
    
    return return_val;
} // end CharAtNoCast function definition.

char ** CharAtAddress(char * str, char ch){

    char * cur = str;
    char ** return_val;

    while(*cur != '\0' && *cur != ch){
        cur++;
    }  // end while loop.

    if(*cur != '\0'){
        return_val = &cur;
    }
    
    return return_val;
} // end CharAtAddress function definition.
