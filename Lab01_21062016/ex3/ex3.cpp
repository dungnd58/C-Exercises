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

using namespace std;

//Subject infomation
struct Subject {
	string name;
	double test_mark1;
	double test_mark2;
	double exam_mark1;
	double exam_mark2;
	double sum_mark;
};
typedef struct Subject Subject;

//Student infomation
struct Student {
	string id;
	string name;
	int age;
	Subject* subjects;
};
typedef struct Student Student;

//Class infomation
struct Class {
	string name;
	string year;
	int numbers;
	Student* students;
};
typedef struct Class Class;

/* Functions */
void saveToFile(Class* classes, int class_id);
void getFromFile(Class* classes);
void enterStudentInfo(Class* classes, int class_id);
void searchStudents(Class* classes, int class_id, int id, string name);
void printAStudentResult(Student* students, int id);
void printClassResults(Class* classes, int class_id);
void printClassList(Class* classes, int& class_choice);

inline bool checkStringCompare(char a, char b);

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
	//getFromFile(classes);
	
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
				 
				searchStudents(classes,class_choice,id,"");
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

/* Function: output the data to local storage */
void saveToFile(Class* classes, int class_id){
	fstream f;
	
	int c = class_id - 1;
	
	string fname = ".\\ex3_input\\" + classes[c].name + ".txt";
	f.open(fname.c_str(),ios::out);

	f << classes[c].name << "\n";
	f << classes[c].year << "\n";
	f << classes[c].numbers << "\n";
	
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

/* Function: input all students' information and marks */
void enterStudentInfo(Class* classes, int class_id){
	int n;
	int i,j;
	cout << "Enter number of students: ";
	cin >> n;
	
	int numbers = classes[class_id-1].numbers;		//get the number of students in class
	i = numbers; 									//continue to add students
	
	while(i < numbers + n){
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
			
			classes[class_id-1].students[i].subjects[j].sum_mark = sum;
			
			j++;
		}
		
		i++;		
	}
	
	cout << "Saving to local storage..." << endl;
	saveToFile(classes,class_id);
	cout << "Done" << endl;
	cout << endl;
}


/* Function: check each character of student name */
bool checkStringCompare(char a, char b){
	return (tolower(a) == tolower(b));	
}

/* Function: output results of some students */
void searchStudents(Class* classes, int class_id, int id, string name){
	//Search by ID
	if(id != -1 && name == ""){
		printAStudentResult(classes[class_id-1].students,id);
	}
	
	//Search by Name
	/*
	else if(id == -1 && name != ""){
		int i = 0;
		while(i < classes[class_id-1].numbers){
			string stn = classes[class_id-1].name;
			
			if(stn.size() == name.size() 
					&& equal(stn.begin(), stn.end(), name.begin(), checkStringCompare)){
				printAStudentResult(classes[class_id-1].students,i);
			}
			
			i++;
		}
	}*/
	
	else {
		cout << "The student is not in the list." << endl;
	}
}


/* Function: output a student's result */
void printAStudentResult(Student* students, int id){
	// Start to output
	int j;
	
	cout << "Student ID: " << id << endl;

	cout << "	Name: " << students[id-1].name << endl;
	
	cout << "	Age: " << students[id-1].age << endl;
	
	// Enter marks
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
