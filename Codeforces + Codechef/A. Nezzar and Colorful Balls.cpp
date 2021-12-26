#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void vector_printer(vector<int> v1)
{
cout<<"\n--------\n";
for(int i=0;i<v1.size();i++)
    printf("%d ",(v1[i]));
cout<<"\n--------\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    usi n;
    cin>>n;
    usi a[n];
    vector <int> de;
    vector <int> f;
    bool found = 0;
    int index;
    for(usi i=0;i<n;i++)
        {
            cin>>a[i];
        found = 0;
        for(usi j=0;j<de.size();j++)
            {
                if(a[i] == de[j])
                    {
                        index = j;
                        found = 1;
                        break;
                    }
            }

        if(found == 0)
            {
                de.push_back(a[i]);
                f.push_back(1);
            }
        else
                f[index]++;
        }

    //vector_printer(de);
    //cout<<"\n";
    //vector_printer(f);
    cout<<*max_element(f.begin(),f.end())<<"\n";
    t--;
    }



return 0;
}
