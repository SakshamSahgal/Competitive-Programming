#include<iostream>
#include<algorithm>
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
    string s;
    cin>>s;
    lli c1=0,c2=0;
    lli answer=0;
    lli fronter[s.size()]= {0};
    lli backer[s.size()] = {0};
    if(s.size()<3)
        cout<<0<<"\n";
    else
    {
        for(int i=1,k=s.size()-2; i<s.size() && k>=0; i++,k--)
        {
            if(s[i] == 'v' && s[i-1]=='v' )
            {
                c1++;
                fronter[i]=c1;
            }
            else
                fronter[i]=c1;

            if(s[k] == 'v' && s[k+1] == 'v')
            {
                c2++;
                backer[k] = c2;
            }
            else
                backer[k] = c2;

        }
        /*
        for(int i=0; i<s.size(); i++)
            cout<<fronter[i]<<" ";
        cout<<"\n";
        for(int i=0; i<s.size(); i++)
            cout<<backer[i]<<" "; */

        for(int i=1; i<(s.size()-1); i++)
        {
            if(s[i] == 'o')
                answer+=fronter[i-1]*backer[i+1];
        }
        cout<<answer<<"\n";

    }


    return 0;
}

