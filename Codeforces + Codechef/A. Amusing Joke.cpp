#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char a[100],b[100],c[100],d[200];
cin>>a>>b>>c;
cout<<"string length of a = "<<strlen(a)<<"\n"<<"string length of b = "<<strlen(b)<<"\n"<<"string length of c = "<<strlen(c)<<"\n";
for(int i=0; i<(strlen(a) + strlen(b)) ;i++)
    {

            if(i<strlen(a))
                {
                    //cout<<" i = "<<i<<"\n";
                d[i] = a[i];
                }
            else
                {
                    //cout<<"* i = "<<i<<"\n and "<<i-strlen(a)<<"\n";
                d[i] = b[i-strlen(a)];
                }

    }
cout<<"strlen of d = "<<strlen(d)<<"\n";
cout<<"\n";
cout<<"d before \n"
for(int i=0;i<(strlen(a) + strlen(b));i++)
    {
                    cout<<d[i];
    }

if((strlen(a) + strlen(b)) == strlen(c))
    {
                for(int i=0; i<(strlen(a) + strlen(b)) ;i++)
                    {
                            for(int j=0;j< (strlen(a) + strlen(b)) ;j++)
                                {
                                if(d[i] == c[j])
                                    {
                                    d[i] = '1';
                                    break;
                                    }
                                }
                    }

                    for(int i=0; i<(strlen(a) + strlen(b)) ; i++ )
                        {

                            if(d[i] != '1')
                                {
                                    goto c;
                                }

                        }

    }
else
    {
    c:
    cout<<"NO";
    }

cout<<"\n d = \n";

for(int i=0;i<(strlen(a) + strlen(b));i++)
    {
                  cout<<d[i];
   }


return 0;
}
