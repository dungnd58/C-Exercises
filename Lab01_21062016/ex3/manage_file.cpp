/*
Owner: Ngo Duc Dung
Added: 21/06/2016
Last update: 21/06/2016
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#include "manage_file.h"

using namespace std;

/* Function: output the data to local storage
			all file storage are in ex3_input folder
 */
void saveToFile(Class* classes, int class_id){
	fstream file;
	
	int c = class_id - 1;
	
	//Each file save the data of each class.
	string fname = ".\\ex3_input\\" + classes[c].name + ".txt";
	file.open(fname.c_str(),ios::out);

	//Output the info of class
	file << classes[c].name << "\n";
	file << classes[c].year << "\n";
	file << classes[c].numbers << "\n";

	//Ouput the students' info of each class	
	int i = 0;

	while(i < classes[c].numbers){
		file << classes[c].students[i].name << ",";
		file << classes[c].students[i].age << ",";
		
		int j=0;
		while(j < 3){
			file << classes[c].students[i].subjects[j].name << ",";
			file << classes[c].students[i].subjects[j].test_mark1 << ",";
			file << classes[c].students[i].subjects[j].test_mark2 << ",";
			file << classes[c].students[i].subjects[j].exam_mark1 << ",";
			file << classes[c].students[i].subjects[j].exam_mark2;
			
			if(j != 2){ file << ","; }
			
			j++;
		}
		
		file << "\n";
		i++;
	}
	
	c++;
	
	file.close();	
}


/* Function: get data from file */
void getFromFile(Class* classes){
	fstream file;
	
	cout << "Loading data.." << endl;
	
	int c = 0;
	while(c < 5){
		cout << "..." << endl;
		
		string fname = ".\\ex3_input\\" + classes[c].name + ".txt";
		file.open(fname.c_str(),ios::in);
	
		if(file){
			//Get class's information
			file >> classes[c].name;
			file >> classes[c].year;
			file >> classes[c].numbers;
			
			//get students' information
			int i = 0;
			string info_line;
			
			while(i < classes[c].numbers){
				file >> info_line;
				
				//convert 'line' to it's floating-point value.
				stringstream linestream(info_line);
			
				getline(linestream,classes[c].students[i].name,',');
				
				string age = "";
				getline(linestream,age,',');
				classes[c].students[i].age = atoi(age.c_str());
				
				int j=0;
				string mark="";
				
				classes[c].students[i].subjects = new Subject[3];
			
				while(j < 3){	
					getline(linestream,classes[c].students[i].subjects[j].name,',');
	
					getline(linestream,mark,',');
					classes[c].students[i].subjects[j].test_mark1 = strtod(mark.c_str(),NULL);
					
					getline(linestream,mark,',');
					classes[c].students[i].subjects[j].test_mark2 = strtod(mark.c_str(),NULL);
					
					getline(linestream,mark,',');
					classes[c].students[i].subjects[j].exam_mark1 = strtod(mark.c_str(),NULL);
					
					getline(linestream,mark,',');
					classes[c].students[i].subjects[j].exam_mark2 = strtod(mark.c_str(),NULL);
					
					j++;
				}
				
				i++;
			}
		}
		
		file.close();
		c++;
	}
	cout << "Loading Completed." << endl;
}
