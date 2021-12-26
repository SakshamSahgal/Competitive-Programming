#include<iostream>
using namespace std;
int number_Extractor(unsigned long long int n)
{
int digit = n%10;
return digit;
}

int luckycheck(int luckycount)
{
int check = 0;
for(int i=0;luckycount>0;i++)
    {
        if(number_Extractor(luckycount) == 7 || number_Extractor(luckycount) == 4)
            {
            }
        else
            {
            check = 1;
            return check;
            }
        luckycount = luckycount/10;
    }
return check;
}
int main()
{
unsigned long long int n;
int luckycount=0;
cin>>n;
for(int i=0;n>0;i++)
    {

    if(number_Extractor(n) == 4 || number_Extractor(n) == 7)
        {
            luckycount++;
        }
        n=n/10;
    }

if(luckycount == 0)
    {
    cout<<"NO\n";
    return 0;
    }
if(luckycheck(luckycount) == 1 )
    {
    cout<<"NO\n";
    }
else if(luckycheck(luckycount) == 0)
    {
    cout<<"YES\n";
    }
return 0;
}
