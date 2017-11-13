#include<iostream>
#include<random>
using namespace std ;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Naive_Shuffle(int x[] , int n)
{
	int pick;
	int y[n];
	for(int i=0;i<n;i++){

		do{
			pick = rand() % n ;
		}while(x[pick] == 0);
		y[i] = x[pick] ;
		x[pick] = 0;
	}
	for(int i=0; i<n;i++){
		x[i] = y[i];
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
	Naive_Shuffle(a,n);
	for(int i=0;i<n ;i++){
		cout << a[i] << ' ';
	}
	cout << "\n" ;
	Naive_Shuffle(a,n);
	for(int i=0;i<n ;i++){
		cout << a[i] << ' ';
	}
	cout << "\n" ;
	Naive_Shuffle(a,n);
	for(int i=0;i<n ;i++){
		cout << a[i] << ' ';
	}
}
