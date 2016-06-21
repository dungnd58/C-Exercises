/*
Owner: Ngo Duc Dung
Added: 17/06/2016
Last update: 17/06/2016
*/


#include <iostream>
#include <fstream>

using namespace std;

// main() is where program execution begins.

void writeToFile(double* nums);
void readFromFile(double* nums);
void printNums(double* nums);
double sumNums(double* nums);

int main()
{
	double real_nums[10];		//array of real numbers
	double sum;					//sum of square of each number
	
	cout << "Enter 10 real numbers: " << endl;
	
	int i = 0;
	while(i < 10){
		cout << i+1 << " >> ";
		cin >> real_nums[i];
		cout << "\n";
		i++;
	}
	
	writeToFile(real_nums);
	cout << "Writing completed." << endl << endl;
	
	readFromFile(real_nums);
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

/* Function: write 10 real numbers to input.txt */

void writeToFile(double* nums){
	fstream file;	//object used to manage files
	
	cout << "Opening file...\n";
	file.open("ex2_input.txt", ios::out | ios::trunc);
	cout << "Now writing data to input.txt \n";
	
	int i = 0;
	while(i < 10){
		file << nums[i] <<"\n";
		i++;
	}
	
	cout << "Now closing input.txt \n";
	file.close();
}

/* Function: read 10 real numbers from input.txt */

void readFromFile(double* nums){
	fstream file;	//object used to manage files
	
	cout << "Opening file...\n";
	file.open("ex2_input.txt", ios::in);
	cout << "Now reading data from input.txt \n";
	
	int i = 0;
	while(!file.eof()){
		file >> nums[i];
		i++;
	}
	
	cout << "Now closing input.txt \n";
	file.close();
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

