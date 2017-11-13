#include <iostream>
#include<random>
using namespace std;

void Merge(int x[], int left, int right, int middle)
{
    int i, j, k, c[50];
    i = left;
    k = left;
    j = middle + 1;
    while (i <= middle && j <= right)
    {
        if (x[i] < x[j])
        {
            c[k] = x[i];
            k++;
            i++;
        }
        else
        {
            c[k] = x[j];
            k++;
            j++;
        }
    }
    while (i <= middle)
    {
        c[k] = x[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        c[k] = x[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++)
    {
        x[i] = c[i];
    }
}

void Merge_Sort(int x[], int left, int right)
{
    int middle;
    if (left < right)
    {
        middle = (left + right)/2;
        Merge_Sort(x,left,middle);
        Merge_Sort(x, middle + 1,right);
        Merge(x, left, right, middle);
    }
    return;
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
	const int n = 10;
	int x[n];
	randomArray(x, n, n);
	print(x, n);
	Merge_Sort(x,0, n-1);
	print(x, n);
	int y[5] = {62, 50, 50, 50, 62};
	Merge_Sort(y, 0, 4);
	print(y,5);
}
