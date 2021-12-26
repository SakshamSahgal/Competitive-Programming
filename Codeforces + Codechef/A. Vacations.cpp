#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void pair_printer(vector<pair<int,char>> v)
{
    cout<<"\n------------pair------------\n";
    cout<<"value = ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" ";
    cout<<"\n";
    cout<<"select=";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].second<<" ";
    cout<<"\n-------------------------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int sum=0;
    vector<pair<int,char>> a;
    int temp;
    char selected;
    int counter=0;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        a.push_back(make_pair(temp,'X'));
    }

    if(n == 1)
    {
        if(a[0].first == 0)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(a[i].first == 0)
            {
                selected = 'N';
            }
            else if(a[i].first == 1)
            {
                if(i!=0)
                {
                    if(a[i-1].second == 'C')
                        selected = 'N';
                    else
                        selected = 'C';
                }
                else
                    selected = 'C';
            }
            else if(a[i].first == 2)
            {
                if(i!=0)
                {
                    if(a[i-1].second == 'G')
                        selected = 'N';
                    else
                        selected = 'G';
                }
                else
                    selected = 'G';
            }
            else
            {
                if( i!=0 && i!=(n-1) )
                {
                    if( (a[i-1].first == 'G' && a[i+1].first == 1) || (a[i-1].first == 'C' && a[i+1].first == 2) )
                        selected = 'N';
                    else
                        selected = 'C';
                }
                else
                {
                    if(i == 0)
                    {
                        if(a[i+1].first = 0)
                            selected = 'C';
                        else if(a[i+1].first = 1)
                            selected = 'G';
                        else if(a[i+1].first = 2)
                            selected = 'C';
                        else
                            selected ='C';
                    }
                    else
                    {
                        if(a[i-1].second = 'C')
                            selected = 'G';
                        else if(a[i-1].second = 'G')
                            selected = 'C';
                        if(a[i-1].second = 'N')
                            selected = 'C';
                        else
                            selected ='C';

                    }

                }
            }
            a[i].second = selected;
            if(selected == 'N')
                counter++;
        }

        pair_printer(a);
        cout<<counter<<"\n";
    }

    return 0;
}
