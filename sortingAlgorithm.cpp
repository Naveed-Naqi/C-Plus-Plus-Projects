/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Naveed
 *
 * Created on October 13, 2018, 10:30 AM
 */

#include <iostream>
using namespace std;

/*
 * 
 */

int sortingAlgorithm(int a[], int size);

int main() 
{
    int temp = 0;
    int first = 0;
    
    int a[5] = {3,2,7,1,4};
    
    int size = sizeof(a)/sizeof(a[0]);
    
    for(int i = 0; i < size-1; i++)
    {
        first = i;
        
        for(int j = i+1; j < size; j++)
        {
            
            if(a[j] < a[first])
            {
                first = j;
            }   
        }
        
        if(a[first] < a[i])
        {
            temp = a[i];
            a[i] = a[first];
            a[first] = temp;  
        }    
        
        
    }
    
    for(int i = 0; i < size; i++)
    {
        cout << a[i];
    }
}

