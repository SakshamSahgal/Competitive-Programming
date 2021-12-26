#include<iostream>
#include<cmath>
using namespace std;
#define ui unsigned int
int main()
{
unsigned short int t;
cin>>t;
while(t--)
    {
    ui n,k;
    cin>>n>>k;
    bool checker = 0;
    int counter = 0;
    x:
    for(ui i=0;i<=n;i++)
        {
            int temp = i-n;
            int temp2 = i - abs(temp);
            if( abs(temp2) == k)
                {
                    cout<<counter;
                    checker = 1;
                }

        }

        if(checker == 0)
            {
            n++;
            goto x;
            }
    }
return 0;
}
