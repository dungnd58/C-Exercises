#include <iostream>

using namespace std;

// main() is where program execution begins.

int calculate(int m);

int main()
{
	int m;
	int sum = 0;
	
	cout << "Please enter 'minutes' of using: ";
	cin >> m;
	cout << endl;
	
	
	cout <<"The cost of telephone: " << endl;

	sum = calculate(m);
   
   	cout << " = " << sum << endl;
	return 0;
}

int calculate(int m){
	int sum = 25000;
	int temp;
	int cost50 = 600;
	int cost150 = 400;
	int cost200 = 200;
	
	cout <<" 25000 + ";
	
	while(m > 0){
		if(m > 200){
			temp = m-200;
			
			sum += temp*cost200;

			m -= temp;
			
			cout << temp << "*" << cost200 << " + ";
			
		} else if(m > 50 && m <= 200){
			temp = m-50;
			
			sum += temp*cost150;
			
			m -= temp;
			
			cout << temp << "*"  << cost150 << " + ";	
			
		} else if(m <= 50){
			sum += m*cost50;
			
			m -= 50;
			
			cout << temp << "*" << cost50;
		}
	}
	
	return sum;
}


