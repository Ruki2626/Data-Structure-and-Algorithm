#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Selection_Sort(int x[], int n) {
	 int i, j,index;
	   for (i = 0; i < n-1; i++){
		   index =i;
	       for (j = i; j < n; j++)
	           if (x[j] < x[index])
	        	   index =j ;
	   swap(&x[index], &x[i]);
	   }
}
default_random_engine gen;

// fill an array of n elements with value from 0 to m
void randomArray(int x[], int n, int m) {
	uniform_int_distribution<int> distribution(0, m);
	for (int i = 0; i < n; ++i) {
		x[i] = distribution(gen);
	}
}

void print(int x[], int n) {
	for (int i = 0; i < n; ++i)
		cout << x[i] << ' ';
	cout << '\n';
}

int main() {
	const int n = 10;
	int x[n];
	randomArray(x, n, n);
	print(x, n);
	Selection_Sort(x, n);
	print(x, n);
	int y[5] = {1, 89, 90, 51, 7};
	Selection_Sort(y,5);
	print(y,5);
}
