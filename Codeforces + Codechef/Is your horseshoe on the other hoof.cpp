#include<iostream>
using namespace std;
int main()
{
long long int a[4];
short int counter=0;
for(int i=0;i<4;i++)
    {
    cin>>a[i];
    }

for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            if(i==0)
                {
                if(a[i] == a[j])
                    {
                    counter++;
                    }
                }

           else
                {
                    if(a[i] != a[i-1])
                        {
                                if(a[i] == a[j])
                                    {
                                    counter++;
                                    }
                        }
                    else
                        {
                       break;
                        }
                }
        }

    }
cout<<(counter);
return 0;
}
