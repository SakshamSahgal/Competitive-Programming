#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int Binary_Searcher(int a[],int n,int x)
{
int start = 0;
int endd = n-1;
int mid = (start+endd)/2;

while(start<=endd)
    {
        mid = (start+endd)/2;

        if(x == a[mid])
            return mid;
        else if( x < a[mid] )
            endd = mid-1;
        else
             start = mid+1;
    }
return (-1);
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int a[] = {0,1,5,8,9,12,14,55,200};

int x;
cin>>x;
cout<<Binary_Searcher(a,9,x);

return 0;
}
