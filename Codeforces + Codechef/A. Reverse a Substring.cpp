#include<iostream>
#include<algorithm>
#include<cstring>
#define ui unsigned int
using namespace std;

void reverser(char input[],char reversed[],ui its_size)
{
for(ui i=0;i<its_size;i++)
    {
        reversed[i] = input[its_size-1-i];
    }
}
int main()
{
ui n;
cin>>n;
char ch[n];
for(ui i=0;i<n;i++)
    cin>>ch[i];
//cout<<"\n";
for(ui starting_point=0;starting_point<n;starting_point++)
    {
        for(ui ending_point=starting_point;ending_point<n;ending_point++)
            {
                char rev[ending_point-starting_point+1];
                char input[ending_point-starting_point+1];

                for(ui i=starting_point,j=0;i<=ending_point;i++,j++)
                    {
                        input[j] = ch[i];
                        //cout<<input[j];
                    }

                    reverser(input,rev,(ending_point-starting_point+1));
                  // cout<<" == ";


                //for(ui i=0;i<(ending_point-starting_point+1);i++)
                        //cout<<rev[i];

                if(strcmp(input,rev) == 1)
                    {
                    cout<<"YES\n";
                    cout<<(starting_point+1)<<" "<<(ending_point+1)<<"\n";
                    goto z;
                    }
                //cout<<"\n";
            }
    }
cout<<"NO\n";
z:
return 0;
}
