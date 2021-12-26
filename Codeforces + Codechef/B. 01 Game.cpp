#include<iostream>
#include<vector>
#define usi unsigned short int
using namespace std;
void Printer(vector <char> str)
{
cout<<"\n----------\n";
for(usi i=0;i<str.size();i++)
    cout<<str[i]<<" ";
cout<<"\n----------\n";
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
    vector <char> str;
    for(usi i=0;i<s.length();i++)
        str.push_back(s[i]);

    auto it = str.begin();


    usi c=0;
    y:
    bool got_in = 0;
   for(usi i=0;i<str.size()-1;i++)
            {
                if( (str[i] == '0' && str[i+1] == '1') || (str[i] == '1' && str[i+1] == '0') )
                    {
                    got_in = 1;
                    c++;
                    str.erase(it+i);
                    str.erase(it+i);
                    //Printer(str);
                    break;
                    }
            }

        if(got_in == 0 || str.size() == 0)
            {
              if(c%2 ==0)
            cout<<"NET\n";
            else
            cout<<"DA\n";
            }
        else
            goto y;



    }

return 0;
}
