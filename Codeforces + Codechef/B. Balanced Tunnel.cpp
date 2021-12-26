#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
struct cars
{
    int car_no;
    int entry_no;
    int exit_no;
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n;
    cin>>n;
    cars c[n];
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        c[i].car_no = a[i];
        c[i].entry_no = i+1;
    }
    int b[n];
    int x[n+1]; //index = car no //value = car no
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
        x[b[i]] = i+1;
    }
    for(int i=1; i<=n; i++)
        c[i-1].exit_no = x[c[i-1].car_no];

    int maxi[n];
    int maxx=0;
    for(int i=0; i<n; i++)
    {
        if(c[i].exit_no > maxx)
            maxx = c[i].exit_no;

        maxi[i] = maxx;
       // cout<<"car no = "<<c[i].car_no<<" entry no = "<<c[i].entry_no<<" exit no = "<<c[i].exit_no<<"\n";
    }
    //cout<<"\n";
    //for(int i=0; i<n; i++)
        //cout<<maxi[i]<<"\n";
    int cx=0;
    for(int i=0; i<n; i++)
    {
        if(i!=0)
        {
            if( c[i].exit_no < maxi[i-1])
            cx++;

        }
    }
    cout<<cx<<"\n";
    return 0;
}

