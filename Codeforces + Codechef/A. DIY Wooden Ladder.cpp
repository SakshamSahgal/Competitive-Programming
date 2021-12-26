#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
unsigned int temp;
for(unsigned int i=1;i<n;i++)
    {
    temp = a[i];
    for(int j=(i-1);j>=0 && temp>a[j];j--)
        {
            a[j+1] = a[j];
            a[j] = temp;
        }
    }

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
short int t;
cin>>t;
while(t--)
    {
    unsigned int n;
    cin>>n;
    int a[n];
    for(unsigned int i=0;i<n;i++)
        cin>>a[i];
    if(n<3)
        {
        cout<<"0"<<"\n";
        }
    else
        {
        insertion_sort(a,n);//dec sorting
        if(a[0]>1 && a[1]>1)
            {
                if((a[1]-1)>(n-2))
                    {
                    cout<<n-2<<"\n";
                    }
                else
                    {
                    cout<<a[1]-1<<"\n";
                    }

            }
        else
            cout<<"0\n";
        }

    }
return 0;
}
