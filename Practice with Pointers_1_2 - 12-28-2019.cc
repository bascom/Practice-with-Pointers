// Practice with Pointers_1_2 - 12-28-2019.cc
// Matthew C. Bascom
// Completed Practice with Pointers_1_1.cc at 00:56 (12:56AM) | Monday, December 23, 2019
// Complete "Practice with Pointers_1_2.cc" at "2019-12-28 07:11:20 PST" | Sat., Dec 28, 2019


// Reference: Chapter 12 - Albert and Breedlove - First Indian Edition 2010

// I want to start studying how changes to my code correspond to changes in assembly
// Referring to screenshot '2019-11-29 15-04-03.png',
// This shell command labels each block of assembly code with its corresponding line in c++:
// c++ -S -fverbose-asm file.cc -o out.s

// This is a working example of p.408 "Example" 12.7.2 "Pointers and the Increment Operator."
// The code provided in the book is just the function declaration. I fill in the blanks...

/* * * * * * * * * * * * * * * * * * * * *
 * What does this function do?
 * 
 * StryCpy, like the traditional strcpy, copies characters from 
 * source to destination. The main feature of the StrCpy function is this:
 * "while(*dest++ = *src++);"
 * Notice the semicolon at the end of the while loop. Because the assignment operator
 * is used within the condition, the control variable is changing within the loop.
 * 
 * ***Because the null value equates to zero, and zero represents false, as soon
 *    as null is copied from src to dest, the loop will terminate.***
 * 
 * * * * * * * * * * * * * * * * * * * * */


/**************************/
// Illustration: 
// User input: Matthew
// Output: Enter a word: Matthew
//         You entered Matthew which is stored in user_word
//         That word was moved to moved_word and the value of moved_word is Matthew
/**************************/

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::strcpy;
using std::endl;
                             // First assembly test. In assembly, what's the difference between
                             // using endl and '\n'? If I use it once, how much longer is the 
                             // compiled program? If I use it twice, is there any difference?
                         

// StrCpy Function declaration.
void StrCpy(char * dest, char * src);



int main(){
    
    char user_word[10];   
                         // WOW. At first I forgot to specify the number of elements in the 
                         // to hold in the character vector! Epic fail.
                        
    char moved_word[10];

    cout << "Enter a word: ";
    cin >> user_word;

// DeleteString( user_word, start_pos, num_char);
StrCpy(moved_word, user_word);

    cout << "You entered " << user_word
         << " which is stored in user_word"
         << "\nThat word was moved to moved_word"
         << " and the value of moved_word is " << moved_word
         << '\n';

    // Recall that the array name is an address to the starting point to of the array.
    // So use of & isn't necessary when passing to the function.


return 0;
}

void StrCpy(char * dest, char * src){
    while(*dest++ = *src++);
}