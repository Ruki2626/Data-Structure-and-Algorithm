#include <iostream>
#include <vector>
using namespace std;
void make_vector(vector<int>& v)
{
    int num, val;
    cout << "Enter the number of elements in vector ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> val;
        v.push_back(val);
    }
}
int lin_search(vector<int> v, int val)
{
    int key = -1;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (v[i] == val)
        {
            key = i;
            break;
        }
    }
    return key;
}

int main()
{
    int key, val;
    vector<int> v;
    make_vector(v);
    cout << "Enter the number : ";
    cin >> val;
    key = lin_search(v, val);
    if (key != -1)
        cout << "\nElement " << val
                  << " is at position " << ++key;
    else
        cout << "\nElement " << val
                  << " is not present";
}
