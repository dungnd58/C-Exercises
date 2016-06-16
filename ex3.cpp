#include <iostream>

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
	char rank[20];
};
typedef struct Intership Intership;

int inputInfo(Intership* student, int num);
int printOutput(Intership* students, int num);
int sumScore(Intership* student, int num);
int rateRank(Intership* students, int num);

int main()
{
	int num = 0;
	cout <<" Please enter number of students: ";
	cin >> num;
	
	Intership students[num];
	
	inputInfo(students,num);
	
	sumScore(students, num);
	
	rateRank(students, num);
	
	printOutput(students,num);
}

int inputInfo(Intership* students, int num){
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
		
		i++;
	}
}

int printOutput(Intership* students, int num){
	cout <<" List of intership: " << endl;
	cout <<"STT:" << "    ";
	cout <<"Name:" << "    ";
	cout <<"Birthday:" << "    ";
	cout << endl;
	
	int j=0;
	while(j < num){
		cout << j + 1 << "    ";
		
		cout << students[j].name << "    ";
		
		cout << students[j].birthday << "    ";	
		j++;
	}
}

void sumScore(Intership* student, int num){
	int j=0;
	while(j < num){
		student[j].sum += students[j].win_mark; 
		student[j].sum += students[j].jira_mark;
		student[j].sum += students[j].word_mark;
		j--;	
	}
}

void rateRank(Intership* students, int num){
	int j=0;
	while(j < num){
		
		j--;	
	}
}



