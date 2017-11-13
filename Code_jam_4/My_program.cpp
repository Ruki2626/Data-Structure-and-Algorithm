#include <iostream>
#include<fstream>
#define ull unsigned long long
#include <vector>
#include <algorithm>
using namespace std;
bool row_col_create(char *array[],int n, int row, int col)
{
    int row_num_plus=0,col_num_plus=0;
    int row_total_models=0,col_total_models=0;
    char *a=(char *)array;
    for (int i=0;i<n;i++)
    {
        if (a[(row*n)+i]!='.')
        {
            if (a[(row*n)+i]=='+')
            row_num_plus++;
            row_total_models++;
        }
        if (a[(i*n)+col]!='.')
        {
            if (a[(i*n)+col]=='+')
            col_num_plus++;
            col_total_models++;
        }
    }
    if ( ((row_num_plus>=(row_total_models-1))==true) && ((col_num_plus>=(col_total_models-1))==true) )
    return true;
    else
    return false;
}
bool diagCheck(char *arr[], int n, int row, int col)
{
    int num_x=0,r_num_x=0;
    int l_total_models=0,r_total_models=0;
    int sum=row+col, diff=row-col;
    char *a=(char *)arr;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if ((i+j)==sum)
            {
                if (a[(i*n)+j]!='.')
                {
                    if (a[(i*n)+j]=='x')
                    r_num_x++;
                    r_total_models++;
                }
            }
            if ((i-j)==diff)
            {
                if (a[(i*n)+j]!='.')
                {
                    if (a[(i*n)+j]=='x')
                    num_x++;
                    l_total_models++;
                }
            }
        }
    }
    if ( ((num_x>=(l_total_models-1))==true) && ((r_num_x>=(r_total_models-1))==true) )
    	return true;
    else
    	return false;
}
int main()
{
	int num_input;
	cin>>num_input;
	ofstream output;
	output.open("output.txt");
	for (long long test=1;test<=num_input;test++)
	{
	    int n , m;
	    cin>> n>> m;
	    char a[n][n];
	    for (int i=0;i<n;i++)
	        for (int j=0;j<n;j++)
	            a[i][j]='.';
	    char chr;
	    int chri,chrj;
	    for (int i=0;i<m;i++)
	    {
	        cin>>chr>>chri>>chrj;
	        a[chri-1][chrj-1]=chr;
	    }
	    int y=0,z=0;
	    vector<char> vec;
	    vector<int> ROW,COL;
	    for (int i=0;i<n;i++)
	    {
	        for (int j=0;j<n;j++)
	        {
	            char old=a[i][j];
	            if (a[i][j]!='o')
	            {
	                if (a[i][j]=='.')
	                {
	                    a[i][j]='o';
	                    if (!(row_col_create((char**)a,n,i,j) && diagCheck((char**)a,n,i,j)))
	                    a[i][j]='x';
	                    if (!(row_col_create((char**)a,n,i,j) && diagCheck((char**)a,n,i,j)))
	                    a[i][j]='+';
	                    if (!(row_col_create((char**)a,n,i,j) && diagCheck((char**)a,n,i,j)))
	                    a[i][j]='.';
	                }
	                else
	                {
	                    if (a[i][j]=='+')
	                    {
	                        a[i][j]='o';
	                        if (!(row_col_create((char**)a,n,i,j) && diagCheck((char**)a,n,i,j)))
	                        a[i][j]='+';
	                    }
	                    else if(a[i][j]=='x')
	                    {
	                        a[i][j]='o';
	                        if (!(row_col_create((char**)a,n,i,j) && diagCheck((char**)a,n,i,j)))
	                        a[i][j]='x';
	                    }
	                }
	            }
	            if (a[i][j]!=old)
	            {
	                z++;
	                char s=a[i][j];
	                vec.push_back(s);
	                ROW.push_back(i+1);
	                COL.push_back(j+1);
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(a[i][j]=='o')
	            y+=2;
	            else if (a[i][j]=='+' || a[i][j]=='x')
	            y+=1;
	        }
	    }

	    output<<"Case #"<<test<<": "<<y<<" "<<z<<endl;
	    for (unsigned int i=0;i<vec.size();i++)
	        output<<vec[i]<<" "<<ROW[i]<<" "<<COL[i]<<endl;
	}
	return 0;
}
