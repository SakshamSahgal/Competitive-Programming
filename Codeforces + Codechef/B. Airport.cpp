#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Map_printer(multimap<int,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

void Map_printer2(multimap<int,int,greater<int>> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
        int n,m;
        cin>>n>>m;
        multimap<int,int,greater <int>> price_dec;
        multimap<int,int> price_acc;
        lli sum1=0;
        lli sum2=0;
        int x;
        for(int i=0; i<m; i++)
        {
            cin>>x;
            price_acc.insert({x,x});
            price_dec.insert({x,x});
        }
        //cout<<"size = "<<price_acc.size()<<" "<<price_dec.size()<<"\n";
       // Map_printer(price_acc);
       // Map_printer2(price_dec);
        for(int i=1;i<=n;i++)
        {
                {
                    auto acc = price_acc.begin();

                        int temp1 = acc->first;
                          sum1+=temp1;
                          price_acc.erase(acc);
                          if(temp1>1)
                          {
                              --temp1;
                              price_acc.insert({temp1,temp1});
                          }
                }

                {
                    auto dec = price_dec.begin();
                    int temp2 = dec->first;
                    sum2+=temp2;
                    price_dec.erase(dec);
                    if(temp2>1)
                    {
                        --temp2;
                        price_dec.insert({temp2,temp2});
                    }
                }
        }

    cout<<sum2<<" "<<sum1<<"\n";

    return 0;
}
