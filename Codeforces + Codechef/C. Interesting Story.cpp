#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
struct current_count
{
    int a;
    int b;
    int c;
    int d;
    int e;
    current_count()
    {
        a=0;
        b=0;
        c=0;
        d=0;
        e=0;
    }
};

struct current_count Counter(string s)
{
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;

    for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'a')
                a++;
            else if(s[i] == 'b')
                b++;
            else if(s[i] == 'c')
                c++;
            else if(s[i] == 'd')
                d++;
            else if(s[i] == 'e')
                e++;
        }
    current_count x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.d = d;
    x.e = e;
    return x;
}

bool is_max_greater_than_all_sum(struct current_count x)
{

    lli sum = x.a + x.b + x.c + x.d + x.e;
    int maxx = max( max(x.a,x.b) , max( max(x.c,x.d) , x.e ) );
    sum -= maxx;
    if(maxx > sum)
        return 1;
    else
        return 0;
}

struct current_count add_it(struct current_count x, struct current_count y)
{
    struct current_count f;
    f.a = x.a + y.a;
    f.b = x.b + y.b;
    f.c = x.c + y.c;
    f.d = x.d + y.d;
    f.e = x.e + y.e;
    return f;
}

void struct_printer(struct current_count c)
{
    cout<<c.a<<" "<<c.b<<" "<<c.c<<" "<<c.d<<" "<<c.e<<"\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        current_count c;
        int countt=0;
        vector<string> vv;
        vector <current_count> not_interesting;
        for(int i=0;i<n;i++)
            {
                string s;
                cin>>s;
                vv.push_back(s);
                struct_printer(Counter(s));

                current_count temp = Counter(s);

                if( is_max_greater_than_all_sum(temp) )
                {
                    cout<<"found \n";
                    countt++;
                    current_count temp2 = add_it(temp,c);
                }
                else
                {
                    not_interesting.push_back(temp);
                }
            }
        //cout<<countt<<"\n";
        if(countt == 0)
            cout<<0<<"\n";
        else
        {
            for(int i=0;i<not_interesting.size();i++)
            {
                current_count temp = add_it(not_interesting[i],c);
                if(is_max_greater_than_all_sum(temp))
                {
                    c = temp;
                    countt++;
                }
            }
            cout<<"\n--------------\n";
            struct_printer(c);
            cout<<"\n--------------\n";
            cout<<countt<<"\n";
        }

        t--;
    }

    return 0;
}
