#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

char lowest_freq_odd = '*';
char lowest_freq_even= '*';
char highest_freq_odd= '*';
char highest_freq_even= '*';
int min_freq_even=1001;
int min_freq_odd=1001;
int max_freq_even = 0;
int max_freq_odd = 0;
bool is_palendrome(vector <char> SV)
{
    vector <char> DE;
    vector <int> freq;
    bool found = 0;
    for(usi i=0; i<SV.size(); i++)
    {
        found = 0;
        for(usi j=0; j<DE.size(); j++)
        {
            if(SV[i] == DE[j])
            {
                found = 1;
                freq[j]++;
                break;
            }

        }

        if(found == 0)
        {
            DE.push_back(SV[i]);
            freq.push_back(1);
        }

    }

    min_freq_even= 1001;
    min_freq_odd= 1001;
    max_freq_even = -1;
    max_freq_odd = -1;
    lowest_freq_odd = '*';
    lowest_freq_even = '*';
    highest_freq_odd = '*';
    highest_freq_even = '*';

    for(int i=0; i<freq.size(); i++)
    {
        if(freq[i]%2 == 0)
        {
            if(freq[i] < min_freq_even )
            {
                min_freq_even = freq[i];
                lowest_freq_even = DE[i];
            }
            if(freq[i] > max_freq_even )
            {
                max_freq_even = freq[i];
                highest_freq_even = DE[i];
            }

        }
        else
        {
            if(freq[i] < min_freq_odd )
            {
                min_freq_odd = freq[i];
                lowest_freq_odd = DE[i];
            }
            if(freq[i] > max_freq_odd )
            {
                max_freq_odd = freq[i];
                highest_freq_odd = DE[i];
            }
        }
    }

    if(min_freq_even == 1001)
        min_freq_even = 0;

    if(min_freq_odd == 1001)
        min_freq_odd = 0;

    if(max_freq_even == -1)
        max_freq_even = 0;

    if(max_freq_odd == -1)
        max_freq_odd = 0;
    /*
    cout<<"\n-----------------------\n";
    for(usi i=0; i<DE.size(); i++)
        cout<<DE[i]<<" ";
    cout<<"\n-----------------------\n";
    for(usi i=0; i<freq.size(); i++)
        cout<<freq[i]<<" ";
    cout<<"\n-----------------------\n";

    cout<<"lowest freq even = "<<lowest_freq_even<<" ";
    cout<<"min freq even = "<<min_freq_even<<"\n";
    cout<<"lowest freq odd = "<<lowest_freq_odd<<" ";
    cout<<"min freq odd = "<<min_freq_odd<<"\n";

    cout<<"highest freq even = "<<highest_freq_even<<" ";
    cout<<"max freq even = "<<max_freq_even<<"\n";
    cout<<"highest freq odd = "<<highest_freq_odd<<" ";
    cout<<"max freq odd = "<<max_freq_odd<<"\n";
    cout<<"\n-----------------------\n";
    */
    if(SV.size()%2 == 0)
    {
        if(min_freq_odd == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(min_freq_odd == 1)
            return 1;
        else
            return 0;
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    vector <char> SV;
    int chance = 0;
    string s;
    cin>>s;
    for(usi i=0; i<s.size(); i++)
        SV.push_back(s[i]);

    //cout<<is_palendrome(SV);
    x:
    if(is_palendrome(SV) == 1)
        {
        //victory of current player
        if(chance%2 == 0)
        cout<<"First\n";
        else
        cout<<"Second\n";
        }
    else
        {
               chance++;

                if(max_freq_even!= 0)
                    {
                         for(usi i=0;i<SV.size();i++)
                         {
                            if(SV[i] == highest_freq_even)
                                {
                                auto ptr = SV.begin();
                                SV.erase(ptr+i);
                                break;
                                }
                         }
                    }
                else
                    {
                     for(usi i=0;i<SV.size();i++)
                         {
                            if(SV[i] == highest_freq_odd)
                                {
                                auto ptr = SV.begin();
                                SV.erase(ptr+i);
                                break;
                                }
                         }
                    }

        goto x;
        }
    return 0;
}

