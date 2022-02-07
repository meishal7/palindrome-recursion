/*
main.cpp This program checks if given string is a palindrome recursively.
It takes user input as c-style string, converts it to std::string, deletes everything except digits and letters. Recursive function works with new string that has only alphanumeric characters. It compares first char and last char of a string. If they are equal, call recursion, but lower++ and upper--.

Author:     Elena Mudrakova
Module:     11
 
Algorithm:
1. Declare function is_palindrome() that returns boolean and accepts string that needs to be checked for palindrome, int lower index where to start checking, int upper where to stop checking.
2. if lower >= upper (means string has only one char) return true.
3. if(tolower(s[lower]) != tolower(s[upper])) return false.
4. Otherwise call recursion and pass lower+1, upper-1 for indexes.
 
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

// Prototype
bool is_palindrome(string s, int lower, int upper);

int main(){
  cout << "Enter strings. Enter 'Done' when finished" << endl;
  string input;
  
  while(input.compare("Done") != 0){
    // Take user input
    char str[30];
    cout << "\nEnter a string: ";
    cin.clear();
    cin.getline(str, 30);
       
    // string test = input ;
    // for_each(test.begin(), test.end(), [](char &c) { c = tolower(c) ; } ) ;
    // if (test == "quit") {
    //     cout << "Thanks for using our encryption service" << endl ;
    //     exit(0) ;
    // }

    string converted(str); // Convert c-str to std::string
    string new_str = "";   // String for storing only alphanumeric chars

    // Delete everything except digits and letters
    for(int i = 0; i < converted.size(); ++i){
        if(isalnum(converted[i])){
          new_str = new_str + converted[i]; 
        }
    }

    cout << converted << " is palindrome : " << is_palindrome(new_str, 0, new_str.size()-1);
    
   }

   return 0;
}


// Check if string is a palindrome recursively
bool is_palindrome(string s, int lower, int upper){
    if(lower >= upper) return true;
    if(tolower(s[lower]) != tolower(s[upper])) return false;
    is_palindrome(s, lower+1, upper-1);
    return true;
}