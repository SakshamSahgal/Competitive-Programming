#include<iostream>
using namespace std;
int bubble_Sorting(unsigned int a[],unsigned short int n)
{
int moves = (n*(n-1))/2 - 1;
int temp;
int counter = 0;
bool checker = 1;
for(int i=1;i<n;i++)
    {
    checker = 0;
    for(int j=0;j<=(n-1-i);j++)
        {
        if(a[j]>a[j+1])
            {
            counter++;
            checker = 1;
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            }
        }
    if(counter>moves)
        {
        //cout<<"\ncounter = "<<counter<<"\n";
        return 0;
        }
    if(checker == 0 && counter<=moves)
        {
           // cout<<"\ncounter"<<counter<<"\n";
            return 1;
        }
    }
}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned short int t;
cin>>t;
while(t--)
    {
    unsigned short int n;
    cin>>n;
    unsigned int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(bubble_Sorting(a,n) == 1)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    }
return 0;
}
