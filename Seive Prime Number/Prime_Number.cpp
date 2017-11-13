#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
const unsigned long long int maxsize = std::numeric_limits<unsigned long long int>::max();
int main()
{
	unsigned long long int i,j,m,n;
	long long np=0;
	bool *a = new bool[10000000000];
	cin>>m;
	cin>>n;
	for(i=2;i<n;i++)
	{
		a[i]=true;
	}
	for(i=2;i<=sqrt(n);i++)
	{
		if(a[i]==true)
		{
			for(j=i*i;j<=n;j+=i)
			{
				a[j]=false;
			}
		}
	}
	for(i=m;i<n;i++)
	{
		if(a[i]==true)
			np++;
	}
	cout<<np;
	delete [] a;
	return 0;
}
