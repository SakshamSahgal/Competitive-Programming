#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

struct regis
{
    string DE;
    int freq=0;
};

void vector_printer(vector <string> inp,vector<regis> b)
{
    cout<<"\n#----input------\n";
    for(int i=0;i<inp.size();i++)
        cout<<inp[i]<<"\n";
    cout<<"\n-----regis------\n";
    for(int i=0;i<b.size();i++)
        cout<<b[i].DE<<" "<<b[i].freq<<"\n";
    cout<<"\n---------------#\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;
    cin>>n;
    vector <string> input;


    vector <regis> reg;
    string a;
    bool found = 0;
    for(int i=0; i<n; i++)
    {
        found = 0;
        cin>>a;
        input.push_back(a);
        for(int j=0; j<reg.size(); j++)
        {
            if(a == reg[j].DE)
            {
                found = 1;
                reg[j].freq++;
                cout<<a<<reg[j].freq<<"\n";
                break;
            }
        }

        if(found == 0)
        {
            cout<<"OK\n";
            reg.push_back(regis());
            reg[reg.size()-1].DE = a;
        }
        //vector_printer(input,reg);
    }

    return 0;
}

