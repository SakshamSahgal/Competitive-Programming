#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void array_printer(lli a[],int n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    int maxx = INT_MIN;
    int maxx_index=0;
    int minn = INT_MAX;
    int a[n];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] > maxx)
        {
            maxx = a[i];
            maxx_index = i;
        }
        minn = min(a[i],minn);
    }

    if(k == 1)
        cout<<minn<<"\n";
    else
    {
        if(k == 2)
        {

            if(maxx_index == 0 || maxx_index == n-1)
                cout<<maxx<<"\n";
            else
            {
                lli min_left[n];
                lli min_right[n];
                int minn_r = INT_MAX;
                int minn_l = INT_MAX;

                for(int i=0,j=n-1; i<n; i++,j--)
                {
                    minn_l = min(a[i],minn_l);
                    min_left[i] = minn_l;

                    minn_r = min(a[j],minn_r);
                    min_right[j] = minn_r;
                }

               // array_printer(min_left,n);
               // array_printer(min_right,n);
                int my_maxx = INT_MIN;
                for(int i=0; i<n-1; i++)
                {
                   // cout<<"i = "<<i<<" "<<min_left[i]<<" "<<min_right[i+1]<<" \n";
                    my_maxx = max(my_maxx,(int)max(min_left[i],min_right[i+1]));
                }
                cout<<my_maxx<<"\n";
            }
        }
        else
            cout<<maxx<<"\n";
    }


    return 0;
}


