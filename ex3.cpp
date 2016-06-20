/*
Owner: Ngo Duc Dung
Added: 16/06/2016
Last update: 16/06/2016
*/


#include <iostream>
#include <cstdlib>

using namespace std;

// main() is where program execution begins.

struct Intership
{
	char name[30];
	char birthday[8];
	int win_mark;
	int word_mark;
	int jira_mark;
	int sum;
	string rank;
};
typedef struct Intership Intership;

void inputAllIntership(Intership* students, int num);
void printMainInfo(Intership* students, int num);
void printAll(Intership* students, int num);
void sumScore(Intership* student, int num);
void rateRank(Intership* students, int num);

int main()
{
	int num = 0;					//number of intership
	
	Intership* students;
	
	int choice;
	
	while(choice != 4){
		cout <<"----------------------------------------------" << endl;
		cout <<"1. Enter all student and their marks " << endl;
		cout <<"2. Process the data. " << endl;
		cout <<"3. List all students. " << endl;
		cout <<"4. Exit.  " << endl;
		cout <<"Enter your choice: ";
		cin >> choice;
		cout << endl;
		

		// Start to execute user choice
		switch(choice){
			case 1:
			{
				cout <<" Please enter number of students: ";
				cin >> num;
				
				students = new Intership[num];		//array of interships
				
				inputAllIntership(students,num);
				
				printMainInfo(students,num);
				
				break;
			}
			case 2:
			{
				if(students){
					if(num > 0){
						sumScore(students,num);
				
						rateRank(students,num);
					
						printAll(students,num);
						
						cout <<"Done";
					} else {
						cout <<"Empty list of students"<<endl;
					}
				}
				break;
			}
			case 3:
			{
				if(students){
					if(num > 0){	
						printAll(students,num);
					} else {
						cout <<"Empty list of students"<<endl;
					}
				}
				break;
			}
			case 4:
			{
				break;
			}
			default:
			{
				cout << "Invalid choice. Please choose again." <<endl;
			}
		} //End execute choice
	}
	
	return 0;
}

/*
Function: input all intership information
*/
void inputAllIntership(Intership* students, int num){
	int i = 0;
	while(i < num){
		cout << "Student ID: " << i + 1 << endl;
		
		cout <<"Name: ";
		cin >> students[i].name;
		
		cout <<"Birthday: ";
		cin >> students[i].birthday;
		
		cout <<"Win-mark: ";
		cin >> students[i].win_mark;
		
		cout <<"Word-mark: ";
		cin >> students[i].word_mark;
		
		cout <<"Jira-mark: ";
		cin >> students[i].jira_mark;
		
		students[i].sum = 0;
		students[i].rank = "";
		
		cout << endl;
		
		i++;
	}
}

/*
Function: print intership information, except marks and rank
*/
void printMainInfo(Intership* students, int num){
	cout <<" List of intership: " << endl;
	cout <<"STT" << "    ";
	cout <<"Name" << "    ";
	cout <<"Birthday" << "    ";
	cout << endl;
	
	int j=0;
	while(j < num){
		cout << j + 1 << "    ";
		
		cout << students[j].name << "    ";
		
		cout << students[j].birthday << "    ";
		
		cout << endl;
		
		j++;
	}
}

/*
Function: print all intership information
*/
void printAll(Intership* students, int num){
	cout <<" List of intership: " << endl;
	cout <<"STT" << "    ";
	cout <<"Name" << "    ";
	cout <<"Birthday" << "    ";
	cout <<"Sum" << "    ";
	cout <<"Rank" << "    ";
	cout << endl;
	
	int j=0;
	while(j < num){
		cout << j + 1 << "    ";
		
		cout << students[j].name << "    ";
		
		cout << students[j].birthday << "    ";	

		cout << students[j].sum << "    ";	
		
		cout << students[j].rank << "    ";
		
		cout << endl;
		
		j++;
	}
}

/*
Function: caculate sum of marks
*/
void sumScore(Intership* students, int num){
	int j=0;
	while(j < num){
		students[j].sum += students[j].win_mark;
		students[j].sum += students[j].jira_mark;
		students[j].sum += students[j].word_mark;
		j++;
	}
}

/*
Function: rate rank of intership based on sum of marks
*/

void rateRank(Intership* students, int num){
	int j=0;
	while(j < num){
		if(students[j].sum >= 24){
			students[j].rank = "Exelence";
		} else if(students[j].sum < 24 && students[j].sum >= 18){
			students[j].rank = "Good";
		} else {
			students[j].rank = "Average";
		}
		
		j++;	
	}
}



