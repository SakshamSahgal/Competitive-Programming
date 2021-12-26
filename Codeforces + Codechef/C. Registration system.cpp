#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
void vector_printer(vector <string> a , vector <string> b)
{
cout<<"\n-----input-------\n";
for(int i=0;i<a.size();i++)
    cout<<a[i]<<"\n";
cout<<"\n";
cout<<"\n-------database-----------\n";
for(int i=0;i<b.size();i++)
    cout<<b[i]<<"\n";
cout<<"\n----------------------\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    vector <string> Database;
    vector <string> input;
    string a;
    bool found=0;
    int found_At=0;
    for(int i=0; i<n; i++)
    {
        found = 0;
        cin>>a;
        input.push_back(a);

        for(int j=Database.size()-1; j>=0; j--)
        {
            if( input[i] == Database[j] )
            {
                found = 1;
                found_At = j;
                break;
            }
        }

        if(found == 0)
            {
             cout<<"OK\n";
            Database.push_back(a);
            }

        else
        {
            cout<<"found at index = "<<found_At<<"\n";
            string in_database = Database[found_At];

            if( in_database.size() ==  a.size() )
            {
                in_database+='1';
                Database.push_back(in_database);
                cout<<in_database<<"\n";
            }
            else
            {
                int num = 1;

                int nod = in_database.size() - a.size();

                for(int k=a.size(),mult = pow(10,nod-1);k<in_database.size();k++,mult/=10)
                    {
                            num += (in_database[k]-48)*mult;
                    }
                string arr[nod];
                for(int l=nod-1;l>=0;l--)
                    {
                        arr[l] = (num%10 + 48);
                        num/=10;
                    }
                for(int l=0;l<nod;l++)
                    in_database += arr[l];

                Database.push_back(in_database);
                cout<<in_database<<"\n";
            }

        }
    vector_printer(input,Database);
    }

    return 0;
}

