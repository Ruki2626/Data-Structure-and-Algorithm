#include <cstdlib>
#include <iostream>
using namespace std;

int binary_search(int a[],int left,int right, int target){

	int index;
	if (left > right)
		index = -1;
	else{
		int mid = (left + right)/2;
		if (target == a[mid])
			index = mid;
		else if (target < a[mid])
			index = binary_search(a,left, mid-1, target);
		else
			index = binary_search(a, mid+1, right, target);
	}
 return index;
 }
int main() {
	int a[10];
	for (int k=0; k<10; k++)
		cin >> a[k] ;
	cout<< "binary search results: "<< binary_search(a,0,9,11)<< endl;
 return 0;
}
