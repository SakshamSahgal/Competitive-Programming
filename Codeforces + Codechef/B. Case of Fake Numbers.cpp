#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int moves(int i,int value,int n)
{
    if(i%2 == 0)
    {
        if(value>i)
            return(n-value+i);
        else if(value<i)
            return (i-value);
        else
            return 0;
    }
    else
    {
        if(value<i)
            return (value+n-i);
        else if(value>i)
            return (value-i);
        else
            return 0;
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    int m;
    bool no=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i == 0)
            m = moves(i,a[i],n);
        else
        {
            if(m != moves(i,a[i],n))
                no = 1;
        }
        //cout<<"moves = "<<moves(i,a[i],n)<<"\n";
    }

    if(no == 1)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return 0;
}
