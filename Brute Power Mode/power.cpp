#include<iostream>
using namespace std;
int power_mode(int x, int n){
	int prod = 1 ;
	while (n > 0 ){
    if (n%2 != 0){
    	prod = prod * x ;
    }
	x = x * x ;
    n = n / 2 ;
	}
 return prod ;
}

int main(){
	int x,n;
	cin >> x >> n ;
	cout << "\n" ;
	cout << power_mode(x,n) ;
}
