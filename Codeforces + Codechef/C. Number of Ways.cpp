#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

vector<int> ne;
vector<int> p;
void solve_without_optimisation(int n,lli a[],lli p_s[])
{
    lli moves=0;
    lli c=0;
    for(int i=2; i<=(n-1); i++)
    {
        for(int j=i; j<=(n-1); j++)
        {
            moves++;
            lli fs = p_s[i-1];
            lli ms = p_s[j]-p_s[i-1];
            lli ls = p_s[n]-p_s[j];
            if(fs == ms && ms == ls)
            {
                cout<<"Found at "<<i<<" "<<j<<" ("<<fs<<")\n";
                c++;
            }

        }

    }
    cout<<c<<" moves req = "<<moves<<"\n";
}

void solve_with_optimisation(int n,lli a[],lli p_s[])
{
    lli moves=0;
    lli c=0;
    if(p_s[n]%3 != 0)
        cout<<"0\n";
    else
    {
        lli s=0;
        vector<lli> check;
        cout<<"\n----------\n";
        for(int i=1; i<=n; i++)
        {
            s+=a[i];
            if(s == p_s[n]/3)
            {
                if((i+1)>=2 && (i+1)<=(n-1))
                {
                    check.push_back(i+1);
                    cout<<i+1<<" ";
                }
            }

        }
        cout<<"\n----------\n";
        if(check.size() == 0)
            cout<<"0\n";
        else
        {
            for(int j=0,i=check[0]; j<check.size(); j++,i=check[j])
            {
                //cout<<"i = "<<i<<"\n";
                for(int j=i; j<=(n-1);)
                {
                    moves++;
                    lli fs = p_s[i-1];
                    lli ms = p_s[j]-p_s[i-1];
                    lli ls = p_s[n]-p_s[j];

                    if(fs == ms && ms == ls)
                    {
                        cout<<"Found at "<<i<<" "<<j<<"\n";
                        c++;
                        j++;
                    }
                    else if(fs < ms)
                    {
                        auto next_negative = lower_bound(ne.begin(),ne.end(),j+1);
                        if(next_negative == ne.end())
                            break;
                        else
                            j = ne[next_negative-ne.begin()];

                    }
                    else if(fs > ms)
                    {
                        auto next_positive = lower_bound(p.begin(),p.end(),j+1);
                        if(next_positive == p.end())
                            break;
                        else
                            j = p[next_positive-p.begin()];
                    }
                    else
                        j++;
                }
            }
            //cout<<c<<" moves req = "<<moves<<"\n";
            cout<<c<<"\n";
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    lli a[n+1];
    lli p_s[n+1];
    lli s=0;
    map<int,int> z;
    a[0]=0;
    p_s[0]=0;
    bool newg=0;
    lli st=0;
    lli ed=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];

        if(i>1)
        {
            if(a[i] == 0 && newg == 0)
            {
                z[i]
            }
        }

        if(a[i]<0)
            ne.push_back(i);
        else if(a[i]>0)
            p.push_back(i);
        s+=a[i];
        p_s[i]=s;
    }



    for(int i=1; i<n; i++)
    {
        if(a[i] == 0 && newg = 0)
        {

        }


    }

    cout<<"\n-------------------------\n";
    solve_without_optimisation(n,a,p_s);
    cout<<"\n-------------------------\n";
    // cout<<"\n";
    solve_with_optimisation(n,a,p_s);
    return 0;
}
