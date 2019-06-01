//Given a string, determine if it contains all unique characters

#include <iostream> 
#include <unordered_map>
#include <algorithm>

//This is a potential solution using a hash table. 
//The time complexity of this solutiion is O(n)
bool hasUniqueCharacters(std::string some_word)
{
    std::unordered_map<char, int> my_map;

    for(int i = 0; i < some_word.length(); i++)
    {
        my_map[some_word[i]]++;

        if(my_map[some_word[i]] > 1)
        {
            return false;
        }
    }

    return true;
}

//Find a solution where you do not use an additional data structure

//The following implementation uses a helper function called sortString
//First we sort the characters in the string and then loop through it
//Only looking at adjacent characters. The time complexity of this is O(nlogn).

void sortString(std::string &str) 
{ 
   std::sort(str.begin(), str.end()); 
} 

bool hasUniqueCharactersNoDataStructures(std::string some_word)
{
    int range_to_check = some_word.length()-1;

    sortString(some_word);

    for(int i = 0; i < range_to_check; i++)
    {
        if(some_word[i] == some_word[i+1])
        {
            return false;
        }
    }
    
    return true;
}


int main()
{
    std::string test = "a";

    //hasUniqueCharacters(test) ? std::cout << "Yes\n" : std::cout << "No\n";

    hasUniqueCharactersNoDataStructures(test) ? std::cout << "Yes\n" : std::cout << "No\n";

    return 0;
}