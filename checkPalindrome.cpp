/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Naveed
 *
 * Created on October 13, 2018, 4:55 PM
 */

#include <iostream>
using namespace std;

/*
 * 
 */
bool checkPalindrome(string userInputPhrase);

int main() 
{
    string phraseCheck = "";
    string test = "poop";
    
    cout << "Please enter a word and I will tell you if it is a palindrome: ";
    cin >> phraseCheck;
    
    if(test == phraseCheck)
    {
        cout << "YES";
    }
    
    bool palindromeCheck = checkPalindrome(phraseCheck);
    
    if(palindromeCheck == true)
    {
        cout << "This is a palindrome";
    }
    else
    {
        cout << "This is not a palindrome";
    }
   
}

bool checkPalindrome(string userInputPhrase)
{
    
    string checkPhrase = "";
    
    for(int i = userInputPhrase.length()-1; i >= 0; i--)
    {
        checkPhrase += userInputPhrase[i];
    }
    
    cout << checkPhrase << endl;
    cout << userInputPhrase << endl;
    
    if (checkPhrase == userInputPhrase)
    {
        return true;
    }
    else
    {
        return false;
    }
}

