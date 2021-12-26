#include<iostream>
#include<vector>
#define usi unsigned short int
using namespace std;

int is_palendrome(string s)
{
for(usi i=0;i<s.size();i++)
    {
    if(s[i] != s[s.size()-1-i])
        {
        return 0;
        }
    }
return 1;
}

void swap_it(char *a,char *b)
{
char temp = *a;
*a = *b;
*b = temp;
}

int main()
{
usi t;
cin>>t;
while(t--)
    {
    string s;
    cin>>s;
    if(s.length() == 1)
        {
        cout<<"-1\n";
        goto y;
        }
    else
        {
        bool all_not_same = 0;
        //if all are same
        for(usi i=0;i<(s.size()-1);i++)
            {
                if( s[i] != s[i+1] )
                    {
                    all_not_same = 1;
                    break;
                    }
            }
            if(all_not_same == 0)
                {
                cout<<"-1\n";
                goto y;
                }
            else
                {
                for(usi i=0;i<s.size();i++)
                    {
                    for(usi j=0;j<s.size();j++)
                        {
                            if( i!=j )
                                {
                                swap_it(&s[i],&s[j]);
                                if(is_palendrome(s) == 0)
                                    {
                                    cout<<s<<"\n";
                                    goto y;
                                    }
                                }

                        }
                    }
                cout<<"-1\n";
                goto y;
                }
        }

    y:
        s=s;
    }
return 0;
}
