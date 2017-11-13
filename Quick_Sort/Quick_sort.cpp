#include <iostream>
#include <random>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Quick_Sort(int x[], int left, int right) {
      int i = left, j = right;
      int pivot = x[(left + right) / 2];
      while(i <= j) {
            while(x[i] < pivot)
                  i++;
            while(x[j] > pivot)
                  j--;
            if(i <= j) {
            	swap(&x[i], &x[j]);
                  i++;  j--;
            }
      };
      if (left < j)
            Quick_Sort(x, left, j);
      if (i < right)
            Quick_Sort(x, i, right);
}default_random_engine gen;

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
	int n;
	cout << "enter size of array" << '\n';
	cin >> n ;
	int x[n] ;
	randomArray(x, n, n);
	print(x, n);
	Quick_Sort(x, 0, n-1);
	print(x, n);
	int y[10] = {1,2,3,4,5,6,7,8,9,10} ;
	print(y,10);
	Quick_Sort(y,0,9) ;
	print(y,10) ;
	int z[10] = {10,9,8,7,6,5,4,3,2,1};
	print(z,10) ;
	Quick_Sort(z,0,9) ;
	print(z,10);
	int w[5] = {62,50,50,50,62};
	print(w,5) ;
	Quick_Sort(w,0,4) ;
	print(w,5);
}
