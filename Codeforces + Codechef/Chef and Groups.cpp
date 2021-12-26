#include<iostream>
#include<algorithm>
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
    usi t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        int c=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                //cout<<"found at "<<i<<" ";
                int k=0;
                for(int j=i+1; j<n && s[j] == '1'; j++,k++)
                {
                   //
                }
                c++;
                i+=k;
                //cout<<"end at = "<<i<<"\n";
            }
        }



    cout<<c<<"\n";
        t--;
    }

    return 0;
}

