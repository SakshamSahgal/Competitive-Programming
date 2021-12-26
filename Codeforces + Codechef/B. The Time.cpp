#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
char time[5];
usi t;
for(usi i=0;i<5;i++)
    cin>>time[i];

cin>>t;

usi hh = (time[0]-48)*10 + (time[1]-48);
usi mm = (time[3]-48)*10 + (time[4]-48);
usi mr = 60-mm;
usi hr;
usi hta;
if(t>mr)
    {
    hh++;
    if(hh>=24)
        hh-=24;
    mm = 0;
    t -=mr;
    hr = 24 - hh;
    hta = (t/60);
    if(hta>hr)
        {
        hta -= hr;
        hr = 0;
        hh = 0;
        hta -= (hta/24)*24;
        hh += hta;
        if(hh>=24)
            hh-=24;
        mm += t%60;
        if(mm >= 60)
            {
            mm-=60;
            hh++;
            if(hh>=24)
                hh-=24;
            }

        }
    else
        {
         hh += t/60;
        mm = t%60;
        }
    }
else
    {
     mm+=t;
    }
if(mm >=60)
    {
    hh++;
    mm = 0;
    }
if(hh >= 24)
    hh = 0;

if(hh/10 == 0 && mm/10 == 0)
    {
    cout<<0<<hh<<":"<<0<<mm<<"\n";
    }
else if(hh/10 == 0 && mm/10 != 0)
    {
    cout<<0<<hh<<":"<<mm<<"\n";
    }
else if(hh/10 != 0 && mm/10 == 0)
    {
    cout<<hh<<":"<<0<<mm<<"\n";
    }
else
    {
    cout<<hh<<":"<<mm<<"\n";
    }
return 0;
}
