#include<iostream>
#include<cmath>
int number_of_digit(int n)
    {
    int digit=0;
    while(n>0)
        {
        digit++;
        n = n/10;
        }
    return digit;
    }

using namespace std;
int main()
{
int t,n,temp,countit=0;
cin>>t;
while(t--)
    {
    countit = 0;
    cin>>n;
    int arr[number_of_digit(n)];
    while(n>0)
        {
        //cout<<"n = "<<n<<"\n";
        temp = (n/pow(10,(number_of_digit(n)-1)));
        arr[countit] = ceil(temp*(pow(10,(number_of_digit(n)-1))));
        countit++;
        n = n - ceil(temp*pow(10,(number_of_digit(n)-1)));
        }
    cout<<countit<<"\n";
    for(int i=0;i<countit;i++)
        {
        cout<<arr[i]<<" ";
        }
    cout<<"\n";
    }
return 0;
}
