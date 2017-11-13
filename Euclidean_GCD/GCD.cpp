#include<iostream>
using namespace std;

int gcd(int a, int b) {
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main(){
	int a,b ;
	cin >> a >> b ;
	cout << "\n" ;
	cout << gcd (a,b) ;
}
