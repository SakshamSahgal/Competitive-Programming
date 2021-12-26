#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    string s;
    cin>>s;
    lli sum=0;
    int n = s.length();
    int prefix_sum[n];
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i] == s[i+1])
             sum++;
        prefix_sum[i] = sum;
    }
    prefix_sum[n-1] = sum;
    int m,l,r;
    cin>>m;
    while(m)
    {
        cin>>l>>r;
        int L = l-2;
        int R = r-2;
        if(L<0)
            cout<<prefix_sum[R]<<"\n";
        else
        cout<<prefix_sum[R] - prefix_sum[L]<<"\n";
        m--;
    }

    return 0;
}

