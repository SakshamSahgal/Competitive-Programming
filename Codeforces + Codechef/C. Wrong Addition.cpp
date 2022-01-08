#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

vector<lli> no_to_vec(lli n)
{
    vector<lli> x;

    while(n!=0)
    {
        x.insert(x.begin(),(n%10));
        n/=10;
    }

    return x;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void make_same_size(vector<lli> &aa,vector<lli> &bb )
{
    if(aa.size() < bb.size() )
    {
        for(int i=1;i<=(bb.size()-aa.size());i++)
            aa.insert(aa.begin(),0);
    }
    else if(aa.size() > bb.size() )
    {
        for(int i=1;i<=(aa.size()-bb.size());i++)
            bb.insert(bb.begin(),0);
    }
}


lli vector_to_no(vector<lli> x)
{
    lli ans=0;
    for(int i=x.size()-1,j=0;i>=0;i--,j++)
        ans += x[i]*pow(10,j);
    return ans;
}

bool checker(vector<lli> aa,vector<lli> bb,vector<lli> ss)
{
    vector<lli> s;
    make_same_size(aa,bb);
    vector_printer(bb);

    for(int i=aa.size()-1;i>=0;i--)
    {
        if ( (aa[i] + bb[i]) <= 9)
            s.insert(s.begin(),(aa[i] + bb[i]));
        else
        {
            s.insert(s.begin(),(aa[i] + bb[i])%10);
            s.insert(s.begin(),((aa[i] + bb[i])/10)%10);
        }
    }

    cout<<"s = "<<vector_to_no(s)<<" and ss = "<<vector_to_no(ss)<<"\n";
    if(vector_to_no(s) == vector_to_no(ss))
        return 1;
    else
        return 0;
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli a,s;
        cin>>a>>s;
        vector<lli> aa = no_to_vec(a);
        vector<lli> ss = no_to_vec(s);
        vector<lli> bb;

        make_same_size(aa,ss);

        //vector_printer(aa);
        //vector_printer(ss);


        for(int i=aa.size()-1,j=ss.size()-1; i>=0 && j >= 0;)
        {
            if( ss[j] < aa[i] ) //double dig
            {
                if(j > 0)
                {
                    lli sx = (ss[j-1])*10 + ss[j];
                    lli req = sx - aa[i];
                    if(req > 9)
                    {
                        cout<<"-1\n";
                        goto l;
                    }
                    else
                    {
                        bb.insert(bb.begin(),req);
                    }
                }
                else
                {
                    cout<<"-1\n";
                    goto l;
                }

                j-=2;
                i--;
            }
            else
            {
                lli req = ss[j] - aa[i];
                bb.insert(bb.begin(),req);
                j--;
                i--;
            }
        }

        //vector_printer(bb);
        if(checker(aa,bb,ss) == 1)
            cout<<vector_to_no(bb)<<"\n";
        else
            cout<<"-1\n";
l:

        t--;
    }
    return 0;
}
