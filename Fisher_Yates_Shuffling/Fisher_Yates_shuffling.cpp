#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
void Fisher_Yates_Shuffling(int *array, int n)
{
    int a[n];
    int ind[n];
    for (int i = 0; i < n; i++)
        ind[i] = 0;
    int index;
 
    for (int i = 0; i < n; i++)
    {
        do
        {
            index = rand() % n;
        }
        while (ind[index] != 0);
 
        ind[index] = 1;
        a[i] = *(array + index);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n" ;
}
 
int main(int argc, char **argv)
{
    cout << "Enter the array size: ";
    int n;
    cin >> n;
    cout << "Enter the array elements: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Fisher_Yates_Shuffling(a, n);
    Fisher_Yates_Shuffling(a, n);
    Fisher_Yates_Shuffling(a, n);
    Fisher_Yates_Shuffling(a, n);

}
