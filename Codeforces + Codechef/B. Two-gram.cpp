#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#include<climits>
using namespace std;
void printer(vector <pair<char,char>> v, vector <int> freq)
{
cout<<"\n-----------------\n";
for(usi i=0;i<v.size();i++)
    cout<<v[i].first<<v[i].second<<" ";
cout<<"\n";
for(usi i=0;i<freq.size();i++)
    cout<<freq[i]<<"  ";
cout<<"\n-----------------\n";
}
int main()
{
usi n;
usi c=0;
cin>>n;
char s[n];
bool already_used = 0;
usi frequency_of_this_element = 0;
vector <pair<char,char>> distinct;
vector <int> freq;
for(usi i=0;i<n;i++)
    cin>>s[i];

    for(usi i=0;i<(n-1);i++)
        {
        frequency_of_this_element = 0;
        already_used = 0;
        for(usi j=0;j<distinct.size();j++)
            {
            if(s[i] == distinct[j].first && s[i+1] == distinct[j].second)
                    {
                        already_used = 1;
                        break;
                    }
            }
        if(already_used == 0)
            {
            distinct.push_back(make_pair(s[i],s[i+1]));
                for(usi j=0;j<(n-1);j++)
                    {
                        if(s[i] == s[j] && s[i+1] == s[j+1])
                            frequency_of_this_element++;
                    }

            freq.push_back(frequency_of_this_element);
            }

        }

//printer(distinct,freq);

usi maxi = INT_MIN;
usi index=0;
for(usi i=0;i<freq.size();i++)
    {
    if(freq[i]>maxi)
        {
        maxi = freq[i];
        index = i;
        }
    }
//cout<<"maximum index = "<<index<<"\n";
cout<<distinct[index].first<<distinct[index].second<<"\n";
return 0;
}
