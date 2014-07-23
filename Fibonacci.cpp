//Zadanie 610.
//Napisac rekurencyjna funkcje obliczajaca n-ty wyraz ciagu Fibonacciego.

#include<iostream>
using namespace std;

long unsigned int Fibonacci(int n);

//**************************************************************************************************

int main()
{
     int n=16;

for (int i=0;i<n;i++){
	cout << i<<". "<<Fibonacci(i)<<endl;
	}
}

//**************************************************************************************************

long unsigned int Fibonacci(int n)
{
    if (n<=2) return 1;
    else return Fibonacci(n-1)+Fibonacci(n-2);
}
