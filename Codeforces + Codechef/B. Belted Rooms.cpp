#include<iostream>
using namespace std;
int main()
{
unsigned short int t;
cin>>t;
unsigned int counter = 0;
while(t--)
    {
    unsigned int n;
    cin>>n;
    char s[n];
    cin>>s;
    bool all_equal = 1;
    for(int i=1;i<n;i++)
        {
            if(s[i] != s[0])
                {
                all_equal = 0;
                break;
                }
        }
    if(all_equal == 1)
        {
        cout<<n<<"\n";
        }
    else
        {
            if(n==2)
                {
                    if( (s[0] == '-') || (s[1] == '-') || (s[0] == s[1]) )
                        {
                        cout<<"2\n";
                        goto y;
                        }

                    else
                        {
                        cout<<"0\n";
                        goto y;
                        }

                }



            if((s[0] == '<'&& s[n-1] == '<') || (s[0] == '>'&& s[n-1] == '>') || (s[0] == '>'&& s[n-1] == '<') || (s[0] == '<'&& s[n-1] == '>'))
                counter++;


        for(int i=1;i<n;i++)
            {
            if((s[i] == '<'&& s[i-1] == '<') || (s[i] == '>'&& s[i-1] == '>') || (s[i] == '>'&& s[i-1] == '<') || (s[i] == '<'&& s[i-1] == '>') )
                counter++;
            }

            cout<<n-counter<<"\n";
        }
        y:
        counter = 0;
    }

return 0;
}
