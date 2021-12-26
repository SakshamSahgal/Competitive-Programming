#include<iostream>
#define usi unsigned short int
using namespace std;
void swap(usi a[],usi i,usi j)
{
usi temp = a[i];
a[i] = a[j];
a[j] = temp;
}

void Printer(usi a[],usi n)
{
cout<<"\n------------------\n";
for(usi i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n------------------\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n;
    cin>>n;
    usi a[n];
    usi no_of_even_req;
    usi no_of_odd_req;
    usi no_of_even = 0;
    usi no_of_odd = 0;
    usi moves = 0;
    for(usi i=0;i<n;i++)
        {
        cin>>a[i];
        if(a[i]%2 == 0)
            no_of_even++;
        else
            no_of_odd++;
        }

    if(n%2 == 0)
        {
        no_of_even_req = n/2;
        no_of_odd_req = n/2;
        }
    else
        {
        no_of_even_req = n - (n/2);
        no_of_odd_req = n/2;
        }
    //cout<<"\neven req = "<<no_of_even_req<<" odd required = "<<no_of_odd_req<<" even = "<<no_of_even<<" no_of_odd "<<no_of_odd<<"\n";
    if( (no_of_even_req == no_of_even) && (no_of_odd_req == no_of_odd) )
        {
            for(usi i=0;i<n;i++)
                {
                    if(a[i]%2 != i%2)
                        {
                            for(usi j=i+1;j<n;j++)
                                {
                                    if(a[j]%2 != j%2 && a[j]%2 == i%2)
                                        {
                                            swap(a,i,j);
                                            //Printer(a,n);
                                            moves++;
                                            break;
                                        }
                                }

                        }
                }

        cout<<moves<<"\n";
        }
    else
        {
        cout<<"-1\n";
        goto y;
        }
    y:
        n=n;
    }

return 0;
}
