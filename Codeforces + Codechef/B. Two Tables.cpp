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
        lli max_up;
        lli max_right;
        lli x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        lli w,h;
        cin>>w>>h;
        max_up = H - y2;
        max_right = W - x2;
        lli free_right = x1 + max_right;
        lli free_up = y1 + max_up;

        if(h <= y1 && w<= x1)
            cout<<0<<"\n";
        else if(h >=  y1 && w <= x1)
            cout<<0<<"\n";
        else if(h <= y1 && w >= x1)
            cout<<0<<"\n";
        else
        {
            double up = 0;
            double right = 0;
            up = h - y1;
            right = w - x1;
            double diagonal;
            if(up <= max_up && right <= max_right)
            {
            diagonal = sqrt(up*up + right*right);
            cout<<setprecision(6)<<min(min(up,right),diagonal)<<"\n";
            }
            else
            {
                if(up <= max_up && right > max_right)
                    cout<<setprecision(6)<<up<<"\n";
                else if(up > max_up && right <= max_right)
                    cout<<setprecision(6)<<right<<"\n";
                else
                     cout<<"-1\n";
            }
        }
        t--;
    }
    return 0;
}

