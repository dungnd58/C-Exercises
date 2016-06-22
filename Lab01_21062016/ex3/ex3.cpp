/*
Owner: Ngo Duc Dung
Added: 17/06/2016
Last update: 17/06/2016
*/


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>

#include "structs.h"
#include "manage_file.h"
#include "manage_data.h"

using namespace std;

/* Functions */
void printClassList(Class* classes, int& class_choice);

// main() is where program execution begins.
int main()
{
	//initialize the array of classes
	Class classes[5] = {
		{"12A","2013-2016",0, new Student[10]},
		{"12B","2013-2016",0, new Student[10]},
		{"12C","2013-2016",0, new Student[10]},
		{"12D","2013-2016",0, new Student[10]},
		{"12E","2013-2016",0, new Student[10]},
	};
	
	//get information of all Class
	getFromFile(classes);
	
	int choice = 0;
	while(choice != 4){
		cout <<"----------------------------------------------" << endl;
		cout <<"1. Enter students' infomation. " << endl;
		cout <<"2. Search a student's formation by ID'. " << endl;
		cout <<"3. Show results of 1 class. " << endl;
		cout <<"4. Exit.  " << endl;
		cout <<"Enter your choice: ";
		cin >> choice;
		cout << endl;
		
		int class_choice;
		
		// Start to execute user choice
		switch(choice){
			case 1:
			{
				printClassList(classes, class_choice);
				
				enterStudentInfo(classes,class_choice);
				break;
			}
			case 2:
			{
				int id;
				
				printClassList(classes, class_choice);
				
				cout << "Enter the student ID: ";
				cin >> id;
				 
				searchStudents(classes,class_choice,id);
				break;
			}
			case 3:
			{
				printClassList(classes, class_choice);
				
				printClassResults(classes,class_choice);
				break;
			}
			case 4:
			{
				break;
			}
			default:
			{
				cout << "Invalid choice. Please choice again!" <<endl;
			}
		}
	}
	
	return 0;
}

/* Function: output the list of classes name */
void printClassList(Class* classes, int& class_choice){
	cout << "Classes: " << endl;
	int c = 0;
	while(c < 5){
		cout << c+1 << ". "<< classes[c].name << endl;
		c++;
	}
	
	cout << "Please choose the number of one of these classes: ";
	cin >> class_choice;
}
