/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	if (arr == NULL&&len<0)
		return NULL;
	int *resultArr, i = 0, j = 0, k, diff, ratio;
	resultArr = (int*)malloc(sizeof(int) * 6);
	for (i = 0; i < 6; i++)
		resultArr[i] = 0;
	i = 0;
	diff = arr[1] - arr[0];
	ratio = arr[1] / arr[0];
	if ((arr[i + 1] - arr[i] == diff) && (arr[i + 2] - arr[i + 1] == diff))
	{
		resultArr[0] = i;
		while (arr[i + 1] - arr[i] == diff)
		{
			i++;
		}
		resultArr[1] = i;
		j = i + 1;
	}
	else if ((arr[i + 1] / arr[i] == ratio) && (arr[i + 2] / arr[i + 1] == ratio))
	{
		resultArr[4] = i;
		while (arr[i + 1] / arr[i] == ratio)
		{
			i++;
		}
		resultArr[5] = i;
		j = i;
	}
	j = i + 1;
	diff = arr[j + 1] - arr[j];
	ratio = arr[j + 1] / arr[j];
	if ((arr[j + 1] - arr[j] == diff) && (arr[j + 2] - arr[j + 1] == diff))
	{
		if (resultArr[0] != 0)
			resultArr[0] = j;
		else
			resultArr[2] = j;
		while (arr[j + 1] - arr[j] == diff)
		{
			j++;
		}
		if (resultArr[0] != 0)
			resultArr[1] = j;
		else
			resultArr[3] = j;

	}
	k = j + 1;
	ratio = arr[k + 1] / arr[k];
	if (arr[k] / arr[k - 1] == ratio)
	{
		k = k - 1;
	}
	resultArr[4] = k;
	while (arr[k + 1] / arr[k] == ratio)
		k++;
	resultArr[5] = k;
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	return resultArr;
}
