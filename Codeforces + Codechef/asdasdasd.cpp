#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


void reset(lli &s,lli &thick)
{
    s = 0;
    thick = 0;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin >> n;
        lli a[n];

        lli sum = 0;

        for (lli i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }

        lli ansss= n;
        vector<lli> all_divisors;
        lli temp_sum = sum;
        for (lli i = 1; i * i <= temp_sum; i++)
        {
            if (temp_sum % i == 0)
            {
                all_divisors.push_back(i);
                if (temp_sum / i != i)
                    all_divisors.push_back(temp_sum / i);
            }
        }


        if (all_divisors.size() <= 2)
            cout<<n<<"\n";
        else
        {
            for (auto i : all_divisors)
            {
                lli s = 0;
                lli this_thick = 0;
                lli this_len = 0;
                lli rq = sum / i;
                bool not_found = 0;
                //  cout<<"to find = "<<rq<<"\n";
                for (lli i = 0; i < n; i++)
                {
                    s += a[i];
                    this_len++;
                    if (!(s-rq))
                    {
                        this_thick = max(this_len, this_thick);
                        reset(s,this_len);
                    }
                    else if (s > rq)
                    {
                        not_found = 1;
                        break;
                    }
                }
                if (!not_found)
                    ansss = min(ansss, this_thick);
            }
            cout<<ansss<<"\n";
        }

        t--;
    }
    return 0;
}
