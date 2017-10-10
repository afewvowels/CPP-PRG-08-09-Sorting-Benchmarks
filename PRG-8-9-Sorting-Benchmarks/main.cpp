//
//  main.cpp
//  PRG-8-9-Sorting-Benchmarks
//
//  Created by Keith Smith on 10/9/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that uses two identical arrays of at least 20 integers. It should call
//  a function that uses the bubble sort algorithm to sort one of the arrays in ascending
//  order. The function should keep a count of the number of exchanges it makes. The
//  program should then call a function that uses the selection sort algorithm to sort the
//  other array. It should also keep count of the number of exchanges it makes. Display
//  these values on the screen.

#include <iostream>
#include <random>

using namespace std;

int generateRandom();
void populateArray(int [], int []);

void sortBubble(int []);
void sortSelection(int []);

const int INT_ARRAY_SIZE = 200;
const int INT_RANDOM_MAX = 99999;
const int INT_RANDOM_MIN = -99999;

int main() {
    int intArrayBubble[INT_ARRAY_SIZE];
    int intArraySelection[INT_ARRAY_SIZE];
    
    populateArray(intArrayBubble, intArraySelection);
    
    sortBubble(intArrayBubble);
    sortSelection(intArraySelection);
    
    return 0;
}

int generateRandom()
{
    int intRandom;
    
    random_device rd;
    
    mt19937 engine(rd());
    
    uniform_int_distribution<> distribution (INT_RANDOM_MIN, INT_RANDOM_MAX);
    
    intRandom = distribution(engine);
    
//    Debug output result to console
//    cout << intRandom << endl;
    
    return intRandom;
}

void populateArray(int intArray1[], int intArray2[])
{
    int intRandom;
    
    for(int index = 0 ; index < INT_ARRAY_SIZE ; index++)
    {
        intRandom = generateRandom();
        intArray1[index] = intRandom;
        intArray2[index] = intRandom;
    }
}

void sortBubble(int intArray[])
{
    int intMax;
    int index;
    int intTemp;
    int intSwaps = 0;
    
    for(intMax = INT_ARRAY_SIZE - 1 ; intMax > 0 ; intMax--)
    {
        for(index = 0 ; index < intMax ; index++)
        {
            if(intArray[index] > intArray[index + 1])
            {
                intTemp = intArray[index];
                intArray[index] = intArray[index + 1];
                intArray[index + 1] = intTemp;
                intSwaps++;
            }
        }
    }
    cout << "Bubble sort took " << intSwaps << " swaps.\n";
}

void sortSelection(int intArray[])
{
    int intMinIndex;
    int intMinValue;
    int intTemp;
    int intSwaps = 0;
    
    for(int start = 0 ; start < (INT_ARRAY_SIZE - 1) ; start++)
    {
        intMinIndex = start;
        intMinValue = intArray[start];
        for(int index = start + 1 ; index < INT_ARRAY_SIZE ; index++)
        {
            if(intArray[index] < intMinValue)
            {
                intMinValue = intArray[index];
                intMinIndex = index;
                intSwaps++;
            }
        }
        intTemp = intArray[intMinIndex];
        intArray[intMinIndex] = intArray[start];
        intArray[start] = intTemp;
    }
    cout << "Selection sort took " << intSwaps << " swaps.\n";
}
