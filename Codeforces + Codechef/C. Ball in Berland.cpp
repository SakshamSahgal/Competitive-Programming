#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void vector_printer(vector <pair<int,int>> v)
{
cout<<"\n----------------------------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n----------------------------------\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int a,b,k;
    cin>>a>>b>>k;
    int temp1;
    vector <pair<int,int>> c;
    //int c[k][2];
    for(int i=0;i<k;i++)
        {
        scanf("%d",&temp1);
        c.push_back(make_pair(temp1,0));
        }

    for(int i=0;i<k;i++)
        {
        scanf("%d",&temp1);
        c[i].second = temp1;
        }
    vector_printer(c);
    int m=0;
        for(int i=0;i<c.size()-1;i++)
            {
            for(int j=i+1;j<c.size();j++)
                {
                     if(c[i].first != c[j].first && c[i].second != c[j].second)
                     {
                         m++;
                         auto pos = c.begin() + j;
                        c.erase(pos);
                    vector_printer(c);
                     }

                }
            }
    cout<<m<<"\n";
    t--;
    }



return 0;
}
