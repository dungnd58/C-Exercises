/*
Owner: Ngo Duc Dung
Added: 21/06/2016
Last update: 21/06/2016
*/

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>

#include "manage_data.h"
#include "manage_file.h"

using namespace std;


/* Function: input all students' information and marks */
void enterStudentInfo(Class* classes, int class_id){
	int nums;
	int i,j;
	cout << "Enter number of students: ";
	cin >> nums;
	
	int numbers = classes[class_id-1].numbers;		//get the number of students in class
	i = numbers; 									//continue to add students
	
	while(i < numbers + nums){
		//Increase number of students in Class
		classes[class_id-1].numbers++;
		
		// Enter information
		cout << "Student ID: " << i + 1 << endl;
		
		//initialize new object
		//students[i] = new Student();
		
		cout << "	Name: ";
		cin >> classes[class_id-1].students[i].name;
		
		cout << "	Age: ";
		cin >> classes[class_id-1].students[i].age;
		cout << endl;
		
		// Enter marks
		
		classes[class_id-1].students[i].subjects = new Subject[3];
		cout << "Subject's marks: " << endl;
		j = 0;
		while(j < 3){
			int sum = 0;
			
			cout << "	Subject: ";
			cin >> classes[class_id-1].students[i].subjects[j].name;
			
			cout << "		Test mark 1: ";
			cin >> classes[class_id-1].students[i].subjects[j].test_mark1;
			sum += classes[class_id-1].students[i].subjects[j].test_mark1;
			
			cout << "		Test mark 2: ";
			cin >> classes[class_id-1].students[i].subjects[j].test_mark2;
			sum += classes[class_id-1].students[i].subjects[j].test_mark2;
			
			cout << "		Exam mark 1: ";
			cin >> classes[class_id-1].students[i].subjects[j].exam_mark1;
			sum += classes[class_id-1].students[i].subjects[j].exam_mark1;
			
			cout << "		Exam mark 2: ";
			cin >> classes[class_id-1].students[i].subjects[j].exam_mark2;
			sum += classes[class_id-1].students[i].subjects[j].exam_mark2;
			
			cout << endl;
			
			//caculate sum of marks of each subject
			classes[class_id-1].students[i].subjects[j].sum_mark = sum;
			
			j++;
		}
		
		i++;		
	}
	
	//Write data to file
	cout << "Saving to local storage..." << endl;
	saveToFile(classes,class_id);
	cout << "Done" << endl;
	cout << endl;
}

/* Function: output results of some students */
void searchStudents(Class* classes, int class_id, int student_id){
	//Search by ID
	if(student_id < classes[class_id-1].numbers){
		printAStudentResult(classes[class_id-1].students, student_id);
	}
	else {
		cout << "The student is not in the list." << endl;
	}
}


/* Function: output a student's result */
void printAStudentResult(Student* students, int student_id){
	int id = student_id;
	
	// Start to output
	int j;
	
	cout << "Student ID: " << id << endl;

	cout << "	Name: " << students[id-1].name << endl;
	
	cout << "	Age: " << students[id-1].age << endl;
	
	//Output marks
	cout << "Subject's marks: " << endl;
	j = 0;
	while(j < 3){
		students[id-1].subjects[j].sum_mark = 0;
		
		cout << "	Subject: " << students[id-1].subjects[j].name << endl;
		
		cout << "		Test mark 1: " << students[id-1].subjects[j].test_mark1;
		cout << endl;
		students[id-1].subjects[j].sum_mark += students[id-1].subjects[j].test_mark1;
		
		cout << "		Test mark 2: " << students[id-1].subjects[j].test_mark2;
		cout << endl;
		students[id-1].subjects[j].sum_mark += students[id-1].subjects[j].test_mark2;
		
		cout << "		Exam mark 1: " << students[id-1].subjects[j].exam_mark1;
		cout << endl;
		students[id-1].subjects[j].sum_mark += students[id-1].subjects[j].exam_mark1;
		
		cout << "		Exam mark 2: " << students[id-1].subjects[j].exam_mark2;
		cout << endl;
		students[id-1].subjects[j].sum_mark += students[id-1].subjects[j].exam_mark2;
		
		cout << "		Sum of marks: " << students[id-1].subjects[j].sum_mark;
		cout << endl;
		
		j++;
	}
}

/* Function: output a class's results */
void printClassResults(Class* classes, int class_id){
	if(classes[class_id-1].numbers <= 0){
		cout <<	"This class has NO student." << endl;
		cout << endl;
	} else {
		int i = 0;
		
		while(i < classes[class_id-1].numbers){
			printAStudentResult(classes[class_id-1].students,i+1);
			i++;
		}
	}
}
