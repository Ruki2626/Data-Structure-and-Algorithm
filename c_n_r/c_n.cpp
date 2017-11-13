#include <iostream>
#include <cstdint>
using namespace std;


int Combinations(unsigned int n, unsigned int r)
{
    if (r > n)
        return 0;
    unsigned int v = n--;

    for (unsigned int i = 2; i < r + 1; ++i, --n)
        v = v * n / i;

    return v;
}

int main()
{
	unsigned int k,n;
	cout <<  "Enter the value of n & k";
	cin >> n >> k ;
	cout << Combinations(n,k) ;
}
