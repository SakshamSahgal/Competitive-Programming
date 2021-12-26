#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
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

current_count Count_all(string s)
{
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;

    for(int i=0; i<s.length(); i++)
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


int max_minus_other(char maxx,current_count f)
{
    int sum = f.a + f.b + f.c + f.d + f.e;
    if(maxx == 'a')
    {
        sum -= f.a;
        return (f.a - sum);
    }
    else if(maxx == 'b')
    {
        sum -= f.b;
        return (f.b - sum);
    }
    else if(maxx == 'c')
    {
        sum -= f.c;
        return (f.c - sum);
    }
    else if(maxx == 'd')
    {
        sum -= f.d;
        return (f.d - sum);
    }
    else
    {
        sum -= f.e;
        return (f.e - sum);
    }
}

void set_printer(multiset<int> x)
{
    cout<<"\n---------------------------\n";
    for(auto i=x.rbegin(); i!=x.rend(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}

int max_strings(multiset<int> x)
{
    int sum=0;
    int counter=0;
    for(auto i=x.rbegin(); i!=x.rend(); i++)
    {
        sum+=(*i);
        if(sum<=0)
            break;
        else
            counter++;
    }

    return counter;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {

        int n;
        cin>>n;
        multiset<int> a;
        multiset<int> b;
        multiset<int> c;
        multiset<int> d;
        multiset<int> e;

        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            current_count temp = Count_all(s);
            a.insert(max_minus_other('a',temp));
            b.insert(max_minus_other('b',temp));
            c.insert(max_minus_other('c',temp));
            d.insert(max_minus_other('d',temp));
            e.insert(max_minus_other('e',temp));
        }

        // set_printer(a);
        // set_printer(b);
        // set_printer(c);
        // set_printer(d);
        // set_printer(e);

        cout<<max( max(max_strings(a),max_strings(b)), max ( max(max_strings(c),max_strings(d)), max_strings(e) ) )<<"\n";


        t--;
    }

    return 0;
}

