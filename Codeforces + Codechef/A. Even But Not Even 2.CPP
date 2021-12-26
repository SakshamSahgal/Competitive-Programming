#include<iostream>
using namespace std;
int sod(char s[3000],int n)
{
unsigned short int sum=0;
for(int i=0;i<n;i++)
        if(s[i] != '$')
            sum +=(s[i]-48);
return sum;
}

void corrector(char s[3000],int n)
{
char d[3000];
unsigned int j=0;
for(unsigned int i=0;i<n;i++)
    {
        if(s[i] != '$')
            {
            d[j] = s[i];
            j++;
            }
       //cout<<"j this time = "<<j<<"\n";
    }
//cout<<"j = "<<j<<"\n";
bool checker = 0;
if(j==1)
    {
    cout<<"-1\n";
    }
else
    {
    for(int i=0;i<j;i++)
        {
            if(checker == 0)
                if( (d[i]-48)!=0)
                    checker = 1;

            if(checker == 1)
                cout<<d[i];
        }
cout<<"\n";
    }


}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned short int t;
cin>>t;
while(t--)
    {
    unsigned short int n;
    cin>>n;
    char s[3000];
    cin>>s;
    //cout<<"sum of digits = "<<sod(s,n)<<"\n";

        if(n==1)
            {
            cout<<"-1\n";
            goto y;
            }

        else if((s[n-1]-48)%2!=0 && sod(s,n)%2==0)
            {
                cout<<s<<"\n";
                goto y;
            }
        else
            {
                bool check1 = 0;

                if( (s[n-1]-48)%2==0) //if last digit is even
                    {
                    check1 = 1;
                    //cout<<"\nyes last digit is not odd \n";
                    unsigned int i;
                    for(i=(n-1);i>=1;i--)
                    {
                        if( (s[i]-48)%2==0 )
                            s[i] = '$';
                        else
                        break;
                    }

                    if(i==0)
                        {
                        cout<<"-1\n";
                        goto y;
                        }
                    // cout<<"\nString before  ="<<s<<"\n";
                       // corrector(s,n);
                    }

                bool checker = 0;
                bool check2 =0;
                //cout<<"\nsum of digits = "<<sod(s,n)<<"\n";
                if(sod(s,n)%2!=0) //if sum is not even
                    {
                    check2 =1;
                    //cout<<"\nYes sum s not even \n";
                    for(unsigned int i=1;i<10;i+=2)
                        {
                               for(int j=0;j<(n-1);j++)
                                {
                                    if((s[j]-48) == i)
                                        {
                                        s[j] = '$';
                                        checker = 1;
                                        goto x;
                                        }

                                }
                        }

                    }

                          x:
                        if( (check2 == 1 && checker == 1) || (check1 == 1 && check2 == 0) || (check1 == 1 && check2 == 1 && checker == 1) )
                            {
                             //cout<<"\nString before  ="<<s<<"\n";
                            corrector(s,n);
                            goto y;
                            }
                        else
                        {
                            cout<<"-1\n";
                            goto y;
                        }


            }
    y:
    n= n;
    }

return 0;
}
