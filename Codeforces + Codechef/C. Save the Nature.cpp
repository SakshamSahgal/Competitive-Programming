#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
struct Prefix
{
    lli no_of_multiples_of_a;
    lli no_of_multiples_of_b;
    lli no_of_multiples_of_and_b;
};

lli sum_between(lli summer[],lli l,lli r)
{
    if(r<l)
        return 0;
    else
    {
        if((l-1)>=1)
            return (summer[r] - summer[l-1]);
        else
            return(summer[r]);
    }

}

void Struct_printer(struct Prefix x[],int n)
{
    cout<<"\n-----------------------------\n";
    for(int i=1; i<=n; i++)
        cout<<x[i].no_of_multiples_of_a<<" ";
    cout<<"\n";
    for(int i=1; i<=n; i++)
        cout<<x[i].no_of_multiples_of_b<<" ";
    cout<<"\n";
    for(int i=1; i<=n; i++)
        cout<<x[i].no_of_multiples_of_and_b<<" ";
    cout<<"\n-----------------------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    while(q)
    {
        int n;
        cin>>n;
        lli p[n+1];
        p[0]=INT_MAX;
        Prefix p_sum[n+1];
        lli noa=0;
        lli nob=0;
        lli noa_and_b=0;
        for(int i=1; i<=n; i++)
            cin>>p[i];
        sort(p+1,p+n+1,greater<int>());
        lli x,a,y,b;
        cin>>x>>a;
        cin>>y>>b;
        for(int i=1; i<=n; i++)
        {
            if(i%a == 0 && i%b == 0)
                noa_and_b++;
            else
            {
                if(i%a == 0)
                    noa++;
                else if(i%b == 0)
                    nob++;
            }
            p_sum[i].no_of_multiples_of_and_b = noa_and_b;
            p_sum[i].no_of_multiples_of_a = noa;
            p_sum[i].no_of_multiples_of_b = nob;
        }
        //Struct_printer(p_sum,n);
        lli sum=0;
        lli summer[n+1];
        summer[0] =0;
        for(int i=1; i<=n; i++)
        {
            sum+=p[i];
            summer[i] = sum;
        }

        /*

        cout<<"\n---------------------\n";
        for(int i=1; i<=n; i++)
            cout<<summer[i]<<" ";
        cout<<"\n---------------------\n"; */

        lli k;
        cin>>k;
        bool found = 0;
        for(int i=1; i<=n; i++)
        {
            lli soanb;
            lli soa;
            lli sob;
            lli a1,a2;

            soanb = sum_between(summer,1,p_sum[i].no_of_multiples_of_and_b);
            soa = sum_between(summer,1 + p_sum[i].no_of_multiples_of_and_b, p_sum[i].no_of_multiples_of_and_b + p_sum[i].no_of_multiples_of_a);
            sob = sum_between(summer,1 + p_sum[i].no_of_multiples_of_and_b + p_sum[i].no_of_multiples_of_a, p_sum[i].no_of_multiples_of_and_b + p_sum[i].no_of_multiples_of_a + p_sum[i].no_of_multiples_of_b);

            a1 =  ((soanb*(x+y))/100) + ((soa*x)/100) + (((sob)*(y))/100);

            soanb = sum_between(summer,1,p_sum[i].no_of_multiples_of_and_b);
            sob = sum_between(summer,1 + p_sum[i].no_of_multiples_of_and_b, p_sum[i].no_of_multiples_of_and_b + p_sum[i].no_of_multiples_of_b);
            soa = sum_between(summer,1 + p_sum[i].no_of_multiples_of_and_b + p_sum[i].no_of_multiples_of_b, p_sum[i].no_of_multiples_of_and_b + p_sum[i].no_of_multiples_of_b + p_sum[i].no_of_multiples_of_a);

            a2 =  ((soanb*(x+y))/100) + ((soa*x)/100) + (((sob)*(y))/100);

            lli h = max(a1,a2);
            if(h>=k)
            {
                found = 1;
                cout<<i<<"\n";
                break;
            }
        }
        if(found == 0)
            cout<<"-1\n";

        q--;
    }

    return 0;
}
