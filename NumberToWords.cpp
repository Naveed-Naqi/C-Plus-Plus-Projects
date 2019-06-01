#include <iostream>
#include <cmath>
#define print(x) std::cout << x << std::endl

//Given an integer from 1 to 2 billion, convert it to words
std::string convertToWords(int given_num);
int getNumberOfDigits(int given_num);
bool isDivisibleByTen(int given_num);
std::string convert(int given_num, int place_val);

int main()
{   
    print(convertToWords(37));

    return 0;
}

bool isDivisibleByTen(int given_num)
{
    return given_num % 10 == 0;
}

int getNumberOfDigits(int given_num)
{
    int counter = 0;

    if(given_num == 0) {return 1;}

    while(given_num != 0)
    {
        given_num = given_num / 10;
        counter++;
    }

    return counter;
}

std::string convertToWords(int given_num)
{
    std::string word = "";

    std::string lessThanTwenty[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                                     "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",  
                                    "seventeen", "eighteen", "nineteen"};

    std::string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", 
                            "sixty", "seventy", "eighty", "ninety"};
    
    std::string suffixes[10] ={ "", "hundred", "thousand", "million", "billion"};

    if(given_num < 20) 
    {
        return lessThanTwenty[given_num];
    }
    else if (given_num < 100 && isDivisibleByTen(given_num)) 
    {
        return tens[given_num/10];
    }

    else
    { // 127

        int num_of_digits = getNumberOfDigits(given_num);
        int place_val = num_of_digits - 1;

        while (place_val != 0)
        {   
            std::string suffix = suffixes[place_val];
            std::string temp = "";
            int index = given_num / pow(10, place_val-1);
            print(index);

            if(index < 20)
            {
                word += lessThanTwenty[index]; 
            }
            else if (index < 100 && isDivisibleByTen(given_num)) 
            {
                word += tens[index];
            }
            else if (index < 100)
            {

            }

            word += suffix;
 
            place_val--;
        }
    }
    return word;
}