#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <functional>

#define print(x) std::cout << x << std::endl
//Is string a, a permutation of string b?

//This implementation uses two hash tables and has time complexity O(n)
//The space complexity isn't the greatest
bool isPermutation(std::string some_word, std::string other_word)
{
    if (some_word.length() != other_word.length())
    {
        return false;
    }

    std::unordered_map <char, int> some_word_map;
    std::unordered_map <char, int> other_word_map;

    for(int i = 0; i < some_word.length(); i++)
    {
        some_word_map[some_word[i]]++;
        other_word_map[other_word[i]]++;
    }

    for(int i = 0; i < some_word.length(); i++)
    {
        if(some_word_map[some_word[i]] != other_word_map[some_word[i]])
        {
            return false;
        }
    }

    return true;
}

//The following implementation uses a helper function called sortString
//The time complexity of this is O(NlogN), but we use no other data structures so 
//Space complexity is better
void sortString(std::string &str) 
{ 
   std::sort(str.begin(), str.end()); 
} 

bool isPermutationNoDataStructures(std::string some_word, std::string other_word)
{

    if (some_word.length() != other_word.length())
    {
        return false;
    }

    sortString(some_word);
    sortString(other_word);

    for(int i = 0; i < some_word.length(); i++)
    {
        if(some_word[i] != other_word[i])
        {
            return false;
        }
    }

    return true;
}



int main()
{

    std::string a = "lmnop";
    std::string b = "pnoml";

    isPermutation(a, b) ? print("yes") : print("no");
    isPermutationNoDataStructures(a, b) ? print("yes") : print("no");

    return 0;
}