#include <iostream>

void sieveOfEratosthenes(int n)
{
    int* arr = new int[n];
 
    for (int i = 2; i < n; i++)
    {
        for (int j = i * i; j < n; j+=i)
        {
            arr[j - 1] = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == 0)
        {
            std::cout << i << "\n";
        }
            
    }
}

int main()
{
    sieveOfEratosthenes(200);
}