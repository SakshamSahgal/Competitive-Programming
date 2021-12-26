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
int m,s;
cin>>m>>s;
if(s == 0)
{
        if(m == 1)
            cout<<"0 0\n";
        else
            cout<<"-1 -1\n";
}
else
    {
        if(s>(9*m))
        {
            cout<<"-1 -1\n";
        }
        else
            {

            string s_max;
            string s_min;

            int s1 = s;
            int s2 = s;
            for(int i=1;i<=m;i++)
                {
                    if(i == 1)
                        {
                            for(int j=1;j<=9;j++)
                                {
                                    if( (s1-j) <=(9*(m-i)) )
                                       {
                                            s_min+=(j+48);
                                            s1-=j;
                                            break;
                                       }
                                }
                        }
                    else
                        {
                            for(int j=0;j<=9;j++)
                                {
                                    if( (s1-j) <=(9*(m-i)) )
                                       {
                                            s_min+=(j+48);
                                            s1-=j;
                                            break;
                                       }
                                }
                        }

                }

            cout<<s_min<<" ";

                for(int i=1;i<=m;i++)
                {
                    for(int j =9;j>=0;j--)
                        {
                            if( (s2-j) >= 0 )
                                {
                                 s_max+=(j+48);
                                s2-=j;
                                break;
                                }

                        }
                }
            cout<<s_max<<"\n";
            }
    }
return 0;
}

