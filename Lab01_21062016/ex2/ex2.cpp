/*
Owner: Ngo Duc Dung
Added: 17/06/2016
Last update: 21/06/2016
*/


#include <iostream>

#include "manage_file.h"

using namespace std;

// main() is where program execution begins.

void printNums(double* nums);
double sumNums(double* nums);

int main()
{
	double real_nums[10];		//array of real numbers
	double sum;					//sum of square of each number
	
	FileManager file_mn;
	
	cout << "Enter 10 real numbers: " << endl;
	
	int i = 0;
	while(i < 10){
		cout << i+1 << " >> ";
		cin >> real_nums[i];
		cout << "\n";
		i++;
	}
	
	file_mn.writeToFile(real_nums);
	cout << "Writing completed." << endl << endl;
	
	file_mn.readFromFile(real_nums);
	cout << "Reading completed." << endl << endl;
	
	cout << "Input: ";
	printNums(real_nums);
	cout << endl << endl;
	
	cout << "Sum of square of each number: ";
	sum = sumNums(real_nums);
	cout << sum << endl << endl;
	
	return 0;
}

void printNums(double* nums){
	int i = 0;
	while(i < 10){
		cout << nums[i] << " ";
		i++;
	}
}

/* Function: caculate sum of square of a number */
double sumNums(double* nums){
	double sum = 0;
	
	int i = 0;
	while(i < 10){
		sum += nums[i]*nums[i];
		i++;
	}
	
	return sum;
}

