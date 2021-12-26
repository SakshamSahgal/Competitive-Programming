#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    string s;
    cin>>s;
    int elo = -1;
    int ego = -1;
    vector <int> index;
    for(int i=0; i<s.size(); i++)
    {
        if( (s[i]-48)%2 == 0 )
        {
            //cout<<"Comparison = "<<(s[i]-48)<<" "<<( s[s.size()-1]-48 )<<"\n";
            if(  (s[i]-48) > ( s[s.size()-1]-48 ) )
            {
                    ego = i;
            }
            else if(  (s[i]-48) < ( s[s.size()-1]-48 ) )
            {
                if(elo == -1)
                    elo = i;
            }
            if(elo != -1)
                break;
        }
    }
        //cout<<"ELO = "<<elo<<"EGO = "<<ego<<"\n";
        if(elo!= -1)
        {
            char temp;
            temp = s[elo];
            s[elo] = s[s.size()-1];
            s[s.size()-1] = temp;
            cout<<s<<"\n";
        }
        else if(ego != -1)
            {
            char temp;
            temp = s[ego];
            s[ego] = s[s.size()-1];
            s[s.size()-1] = temp;
            cout<<s<<"\n";
            }
        else
        cout<<"-1\n";

return 0;
}

