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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string baad;
    int index=-1;
    for(int i=0; i<n-1; i++)
    {
        if(s[i+1]<s[i])
        {
            index = i;
            break;
        }
    }
//cout<<index<<"\n";

    if(index == -1)
        index = n-1;

    for(int i=0; i<n; i++)
    {
        if(i!= index)
            baad += s[i];
    }




    if(s<baad)
        cout<<s;
    else
        cout<<baad;

    return 0;
}
