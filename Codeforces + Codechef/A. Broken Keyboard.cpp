#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void vector_printer(vector <char> v)
{
sort(v.begin(),v.end());
if(v.size() == 0)
    cout<<"\n";
else
    {
   // cout<<"\n-------------\n";
    for(ui i=0;i<v.size();i++)
    cout<<v[i];
    //cout<<"\n-------------\n";
    cout<<"\n";
    }

}
bool found(char x,vector <char> v)
{
for(usi i=0;i<v.size();i++)
    {
    if(v[i] == x)
        return 1;
    }
return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    string s;
    cin>>s;
    if(s.size() == 1)
        cout<<s[0]<<"\n";
    else
        {
           vector <char> v;
            for(usi i=0;i<(s.size()-1);i++)
            {
            if(s[i] != s[i+1])
                {
                if(found(s[i],v) == 0)
                    v.push_back(s[i]);
                }
            else
            i++;
            }

        usi freq = 0;
       for(usi i=0;i<s.size();i++)
        {
            if(s[i] == s[s.size()-1])
                freq++;
        }
        if(freq%2 == 1)
            {
            if(found(s[s.size()-1],v) == 0)
                v.push_back(s[s.size()-1]);
            }


        vector_printer(v);
        }

    }
return 0;
}
