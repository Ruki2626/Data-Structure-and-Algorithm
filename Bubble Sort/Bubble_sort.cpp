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

void Bubble_Sort(int x[], int n) {
	 int i, j;
	   for (i = 0; i < n-1; i++)
	       for (j = 0; j < n-i-1; j++)
	           if (x[j] > x[j+1])
	              swap(&x[j], &x[j+1]);

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
	Bubble_Sort(x, n);
	print(x, n);
	int y[5] = {55, 4, 90, 51, 7};
	Bubble_Sort(y,5);
	print(y,5);
}
