#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
void Time_Printer(bool m,int HH,int MM)
    {
        if(HH<10)
            {
                if(MM<10)
                    {
                        if(m==0)
                        cout<<"0"<<HH<<":0"<<MM<<" AM\n";
                        else
                        cout<<"0"<<HH<<":0"<<MM<<" PM\n";
                    }
                else
                    {
                        if(m==0)
                        cout<<"0"<<HH<<":"<<MM<<" AM\n";
                        else
                        cout<<"0"<<HH<<":"<<MM<<" PM\n";

                    }

            }
         else
        	 {
         		if(MM<10)
                    {
                        if(m==0)
                        cout<<HH<<":0"<<MM<<" AM\n";
                        else
                        cout<<HH<<":0"<<MM<<" PM\n";
                    }
                else
                    {
                        if(m==0)
                        cout<<HH<<":"<<MM<<" AM\n";
                        else
                        cout<<HH<<":"<<MM<<" PM\n";

                    }
        	 }
    }

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
bool m=0;
usi HH;
usi MM;
usi k;
usi counter = 0;

for(HH=12,k=0;HH<=12&&counter<=1;HH++,k++)
    {
        for(MM=0;MM<=59;MM++)
                Time_Printer(m,HH,MM);
        cout<<"\n*************\n";
        if(HH==11)
            {
                    counter++;
                    if(m==0)
                    m=1;
                    else
                    m=0;
                    cout<<"\n--------------\n";
                    cout<<"\n--------------\n";
            }
        if(HH==12)
        {
        	HH=0;
        }
    }
return 0;
}
