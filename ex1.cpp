#include <iostream>
using namespace std;

// main() is where program execution begins.

int fibo(int n);

int main()
{
	int n;
	int x;
	int sum;
	
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

int fibo(int n){
	if(n == 1 || n == 2){
		return 1;
	} else {
		return fibo(n-1) + fibo(n-2);
	}
}


