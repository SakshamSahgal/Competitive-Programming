#include<iostream>
using namespace std;
#define usi unsigned short int
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
unsigned int countit=0;
unsigned int a,b;
while(n--)
    {
        countit = 0;
        cin>>a>>b;
        while(a>0 && b>0)
        {
            if(a==b)
            {
            countit += 1;
            //cout<<countit;
            break;
            }
            else if(b>a)
            {
            int temp = 0;
            temp+=b/a;
            b -=a*temp;
            countit+=temp;
            }
            else
            {
            int temp = 0;
            temp+=a/b;
            a-=b*temp;
            countit+=temp;
            }
           // cout<<"\n counter this time = "<<countit<<" a this time = "<<a<<" b this time "<<b<<"\n";
        }
    cout<<countit<<"\n";
    }
return 0;
}
