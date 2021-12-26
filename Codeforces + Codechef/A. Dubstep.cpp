#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string ch;
cin>>ch;
bool first=0;
for(int i=0;i<ch.size();i++)
    {
    if(ch[i] == 'W' && ch[i+1] == 'U' && ch[i+2] == 'B')
        {
        if(first == 1)
            {
            cout<<" ";
            }
            i+=2;
        }
    else
        {
        cout<<ch[i];
        first = 1;
        }
    }


return 0;
}
