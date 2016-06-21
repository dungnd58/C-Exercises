/*
Owner: Ngo Duc Dung
Added: 21/06/2016
Last update: 21/06/2016
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "manage_file.h"

using namespace std;

/* Function: output the data to local storage
			all file storage are in ex3_input folder
 */
void saveToFile(Class* classes, int class_id){
	fstream f;
	
	int c = class_id - 1;
	
	//Each file save the data of each class.
	string fname = ".\\ex3_input\\" + classes[c].name + ".txt";
	f.open(fname.c_str(),ios::out);

	//Output the info of class
	f << classes[c].name << "\n";
	f << classes[c].year << "\n";
	f << classes[c].numbers << "\n";

	//Ouput the students' info of each class	
	int i = 0;

	while(i < classes[c].numbers){
		f << classes[c].students[i].name << ",";
		f << classes[c].students[i].age << ",";
		
		int j=0;
		while(j < 3){
			f << classes[c].students[i].subjects[j].name << ",";
			f << classes[c].students[i].subjects[j].test_mark1 << ",";
			f << classes[c].students[i].subjects[j].test_mark2 << ",";
			f << classes[c].students[i].subjects[j].exam_mark1 << ",";
			f << classes[c].students[i].subjects[j].exam_mark2;
			
			if(j != 2){ f << ","; }
			
			j++;
		}
		
		f << "\n";
		i++;
	}
	
	c++;
	
	f.close();	
}


/* Function: get data from file
void getFromFile(Class* classes){
	fstream f;
	
	int c = 0;
	while(c < 5){
		string fname = classes[c].name + ".txt";
		f.open(fname,ios::in);
	
		f >> classes[c].name;
		f >> classes[c].year;
		f >> classes[c].numbers;
		
		classes[c].students = new Student[classes[c].numbers];
		
		int i = 0;
		string line;
		
		while(getline(f,line)){
			istringstream linestream(line);
			
			getline(f,classes[c].students[i].name,',');
			getline(f,classes[c].students[i].age,',');
			
			int j=0;
			while(j < 3){
				getline(f,classes[c].students[i].subjects[j].name,',');
				getline(f,classes[c].students[i].subjects[j].test_mark1,',');
				getline(f,classes[c].students[i].subjects[j].test_mark2,',');
				getline(f,classes[c].students[i].subjects[j].exam_mark1,',');
				getline(f,classes[c].students[i].subjects[j].exam_mark2,',');
				j++;
			}
		}
		
		f.close();
	}
}*/
