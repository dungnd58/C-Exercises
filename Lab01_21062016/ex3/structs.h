/*
Owner: Ngo Duc Dung
Added: 21/06/2016
Last update: 21/06/2016
*/

#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <string>

//Subject infomation
struct Subject {
	std::string name;
	double test_mark1;
	double test_mark2;
	double exam_mark1;
	double exam_mark2;
	double sum_mark;
};
typedef struct Subject Subject;


//Student infomation
struct Student {
	std::string id;
	std::string name;
	int age;
	Subject* subjects;
};
typedef struct Student Student;


//Class infomation
struct Class {
	std::string name;
	std::string year;
	int numbers;
	Student* students;
};
typedef struct Class Class;

#endif
