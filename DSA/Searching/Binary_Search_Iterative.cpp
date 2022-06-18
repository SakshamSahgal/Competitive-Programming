#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


bool Binary_Search(int a[],int n,int x)
{
    int l = 0;
    int h = n-1;
    int mid;

    while(l <= h)
    {
        mid = (l+h)/2;
        if( a[mid] == x )
        {
           cout<<"Found\n";
           return 1;
        }
        else if(a[mid] > x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}

int main()
{
    /*
    Best Case : Omega(1)
    Average Case : Theta(logN)
    Worst Case : O(logN) */
    int a[] = {1,20,30,40,100,1150};
    cout<<Binary_Search(a,6,100);
    return 0;
}
