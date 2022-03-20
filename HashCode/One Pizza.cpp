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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


void debug(map<lli,pair<vector<string>,vector<string>>> &cld,int c)
{
    line_printer(20);
    for(int i=0; i<c; i++)
    {
        cout<<" Client = "<<i<<" \n";
        cout<<"Likes : ";

        for(auto j:cld[i].first)
            cout<<j<<" ";

        cout<<"\nDislikes : ";

        for(auto j:cld[i].second)
            cout<<j<<" ";
        cout<<"\n";
    }
    line_printer(20);
}

lli string_to_index(string s)
{
    map<string,lli> x;
    x["cheese"] = 0;
    x["mushrooms"] = 1;
    x["tomatos"] = 2;
    x["basil"] = 3;
    x["peppers"] = 4;
    x["pineapple"] = 5;
    return x[s];
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}


vector<lli> ans;

void all_possiblities(vector<vector<lli>> &ld,lli c)
{
    lli maxx = INT_MIN;
    for(lli i=1; i<=63; i++) //combination
    {
        cout<<"i = "<<i<<" ";
        vector<lli> lenge;

        //constructing bitmask

        for(int j=0; j<=5; j++)
        {
            if((i>>j)%2)
                lenge.insert(lenge.begin(),1);
            else
                lenge.insert(lenge.begin(),0);
        }

        vector_printer(lenge);

        lli counter=0;

        //iterating over all clients

        for(lli k=0; k<c; k++) //checking for all clients
        {
            bool not_happy = 0;
            //binary of that

            for(lli this_bit = 0; this_bit < 6; this_bit++)
            {
                lli base_pwr = 6 - this_bit - 1;
                if( (lenge[base_pwr] == 1 && ld[base_pwr][k] == -1) || (lenge[base_pwr] == 0 && ld[base_pwr][k] == 1 ) )
                {
                    not_happy = 1;
                    break;
                }
            }

            if(!not_happy)
                counter++;
        }

        if(maxx < counter)
        {
            maxx = counter;
            ans = lenge;
        }


        cout<<" Happy people - "<<counter<<"\n";
        cout<<"\n";
    }
}



void ld_grid(vector<vector<lli>> &ld,lli &c,map<lli,pair<vector<string>,vector<string>>> &cld)
{
    for(int i=0; i<c; i++)
    {
        for(auto j:cld[i].first)
            ld[string_to_index(j)][i] = 1;

        for(auto j:cld[i].second)
            ld[string_to_index(j)][i] = -1;
    }
}


template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}
int main()
{
    //GO_FAST
    lli c;
    cin>>c;
    vector<vector<lli>> ld(6,vector<lli> (c));
    map<lli,pair<vector<string>,vector<string>>> cld;



    for(lli i=0; i<c; i++)
    {
        lli lc,dlc;
        cin>>lc;
        for(int j=0; j<lc; j++)
        {
            string like;
            cin>>like;
            cld[i].first.push_back(like);
        }
        cin>>dlc;
        for(int j=0; j<dlc; j++)
        {
            string dislike;
            cin>>dislike;
            cld[i].second.push_back(dislike);
        }
    }

    debug(cld,c);
    ld_grid(ld,c,cld);
    //Vec_2d_printer(ld);
    all_possiblities(ld,c);
    //cout<<"\n";
    //cout<<"Best ans = ";
    vector_printer(ans);
    string rr[] = {"cheese" , "mushrooms" , "tomatos" , "basil" , "peppers" , "pineapple"};

    int cc=0;
    for(int i=5;i>=0;i--)
        if(ans[i])
            cc++;

    cout<<cc<<"\n";

    for(int i=5;i>=0;i--)
    {
        if(ans[i])
            cout<<rr[5-i]<<" ";
    }
    return 0;
}
