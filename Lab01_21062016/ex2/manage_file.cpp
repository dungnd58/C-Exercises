/*
Owner: Ngo Duc Dung
Added: 21/06/2016
Last update: 21/06/2016
*/

#include <iostream>
#include <fstream>

#include "manage_file.h"

using namespace std;

FileManager::FileManager()
{
}

/* Function: write 10 real numbers to input.txt */
void FileManager::writeToFile(double* nums){
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
void FileManager::readFromFile(double* nums){
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
