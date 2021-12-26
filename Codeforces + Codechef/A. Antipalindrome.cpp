#include<iostream>
#define usi unsigned short int
using namespace std;

int is_palindrome(string s,int starting_point)
{
int j = s.length()-1;
for(int i=starting_point;i<=(s.length()/2);i++,j--)
    {
        if(s[i] != s[j])
            return 0;
    }
    return 1;
}
int main()
{
string s;
cin>>s;
bool all_not_same = 0;
//all characters same
for(usi i=0;i<(s.length()-1);i++)
    {
    if(s[i] != s[i+1])
        {
        all_not_same = 1;
        break;
        }
    }
if(all_not_same == 0)
    {
    cout<<"0\n";
    return 0;
    }
else
    {
    usi j = 0;
    x:
    //cout<<j<<"\n";
    if(is_palindrome(s,j) == 0)
        {
        cout<<s.length()-j;
        return 0;
        }
    else
        {
        j++;
        goto x;
        }

    }
return 0;
}
