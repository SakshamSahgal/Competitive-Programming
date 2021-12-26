#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
bool Second_compare(pair <char,ui> p1,pair <char,ui> p2)
{
        return(p1.second>p2.second);
}


int main()
{
ui n,ques = 0;
cin>>n;
char s[n];
pair <char,ui> p[4];
p[0].first = 'A';
p[0].second = 0;
p[1].first = 'G';
p[1].second = 0;
p[2].first = 'C';
p[2].second = 0;
p[3].first = 'T';
p[3].second = 0;

for(ui i=0;i<n;i++)
    {
    cin>>s[i];

    if(s[i] == 'A')
        p[0].second++;
    else if(s[i] == 'G')
        p[1].second++;
    else if(s[i] == 'C')
        p[2].second++;
    else if(s[i] == 'T')
        p[3].second++;
    else
        ques++;
    }

sort(p,p+4,Second_compare);

ui rem = 0;
for(ui i=1;i<4;i++)
        rem += (p[0].second - p[i].second);
/*
cout<<rem<<" "<<ques<<"\n";
cout<<"\n";
cout<<p[0].first<<p[0].second<<"\n";
cout<<p[1].first<<p[1].second<<"\n";
cout<<p[2].first<<p[2].second<<"\n";
cout<<p[3].first<<p[3].second<<"\n";
*/
if(ques>= rem && (ques-rem)%4 == 0)
    {
        int maxi = p[0].second + (ques-rem)/4;

        for(ui i=0,c=0;i<n;i++)
            {
            if(s[i] == '?')
                {
                x:
                if(p[c].second < maxi)
                    {
                    cout<<p[c].first;
                    p[c].second++;
                    }
                else
                    {
                     c++;
                    goto x;
                    }

                }
            else
                cout<<s[i];
            }

    }
else
    {
    cout<<"===\n";
    }
/*
cout<<"\n";
cout<<p[0].first<<p[0].second<<"\n";
cout<<p[1].first<<p[1].second<<"\n";
cout<<p[2].first<<p[2].second<<"\n";
cout<<p[3].first<<p[3].second<<"\n";
*/
return 0;
}
