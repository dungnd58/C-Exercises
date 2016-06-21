/*
Owner: Ngo Duc Dung
Added: 16/06/2016
Last update: 16/06/2016
*/


#include <iostream>
using namespace std;

// main() is where program execution begins.

int fibo(int n);

int main()
{
	int n;			//input number
	int x;			//fibonanci number
	int sum;		//sum of sequence of Fibonanci
	
	cout << "Please enter a random number: ";
	cin >> n;
	cout << endl;
	
	cout << "Sequence of Fibonanci: " << endl;
	while (n > 0){
		x = fibo(n);
		cout << x << " ";
   		sum += x;
   		n--;
	}
	
	cout << endl;
   	cout << "Sum of sequence of Fibonanci: " << sum << endl;
   
	return 0;
}

/*
Function: calculate fibonanci number
n: number is used to caculate fibonanci number
*/

int fibo(int n){
	if(n == 1 || n == 2){
		return 1;
	} else {
		return fibo(n-1) + fibo(n-2);
	}
}


