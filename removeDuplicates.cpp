/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Naveed
 *
 * Created on October 13, 2018, 11:46 AM
 */

#include <iostream>
using namespace std;

/*
 * 
 */
int main() 
{
    int a[7] = {2,3,4,5,6,7,3};
    
    int size = sizeof(a)/sizeof(a[0]);
    
    int n = size;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(a[i] == a[j])
            {
                for(int k = j; k < size-1; k++)
                {
                    a[k] = a[k+1];
                }
                size--;
                j--;
                
            }
        }
    }
    
    
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    
}

