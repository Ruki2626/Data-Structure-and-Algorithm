#include <iostream>
using namespace std;

void maximum_heap(int x[], int i, int n)
{
    int left,right,large,b;
    left = 2*i;
    right = (2*i+1);
    if( (left <= n) && (x[left] > x[i]))
       large = left;
    else
       large = i;
    if((right <= n) && (x[right] > x[large]))
       large = right;
    if(large != i)
    {
         b = x[i];
         x[i] = x[large];
         x[large] = b;
         maximum_heap(x, large,n);
    }
}
void Build_maximum_heap(int x[], int n)
{
    for(int a = n/2; a >= 1; a--)
    {
        maximum_heap(x, a, n);
    }
}
void Heap_Sort(int x[], int n)
{
    Build_maximum_heap(x,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = x[i];
        x[i] = x[1];
        x[1] = temp;
        maximum_heap(x, 1, i-1);
    }
}
int main()
{
    int n;
    cout<<"Enter size of arr"<< '\n';
    cin>>n;
    int x[n];
    cout<<"Enter Elements"<< '\n';
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
    }
    Heap_Sort(x, n);
    cout<<"Sorting Elements "<<'\n';
    for (int i = 1; i <= n; i++)
    {
        cout<<x[i]<< '\n';
    }
}
