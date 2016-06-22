/*
Owner: Ngo Duc Dung
Added: 17/06/2016
Last update: 17/06/2016
*/


#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

void sort_array(double* numbers, int start, int end);
void min_max(double* numbers, int nums);
void largest_frequent(double* number, int nums);
void print_array(double* numbers, int nums);


// main() is where program execution begins.

int main()
{
	int nums;		//number of numbers
	
	cout << "Please enter the number of numbers: ";
	cin >> nums;
	
	double* numbers = new double[nums];
	
	/* Input array of numbers */
	int i = 0;
	while(i < nums){
		cout << i+1 << " - ";
		cin >> numbers[i]; 
		i++;
	}
	
	sort_array(numbers,0,nums-1);
	
	min_max(numbers,nums);
	
	largest_frequent(numbers,nums);
	
	cout << "Sort ASC: ";
	print_array(numbers,nums);
	
	return 0;
}

/* Function: sort array using quick sort algorithm */
void sort_array(double* numbers, int start, int end){
	srand(time(NULL));								//initialize for parameters of rand()
	int key = start + rand() % (end - start + 1);
	
	int i = start;
	int j = end;
	
	while(i <= j){
		while(numbers[i] < numbers[key]) i++;		//find the left number >= numbers[key]
		while(numbers[j] > numbers[key]) j--;		//find the right number <= numbers[key]
		
		if(i <= j){
			int temp = numbers[i];
		    numbers[i] = numbers[j];
		    numbers[j] = temp;
					    
		    i++;
			j--;
		}
	}
	// Recursion
	if (start < j) sort_array(numbers, start, j);
	if (i < end) sort_array(numbers, i, end);
}

/* Function: finding the number has largest frequent exitence */
void largest_frequent(double* numbers, int nums){		
	int i = 0;
	int max_count = 0;
	int most_freq = 0;
	
	//find the number has most frequent existence
	while (i < nums){
		int a = numbers[i];
		int count = 1;
		
		int j = i+1;
		while(j < nums){
			if (a == numbers[j]){
				count++;
				j++;
			} else {
				break;
			}
		}
		
		if(max_count < count){
			max_count = count;
			most_freq = numbers[i];
		}
		
		i = j;
	}
	
	cout << "Most Freq: ";
	cout << most_freq;
	cout << " (" << max_count << "times)";
	cout << endl;
}

/* Function: finding max and min of the sequence of numbers */
void min_max(double* numbers, int nums){
	cout << "Min: " << numbers[0] << endl;
	cout << "Max: " << numbers[nums-1] << endl;
}

/* Function: output list of numbers */
void print_array(double* numbers, int nums){
	int i = 0;
	while(i < nums){
		cout << numbers[i] << " ";
		i++;	
	}
	cout << endl;
}



