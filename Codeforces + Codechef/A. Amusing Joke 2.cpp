#include<iostream>
#include<string>
using namespace std;
int main()
{
string a,b,c,d;
int e = 0;
cin>>a>>b>>c;
//cout<<"string length of a ="<<a.size()<<"\nstring length of b = "<<b.size()<<"\nstring length of c = "<<c.size()<<"\n";
d = a+b;
//cout<<"\n"<<d;
//cout<<"string length of a ="<<d.size();
if((a.size() + b.size() ) == c.size() )
    {

        for(int i=0; i< (a.size() + b.size()) ;i++)
            {
            for(int j=0;j< (a.size() + b.size()) ; j++)
                {
                    if(d[i] == c[j])
                        {
                        c[j] = '1';
                        break;
                        }
                }
            }

        for(int i=0; i< (a.size() + b.size()) ;i++)
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

return 0;
}
