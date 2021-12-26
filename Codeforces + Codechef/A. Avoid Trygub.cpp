#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n;
    cin>>n;
    vector <char> v;
    char ch;
    for(usi i=0;i<n;i++)
        {
        cin>>ch;
        v.push_back(ch);
        }
        for(usi i=0;i<n;i++)
            {
            if(v[i] == 'b')
                {
                auto pos = v.begin();
                pos+=i;
                v.erase(pos);
                pos = v.begin();
                v.insert(pos,'b');
                }
            }



    //cout<<"\n";
    for(usi i=0;i<v.size();i++)
        cout<<v[i];
     cout<<"\n";
    }



return 0;
}
