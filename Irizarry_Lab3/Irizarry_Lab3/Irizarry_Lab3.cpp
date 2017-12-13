// Alex Irizarry Lab 3
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void reset(const int num[], const int * ptr[], int size);
void displayIntArray(const int num[], int size);
void displayPtrArray(const int * ptr[], int size);
void displayPtrArrayDeref(const int * ptr[], int size);
void BubbleSort(const int *ptr[], int size);
void SelectionSort(const int *ptr[], int size);
void InsertionSort(const int *ptr[], int size);

void reset(const int num[], const int * ptr[], int size)
{
	int i = 0;
	
	for (i = 0; i < size; i++)
	{
		ptr[i] = &num[i];
	}
}

void displayIntArray(const int num[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		cout << num[i] << endl;
	}
}

void displayPtrArray(const int * ptr[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		cout << setw(10) << *ptr[i] << setw(10);
	}
	cout << endl;
}

void displayPtrArrayDeref(const int * ptr[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		cout << setw(10) << *ptr[i] << setw(10);
	}
	cout << endl;
}

void BubbleSort(const int *ptr[], int size)
{
	bool swap;
	const int * temp;
	do
    {
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{	
			if (*ptr[count] > *ptr[count + 1])
			{ 
				temp = ptr[count];
				ptr[count] = ptr[count + 1];
				ptr[count + 1] = temp;  
				swap = true; 
				displayPtrArrayDeref(ptr, size);
			} 
			
		} 
		
	} while (swap);
	
}

void SelectionSort(const int *ptr[], int size)
{
	int startScan, minIndex;
	const int * minValue;

	for (startScan = 0; startScan <(size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = ptr[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (*ptr[index] < *minValue)
			{
				minValue = ptr[index];
				minIndex = index;
			}
		}
		ptr[minIndex] = ptr[startScan];
		ptr[startScan] = minValue;
		displayPtrArrayDeref(ptr, size);

	}
}

void InsertionSort(const int *ptr[], int size)
{

	for (int i = 1; i < size; i++)
	{ 
		int j;
		const int * current = ptr[i];

		for (j = i - 1; j >= 0 && *ptr[j]> *current; j--)
		{
			ptr[j + 1] = ptr[j];
			displayPtrArrayDeref(ptr, size);
		}     

		ptr[j + 1] = current;
		displayPtrArrayDeref(ptr, size);
	}
}

int main()
{

	const int SIZE = 4;
	const int numbers[SIZE] = { 20, 40, 10, 30 };
	const int * ptr[SIZE];

	cout << "Lab 3" << endl;

	for (int i = 0; i < 3; i++)
	{
		reset(numbers, ptr, SIZE);
		cout << "\nThe original array has been reset to: \n";
		displayPtrArrayDeref(ptr, SIZE);
		switch (i)
		{

		case 0:
			cout << "\nSORTING -  Bubble Sort Accending - O(n2) algorithm\n";
			BubbleSort(ptr, SIZE);
			break;
		case 1:
			cout << "\nSORTING -  Selection Sort Accending - O(n2) algorithm\n";
			SelectionSort(ptr, SIZE);
			break;
		case 2:
			cout << "\nSORTING -  Insertion Sort Accending - O(n2) algorithm\n";
			InsertionSort(ptr, SIZE);
			break;

		}

		
	}
	cout << "\nDONE - Alex Irizarry\n";
	
	system("pause");
	return 0;
}
