/**
 * @file Problem1.cpp
 * @author Mostafa Besar (moustafabessar99@gmail.com)
 * @brief This program find two distinct numbers which thier summation is equal to user input (target)
 *        Complexity = O(n*logn) + O(n) =  O(n*logn)
 * @date 2021-01-17
 * *******************************************
 * Example of how to enter the inputs
 * 
 *Input:5
 *      2 1 3 7 3
 *      6
 *Output:2 4
 **********************************************
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Binary Search Algorithm for finding index second number in the array with O(logn) complexity
 * 
 * @param sortedNums 
 * @param firstNumber 
 * @param secondNumber 
 * @return unsigned int 
 */
unsigned int binarySearch(vector<int> &sortedNums, int firstNumber, int secondNumber)
{
    
    int end = sortedNums.size();
    int mid = sortedNums.size()/2;
    if((secondNumber == sortedNums[mid]) && (firstNumber != secondNumber))
        return 1;

    else if(secondNumber > sortedNums[mid])
    {
        for (int i = mid+1; i < end; i++)
        {
            if((secondNumber == sortedNums[i]) && (firstNumber != secondNumber))
                return 1;  
        }
        return 0;
    }
    else if(secondNumber < sortedNums[mid])
    {
        for (int i = 0; i < mid; i++)
        {
            if((secondNumber == sortedNums[i]) && (firstNumber != secondNumber))
                return 1;
        }
        return 0;
    }
    else
        return 0;  
}

int main(void)
{
    int target;
    int n;

    //cout << "Enter length of the array: "<<"\n";
    cin >> n;
    vector<int> nums(n);
    vector<int> sortedNums;
    //cout << "Enter elements: "<<"\n";
    for (int i = 0; i < n; i++)     
    {
        cin >> nums[i];
        sortedNums.push_back(nums[i]);
    }  
    // sorting array to make binary search
    sort(sortedNums.begin(), sortedNums.end());
    
    //cout << "Enter Target number!: "<< "\n";
    cin >> target;

    int output[2], secondNumber = 0;
    //for each element search for it's second number using binary search
    for (int j = 0; j < n; j++)     // O(n)
    {
        secondNumber = target-nums[j];              // second number = target - first number
        if(binarySearch(sortedNums, nums[j], secondNumber))         // O(logn)
        {
            //storing first number index
            output[0] = j;
            break;
        }
        output[0] = j;
    }

    //get index of second number and store it
    for (int i = 0; i < n; i++) {           //O(n)
		if (nums[i] == secondNumber)
		{
            output[1] = i;
            break;
		}
        output[1] = i;
    }
    cout << output[0] << " " << output[1];
    return 0;
}