#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define lli long long int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
string s;
cin>>s;
vector <char> v;
if(s.length()>1)
{

    for(usi i=0;i<s.length();i++)
        v.push_back(s[i]);

    bool done = 1;

      for(usi i=0;i<s.length();i++)
         {
         done = 1;
         for(usi j=0;j<(v.size()-1);j++)
           {
            if(v[j] == v[j+1])
              {
                auto ptr = v.begin();
                 v.erase(ptr+j);
                 v.erase(ptr+j);
                done = 0;
                break;
              }
           }
        if(done == 1 || v.size()<=1)
            break;
        }

    if(v.size() == 0)
        cout<<"empty string";
    else
        {
        for(usi i=0;i<v.size();i++)
            cout<<v[i];
        }


}
else
cout<<s;
return 0;
}
