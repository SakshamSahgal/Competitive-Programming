#include<iostream>
using namespace std;
int exceptor(unsigned int n,unsigned int i,char s[])
{
bool checker = 0;
for(int j=0;j<n;j++)
    {
    if(j != i)
        {
            if(s[j] == '-' || s[j] == s[i])
                {
                checker = 1;
                }
            else
                {
                checker  = 0;
                return checker;
                }

        }

    }
return checker;

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned short int t;
cin>>t;
unsigned int counter = 0;
while(t--)
    {
    unsigned int n;
    cin>>n;
    char s[n];
    cin>>s;
    //all equal
    bool allequal = 1;

            if(n==2)
                {
                    if(s[0] == s[1] || s[0] == '-' || s[1] == '-')
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
            else
                {
                    if(s[0] == '-'|| s[n-1] == '-' || exceptor(n,0,s) == 1 || exceptor(n,n-1,s) == 1)
                        counter++;

                  for(int i=1;i<n;i++)
                    {
                        //cout<<"--contition check--"<<"i == "<<i<<" c 1 = "<<(s[i-1] == '-')<<" c 2 = "<<(s[i] == '-')<<" c 3 = "<<exceptor(n,i,s)<<"\n";
                        if(s[i-1] == '-' || s[i] == '-' || exceptor(n,i,s) == 1 || exceptor(n,i-1,s) == 1)
                        counter++;
                        //cout<<"\ncounter now = "<<counter<<"i == "<<i<<"\n";
                    }
                }

        cout<<counter<<"\n";
            y:
            counter = 0;
        }

    }

