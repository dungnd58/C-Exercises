#include <iostream>
using namespace std;

// main() is where program execution begins.

int calculate(int m);

int main()
{
	int m;
	int sum = 25000;
	
	cout << "Please enter 'minutes' of using: ";
	cin >> m;
	cout << endl;
	
	sum += calculate(m);
   
   	cout << "The cost of telephone: " << sum << endl;
	return 0;
}

int calculate(int m){
	int sum = 0;
	int temp;
	int cost50 = 600;
	int cost150 = 400;
	int cost200 = 200;
	
	while(m > 0){
		if(m > 200){
			temp = m-200;
			sum += temp*cost200;
			m -= temp;
		} else if(m > 50 && m <= 200){
			temp = m-50;
			sum += temp*cost150;
			m -= temp;
		} else if(m <= 50){
			sum += m*cost50;
			m -= 50;
		}
	}
	
	return sum;
}


