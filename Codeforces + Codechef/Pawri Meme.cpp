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
        if(s.size()<5)
            cout<<s<<"\n";
        else
        {
            for(int i=0; i<=(s.size()-5); i++)
            {
                //cout<<"i = "<<i<<"\n";
                if(s[i] == 'p' && s[i+1] == 'a' && s[i+2] == 'r' &&  s[i+3] == 't' && s[i+4] == 'y' )
                    {
                        //cout<<"aaiya at i = "<<i<<"\n";
                        s[i+2] = 'w';
                        s[i+3] = 'r';
                        s[i+4] = 'i';
                        i+=4;
                    }
            }
        cout<<s<<"\n";
        }
        t--;
    }
    return 0;
}

