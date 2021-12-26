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

        lli width = x2-x1;
        lli height = y2-y1;

        if(width + w <= W || height + h <= H)
        {
            if(w <= x1 || w <= W-x2 || h <= y1 || h <= H-y2)
                cout<<0<<"\n";
            else
            {

                lli max_up = H - y2;
                lli max_right = W-x2;
                lli max_down = y1;
                lli max_left = x1;


                lli required_up = max((lli)0,h-y1);
                lli required_right = max((lli)0,w-x1);
                lli required_down = max((lli)0,y2 - H + h);
                lli required_left = max((lli)0,x2 - W + w);

                lli blu;
                lli blr;
                lli mina;

                if( required_up <= max_up && required_right <= max_right )
                {
                    blu = required_up;
                    blr = required_right;
                    mina = min(blu,blr);
                }
                else if( required_up <= max_up && required_right > max_right )
                    mina = required_up;
                else
                    mina = required_right;


                lli bru;
                lli brl;
                lli minb;

                if(required_up <= max_up && required_left <= max_left)
                {
                    bru = required_up;
                    brl = required_left;
                    minb = min(bru,brl);
                }
                else if( required_up <= max_up && required_left > max_left)
                    minb = required_up;
                else
                    minb = required_left;


                lli trd;
                lli trl;
                lli minc;

                if( required_down <= max_down && required_left <= max_left )
                {
                    trd = required_down;
                    trl = required_left;
                    minc = min(trd,trl);
                }
                else if( required_down <= max_down && required_left > max_left )
                    minc = required_down;
                else
                    minc = required_left;

                lli tld;
                lli tlr;
                lli mind;

                if(required_down <= max_down && required_right <= max_right)
                {
                    tld = required_down;
                    tlr = required_right;
                    mind = min(tld,tlr);
                }
                else if(required_down <= max_down && required_right > max_right)
                    mind = required_down;
                else
                    mind = required_right;

                cout<<setprecision(6)<<min(min(mina,minb),min(minc,mind))<<"\n";
            }
        }
        else
            cout<<"-1\n";



        t--;
    }


    return 0;
}

