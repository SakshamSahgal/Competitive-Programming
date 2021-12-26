#include<iostream>
#include<cstring>
using namespace std;
int digit_sum(char s[3000],int n)
{
int sum=0;
for(unsigned int i=0;i<n;i++)
        if(s[i] != '$')
            sum += (s[i]-48);
    return sum;
}

void converter(char s[3000],int n)
{
char d[3000];
    unsigned int j=0;
    for(unsigned int i=0,j=0;i<n;i++)
        {
        if(s[i]!='$')
                {
                d[j] = s[i];
                j++;
                cout<<"d[j] = "<<d[j]<<"\n";
                }

        }

bool check = 0;
for(unsigned int i=0;i<j;i++)
    {
        if(check == 0)
            if((d[i]-48) != 0)
                check = 1;

         if(check == 1)
                cout<<d[i];
    }
    cout<<"\n";
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
unsigned short int t;
cin>>t;
while(t--)
        {
        unsigned short int n;
        cin>>n;
        char s[3000];
        cin>>s;
        int i;

        if(n==1)
            {
            cout<<"-1\n";
            goto y;
            }
        if(digit_sum(s,n)%2 == 0 && (s[n-1]-48)%2 !=0)
        {
          cout<<s;
          goto y;
        }
        for(i=n-1;i>=1;i--)
            {
            if((s[i]-48)%2 == 0)
                s[i] = '$';
            else
                break;
            }
        if(i==0)
            {
            cout<<"-1\n";
            goto y;
            }
        else
        {
            //cout<<"\n"<<s<<"\n";
            //cout<<"digit sum = "<<digit_sum(s,n)<<"\n";

             if(digit_sum(s,n)%2 != 0)
            {
                for(i=1;i<10;i+=2)
                {
                for(int j=0;j<n-1;j++)
                    {
                    if(s[j] != '$' && (s[j]-48) == i)
                        {
                        s[j] = '$';
                        //cout<<"\n"<<"j = "<<j<<"\n";
                        goto x;
                        }
                    }
                }
            }
                x:
                   // cout<<"aaiya";
                    //cout<<"\n"<<s<<"\n";
            if(digit_sum(s,n)%2 == 0)
                        {
                        converter(s,n);
                        //cout<<"digit sum = "<<digit_sum(s,n)<<"\n";
                        }

        }

        y:
            n=n;

        }


return 0;
}
