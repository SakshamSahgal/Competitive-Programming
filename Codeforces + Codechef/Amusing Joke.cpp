#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char a[100],b[100],c[100],d[200];
int e = 0;
cin>>a>>b>>c;
cout<<"string length of a ="<<strlen(a)<<"\nstring length of b = "<<strlen(b)<<"\nstring length of c = "<<strlen(c)<<"\n";
for(int i=0;i<(strlen(a) + strlen(b));i++ )
    {
    if(i<strlen(a))
        {
        d[i] = a[i];
        }
    else
        {
        d[i] = b[i-strlen(a)];
        }
    }

cout<<"\n---------------------------\n";
for(int i=0;i<(strlen(a) + strlen(b));i++)
    {
    cout<<d[i];
    }
cout<<"\n---------------------------\n";



if((strlen(a) + strlen(b)) == strlen(c))
    {

        for(int i=0; i<(strlen(a) + strlen(b)) ;i++)
            {
            for(int j=0;j<(strlen(a) + strlen(b)); j++)
                {
                    if(d[i] == c[j])
                        {
                        c[j] = '1';
                        break;
                        }
                }
            }

        for(int i=0; i<(strlen(a) + strlen(b)) ;i++)
            {
                if(c[i] != '1')
                    {
                    e = 1;
                    //cout<<"aaiya  c[i] = "<<c[i]<<"\n";
                    goto g;
                    }

            }
        g:
        if(e == 1)
            {
            cout<<"NO";
            }
        else
            {
            cout<<"YES";
            }
        }
else
    {
    cout<<"NO";
    }

cout<<"\n---------------------------\n";
for(int i=0;i<(strlen(a) + strlen(b));i++)
    {
    cout<<c[i];
    }
cout<<"\n---------------------------\n";
return 0;
}
