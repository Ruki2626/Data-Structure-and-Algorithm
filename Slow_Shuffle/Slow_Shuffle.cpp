#include<iostream>
#include<random>
using namespace std ;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bad_Shuffle(int a[] , int n)
{
	int pick;
	int y[n];
	for(int i=0;i<n;i++){
		do{
			pick =rand() % n;
		}
		while (a[pick] < 0);
		y[i] = a[pick] ;
		a[pick] = -1 ;
		swap(&a[i] , &a[pick]);
	}
	for (int i=0;i<n;i++){
		a[i] = y[i];
	}
}

int main(){
	int n ;
	cout << "enter the value of n";
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
	cin >> a[i] ;
	}
	Bad_Shuffle(a,n);
	for(int i=0;i<n ;i++){
		cout << a[i] << ' ';
	}
	cout << "\n" ;
	Bad_Shuffle(a,n);
	for(int i=0;i<n ;i++){
		cout << a[i] << ' ';
	}
	cout << "\n" ;
	Bad_Shuffle(a,n);
	for(int i=0;i<n ;i++){
		cout << a[i] << ' ';
	}
}
