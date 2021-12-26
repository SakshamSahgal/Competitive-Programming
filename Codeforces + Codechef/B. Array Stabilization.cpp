#include<iostream>
#include<climits>
#define ui unsigned int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ui n;
cin>>n;
ui a[n];
int mini = 100001;
int second_mini = 100001;
int maxi = 0;
int second_maxi = 0;
for(ui i=0;i<n;i++)
    {
     cin>>a[i];
    if(a[i]>=maxi)
        {
        second_maxi = maxi;
        maxi = a[i];
        }
    else if(a[i]>second_maxi && a[i] != maxi)
        {
        second_maxi = a[i];
        }

    if(a[i] <= mini)
        {
        second_mini = mini;
        mini = a[i];
        }
    else if(a[i]<second_mini && a[i] != mini)
        second_mini = a[i];
    }
//cout<<"maximum = "<<maxi<<" minimum = "<<mini<<"\nsecond maximum = "<<second_maxi<<" second minimum = "<<second_mini<<"\n";

if( (second_maxi-mini)<(maxi-second_mini) )
    cout<<(second_maxi-mini);
else
    cout<<(maxi-second_mini);
return 0;
}
