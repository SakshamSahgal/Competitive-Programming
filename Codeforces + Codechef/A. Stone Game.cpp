#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n];
        int maxx=INT_MIN;
        int mini=INT_MAX;
        int max_index=0;
        int min_index=0;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            if(a[i] > maxx)
            {
                maxx = a[i];
                max_index = i;
            }

            if(a[i] < mini)
            {
                mini = a[i];
                min_index = i;
            }

        }
        //cout<<maxx<<" "<<max_index<<" "<<mini<<" "<<min_index<<"\n";



        char max_char;
        char min_char;

        //maxx
        if(max_index+1 > n-max_index)
            max_char = 'R';
        else if(max_index+1 < n-max_index)
            max_char = 'L';
        else
            max_char = 'B';


        if(min_index+1 > n-min_index)
            min_char = 'R';
        else if(min_index+1 < n-min_index)
            min_char = 'L';
        else
            min_char = 'B';

        int d1 = min(max_index+1,n-max_index);
        int d2 = min(min_index+1,n-min_index);


        if(min_char == 'R' && max_char == 'R')
            cout<<max(d1,d2)<<"\n";
        else if(min_char == 'L' && max_char == 'L')
            cout<<max(d1,d2)<<"\n";
        else if(min_char == 'B' || max_char == 'B')
            cout<<min(max(d1,d2),(d1+d2))<<"\n";
        else
            cout<<min((d1+d2),min(max(d2,n-d1+1),max(d1,n-d2+1)))<<"\n";

        t--;
    }

    return 0;
}
