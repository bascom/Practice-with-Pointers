// Practice with Pointers_1_1 - 12-23-2019.cc
// Matthew C. Bascom
// Completed iteration at 00:56 (12:56AM) | Monday, December 23, 2019

// Reference: Chapter 12 - Albert and Breedlove - First Indian Edition 2010

// I want to start studying how changes to my code correspond to changes in assembly
// Referring to screenshot '2019-11-29 15-04-03.png',
// This shell command labels each block of assembly code with its corresponding line in c++:
// c++ -S -fverbose-asm file.cc -o out.s

// This is a working example of p.408 "Example" 12.7.1 "More pointer arithmetic."
// The code provided in the book is just the function declaration. I fill in the blanks...

// What a cool function! It simply asks how many characters are in the character 
// array entered by the user. Then it asks how long that array is (including all 
// characters plus the NULL, I believe.) Finally, It asks for a start index.
// The start index is very interesting, as everything after the start index is 
// deleted by the DeleteString function, as is apparent upon a cout of the modified
// user_word variable.

/**************************/
// Illustration: 
// User input: Matthew 8 2
// Output: Ma
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
                         

void DeleteString(char * str, int start, int num_char);

int main(){
    
    char user_word[10];   
                         // WOW. At first I forgot to specify the number of elements in the 
                         // to hold in the character vector! Epic fail.
                     
    int num_char;
    int start_pos;

    cout << "Enter a word: ";
    cin >> user_word;

    cout << "How many characters in this character string?";
    cin >> num_char;

    cout << '\n' << num_char << '\n';

    cout << '\n' << "Enter a start position: ";
    cin >> start_pos;

    cout << '\n' << start_pos << '\n';

DeleteString( user_word, start_pos, num_char);

cout << endl << user_word << endl;

return 0;
}

void DeleteString(char * str, int start, int num_char){
    strcpy( str + start, str + start + num_char);
}
