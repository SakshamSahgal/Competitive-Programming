#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli Shortest_distance(lli x1,lli y1,lli x2,lli y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

bool my_compare(pair<int,string> a,pair<int,string> b)
{
    return(a.first>b.first);
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
        int n,m,i,j;
        cin>>n>>m>>i>>j;
        i--;
        j--;
        lli c1 =  Shortest_distance(i,j,0,0);
        lli c2 =  Shortest_distance(i,j,0,m-1);
        lli c3 =  Shortest_distance(i,j,n-1,0);
        lli c4 =  Shortest_distance(i,j,n-1,m-1);
        //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<"\n";

        if(c1 == c2 && c2 == c3 && c3 == c4)
        {
            cout<<1<<" "<<1<<" "<<n<<" "<<m<<"\n";
        }
        else if(c1 == c2 || c1 == c3 || c2 == c4 || c3 == c4)
        {
            if(c1 == c3)
            {
                cout<<1<<" "<<1<<" "<<n<<" "<<m<<"\n";
            }
            else if(c1 == c2)
            {
                cout<<1<<" "<<1<<" "<<n<<" "<<m<<"\n";
            }
            else if(c2 == c4)
            {
                cout<<1<<" "<<m<<" "<<n<<" "<<1<<"\n";
            }
            else
            {
                cout<<n<<" "<<1<<" "<<1<<" "<<m<<"\n";
            }
        }
        else
        {
            vector<pair<int,string>> v;
            v.push_back({c1,"c1"});
            v.push_back({c2,"c2"});
            v.push_back({c3,"c3"});
            v.push_back({c4,"c4"});
            sort(v.begin(),v.end(),my_compare);
            if(v[0].second == "c1")
            {
                cout<<"1"<<" "<<"1"<<" "<<n<<" "<<m<<"\n";
            }
            else if(v[0].second == "c2")
            {
                cout<<"1"<<" "<<m<<" "<<n<<" "<<"1"<<"\n";;
            }
            else if(v[0].second == "c3")
            {
                cout<<n<<" "<<"1"<<" "<<"1"<<" "<<m<<"\n";
            }
            else if(v[0].second == "c4")
            {
                cout<<n<<" "<<m<<" "<<"1"<<" "<<"1"<<"\n";;
            }
        }
        t--;
    }

    return 0;
}
