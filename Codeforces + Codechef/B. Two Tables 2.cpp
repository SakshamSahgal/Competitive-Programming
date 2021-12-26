#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
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
        lli W,H;
        cin>>W>>H;
        lli x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        lli w,h;
        cin>>w>>h;


        lli max_right = W - x2;
        lli max_up = H - y2;

        if(w <= x1 || w <= (W-x2) || h <= y1 || h <= (H-y2) )
            cout<<0<<"\n";
        else
        {
            lli free_right = x1 + max_right;
            lli free_up = y1 + max_up;

            if(w <= free_right || h <= free_up )
            {
                if(w <= free_right && h > free_up)
                    cout<<setprecision(6)<<w-x1<<"\n";
                else if(w > free_right && h <= free_up)
                    cout<<setprecision(6)<<h-y1<<"\n";
                else
                    cout<<setprecision(6)<<min(w-x1,h-y1)<<"\n";
            }
            else
                cout<<"-1\n";

        }
        t--;
    }
    return 0;
}

