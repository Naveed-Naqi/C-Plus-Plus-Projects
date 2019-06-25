#include <iostream>
#include <unordered_map>

//Write a function that returns true, 
//if any permutation of the given word is a palindrome

bool isPalindromeOfPermutation(std::string some_word);
bool isOdd(int number);

bool isPalindromeOfPermutation(std::string some_word)
{
    std::unordered_map<char, int> freq_map;

    for(int i = 0; i < some_word.length(); i++)
    {
        freq_map[some_word[i]]++;
    }

    int odd_counter = 0;

    for(int i = 0; i < some_word.length(); i++)
    {
        if(isOdd(freq_map[some_word[i]]))
        {
            odd_counter++;

            if(odd_counter > 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool isOdd(int number)
{
    return number % 2 == 1;
}

int main()
{

    std::string test = "recacra";

    isPalindromeOfPermutation(test) ? std::cout << "Yes" : std::cout << "No";

    return 0;
}