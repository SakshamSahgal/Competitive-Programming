#include<iostream>
#include<vector>
#define ui unsigned int
using namespace std;
void Details_printer(vector <char> di,vector <int> f)
{
cout<<"\n------------------------\n";
for(ui i=0;i<di.size();i++)
    {
    cout<<di[i]<<" ";
    }
cout<<"\n";
for(ui i=0;i<f.size();i++)
    {
    cout<<f[i]<<" ";
    }
cout<<"\n------------------------\n";
}

int main()
{
ui n;
cin>>n;
char s[n];
cin>>s;
vector <char> Distinct_Elements;
vector <int> Frequency;
if(n==1)
    {
    cout<<"Yes";
    return 0;
    }
else if(n == 2)
    {
    if(s[0] == s[1])
        {
            cout<<"Yes";
            return 0;
        }
    else
        {
        cout<<"No";
        return 0;
        }
    }
else
    {
    ui freq_of_this_Element=0;
    bool already_done = 0;
    for(ui i=0;i<n;i++)
        {

        freq_of_this_Element=0;

        already_done = 0;

        for(ui j=0;j<Distinct_Elements.size();j++)
            {
                if(s[i] == Distinct_Elements[j])
                    {
                    already_done = 1;
                    break;
                    }
            }

        if(already_done == 0)
            {
                Distinct_Elements.push_back(s[i]);

                for(ui k=0;k<n;k++)
                    {
                        if(s[i] == s[k])
                                freq_of_this_Element++;
                    }
                Frequency.push_back(freq_of_this_Element);
            }
        }

        //Details_printer(Distinct_Elements,Frequency);
        freq_of_this_Element = 0;
        //no of distinct elements having frequency 1
        for(ui i=0;i<Frequency.size();i++)
            {
                if(Frequency[i] == 1)
                freq_of_this_Element++;
            }
        if( (n-freq_of_this_Element) > 0 )
            {
                cout<<"Yes\n";
                return 0;
            }
        else
            {
                cout<<"No\n";
                return 0;
            }

    }


return 0;
}
