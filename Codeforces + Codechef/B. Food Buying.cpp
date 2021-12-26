#include<iostream>
using namespace std;
int main()
{

unsigned short int t;
cin>>t;
while(t--)
    {
    unsigned long int sp=0;
    int s=0;
    cin>>s;
    if(s<10)
        cout<<s<<"\n";
    else
        {
        do
            {
            s-=9;
            if(s>0)
                sp+=10;
            else
                sp+=1;
            }
        while(s>0);

         cout<<sp<<"\n";
        }



    }





return 0;
}
