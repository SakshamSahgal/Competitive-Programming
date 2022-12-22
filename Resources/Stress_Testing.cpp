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

typedef long long Long;
typedef pair<Long,Long> PII;

struct Testcase
{
    lli n;
    lli len;
    vector<lli> a;
    lli k;
};

int generate_random_btw(int a, int b)  //function gives random no btw [a,b] (inclusive)
{
    return (a + rand()%(b-a+1));
}

void Testcase_Printer(Testcase x)
{
    line_printer(20);
    cout<<x.n<<" "<<x.len<<"\n";
    for(int i=0; i<x.n; i++)
        cout<<x.a[i]<<" ";
    cout<<"\n";
    cout<<x.k<<"\n";
    line_printer(20);
}

Testcase generate_TestCase()
{
    Testcase t;
    t.n = generate_random_btw(1,100000);
    t.len = generate_random_btw(1,t.n);
    for(int i=0; i<t.n; i++)
        t.a.push_back(generate_random_btw(-1e9,1e9));
    t.k = generate_random_btw(0,t.n);

    //Testcase_Printer(t);
    return t;
}

int Brute_sol(Testcase T)
{
    int sig[100010];
    int N , L , K;
    N = T.n;
    L = T.len;
    vector<lli> arr = T.a;
    K = T.k;
    set< PII > S;
    set< PII > Q;
    Long sum = 0 , ma = -100000000000000000LL;
    // ===============================================
    for(int i = 0; i < N; ++i)
    {
        if( i >= L )
        {
            sum -= (sig[i-L]?-1:1)*arr[i-L];
            if(sig[i-L] && Q.size())
            {
                S.erase( PII(arr[i-L],i-L) );
                set<PII>::iterator it = Q.begin();
                sum -= (sig[it->second]?-1:1)*arr[it->second];
                sig[it->second] = 1;
                sum += (sig[it->second]?-1:1)*arr[it->second];
                Q.erase( *it );
                S.insert( *it );
            }
            else if(sig[i-L])
                S.erase( PII(arr[i-L],i-L) );
            else
                Q.erase( PII(arr[i-L],i-L) );
        }
        if(arr[i] < 0)
        {
            set<PII>::iterator it = S.end() , it2 = S.lower_bound( PII(arr[i],i) );
            if(S.size() < K)
            {
                sig[i] = 1;
                S.insert( PII(arr[i],i) );
            }
            else if(it2!=S.end())
            {
                it--;
                sum -= (sig[it->second]?-1:1)*arr[it->second];
                sig[it->second] = 0;
                sum += (sig[it->second]?-1:1)*arr[it->second];
                S.erase( PII(it->first,it->second) );
                Q.insert( PII(it->first,it->second) );
                S.insert( PII(arr[i],i) );
                sig[i] = 1;
            }
            else
            {
                Q.insert( PII(arr[i],i) );
            }
        }
        sum += (sig[i]?-1:1)*arr[i];
        if( i >= L-1 )
            ma = max( ma , max(sum,-sum) );
    }
    // ===============================================

    sum = 0;
    for(int i = 0; i < N; ++i)
        arr[i] = -arr[i] , sig[i] = 0;
    S.clear();
    Q.clear();
    // ===============================================
    for(int i = 0; i < N; ++i)
    {
        if( i >= L )
        {
            sum -= (sig[i-L]?-1:1)*arr[i-L];
            if(sig[i-L] && Q.size())
            {
                S.erase( PII(arr[i-L],i-L) );
                set<PII>::iterator it = Q.begin();
                sum -= (sig[it->second]?-1:1)*arr[it->second];
                sig[it->second] = 1;
                sum += (sig[it->second]?-1:1)*arr[it->second];
                Q.erase( *it );
                S.insert( *it );
            }
            else if(sig[i-L])
                S.erase( PII(arr[i-L],i-L) );
            else
                Q.erase( PII(arr[i-L],i-L) );
        }
        if(arr[i] < 0)
        {
            set<PII>::iterator it = S.end() , it2 = S.lower_bound( PII(arr[i],i) );
            if(S.size() < K)
            {
                sig[i] = 1;
                S.insert( PII(arr[i],i) );
            }
            else if(it2!=S.end())
            {
                it--;
                sum -= (sig[it->second]?-1:1)*arr[it->second];
                sig[it->second] = 0;
                sum += (sig[it->second]?-1:1)*arr[it->second];
                S.erase( PII(it->first,it->second) );
                Q.insert( PII(it->first,it->second) );
                S.insert( PII(arr[i],i) );
                sig[i] = 1;
            }
            else
            {
                Q.insert( PII(arr[i],i) );
            }
        }
        sum += (sig[i]?-1:1)*arr[i];
        if( i >= L-1 )
            ma = max( ma , max(sum,-sum) );
    }
    // ===============================================
    return ma;
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

int optimised_sol(Testcase T) //My sol
{
    lli n,len;

    n = T.n;
    len = T.len;

    vector<lli> a = T.a;

    lli k;
    k = T.k;

    vector<lli> ps(n,0);

    for(int i=0; i<n; i++)
        ps[i] = (i == 0) ? a[i] : ps[i-1] + a[i];


    multiset<lli> pos;
    multiset<lli> neg;
    lli tkpn=0;
    lli tknn=0;

    for(int i=0; i<len; i++)
    {
        if(a[i] > 0)
        {
            tkpn += a[i];
            pos.insert(a[i]);
            if(pos.size() > k)
            {
                lli sm = *pos.begin();
                pos.erase(pos.find(sm));
                tkpn -= sm;
            }
        }
        else if(a[i] < 0)
        {
            tknn += abs(a[i]);
            neg.insert(abs(a[i]));
            if(neg.size() > k)
            {
                lli sm = *neg.begin();
                neg.erase(neg.find(sm));
                tknn -= sm;
            }
        }
    }

    lli i=0;
    lli j=i+len-1;
    lli ans = -inf;
    while(1)
    {
        lli ss = sum_btw(ps,i,j);
        lli s1 = abs(ss + (lli)2*tknn);
        lli s2 = abs(ss - (lli)2*tkpn);
        ans = max(ans,max(s1,s2));
        if(j+1 < n)
        {
            if(a[i] < 0)
            {
                if( neg.count(abs(a[i])) )
                {
                    neg.erase(neg.find(abs(a[i])));
                    tknn -= abs(a[i]);
                }
            }

            if(a[i] > 0)
            {
                if( pos.count(a[i]) )
                {
                    pos.erase(pos.find(a[i]));
                    tkpn -= a[i];
                }
            }

            if(a[j+1] > 0)
            {
                tkpn += a[j+1];
                pos.insert(a[j+1]);
                if(pos.size() > k)
                {
                    lli sm = *pos.begin();
                    pos.erase(pos.find(sm));
                    tkpn -= sm;
                }
            }
            if(a[j+1] < 0)
            {
                tknn += abs(a[j+1]);
                neg.insert(abs(a[j+1]));
                if(neg.size() > k)
                {
                    lli sm = *neg.begin();
                    neg.erase(neg.find(sm));
                    tknn -= sm;
                }
            }
            i++;
            j++;
        }
        else
            break;
    }
    return ans;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int seed = time(0);
    srand(seed);
    int t;
    cin>>t;
    while(t)
    {
        Testcase x = generate_TestCase();
        lli s1 = optimised_sol(x);
        lli s2 = Brute_sol(x);

        if(s1 != s2)
        {
            Testcase_Printer(x);
            cout<<"my ans = "<<s1<<" correct ans = "<<s2<<"\n";
            goto l;
        }
        else
        {
            //cout<<"Match\n";
        }
        t--;
    }
    cout<<"Correct Sol\n";
    l:
    return 0;
}

