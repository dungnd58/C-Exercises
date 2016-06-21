/*
Owner: Ngo Duc Dung
Added: 16/06/2016
Last update: 16/06/2016
*/


#include <iostream>

using namespace std;

// main() is where program execution begins.

int calculate(int m);

int main()
{
	int m;			//minutes of using the telephong
	int sum = 0;	//sum of cost
	
	cout << "Please enter 'minutes' of using: ";
	cin >> m;
	cout << endl;
	
	
	cout <<"The cost of telephone: " << endl;

	sum = calculate(m);
   
   	cout << " = " << sum << endl;
	return 0;
}


// Function: caluate the cost of telephone

int calculate(int m){
	int sum = 25000;	//sum of cost
	int temp;			//current cost minus 50/150/200
	int cost50 = 600;	//cost of first 50 mins
	int cost150 = 400;	//cost of continuous 150 mins
	int cost200 = 200;	//cost of continuous 200 mins
	
	cout <<" 25000 + ";
	
	while(m > 0){
		if(m > 200){									//continuous 200 mins
			temp = m-200;
			
			sum += temp*cost200;

			m -= temp;
			
			cout << temp << "*" << cost200 << " + ";
			
		} else if(m > 50 && m <= 200){					//continuous 150 mins
			temp = m-50;
			
			sum += temp*cost150;
			
			m -= temp;
			
			cout << temp << "*"  << cost150 << " + ";	
			
		} else if(m <= 50){								//first 50 mins
			sum += m*cost50;
			
			m -= 50;
			
			cout << temp << "*" << cost50;
		}
	}
	
	return sum;
}


