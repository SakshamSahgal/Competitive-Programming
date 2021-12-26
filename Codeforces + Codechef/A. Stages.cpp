#include<iostream>
using namespace std;
int main()
{
unsigned short int n,k;
cin>>n>>k;
char c[n];
for(int i=0;i<n;i++)
    cin>>c[i];
if(n==1 && k ==1)
    {
    cout<<(c[0]-96);
    return 0;
    }

else
    {
                 char temp;
                bool check=1;

                for(unsigned int i=1;i<n;i++)
                {
                    check = 0;
                    for(unsigned int j=0;j<=(n-1-i);j++)
                    {
                    //cout<<"\ncomparison btw "<<(c[j]-96)<<" & "<<(c[j+1]-96)<<"\n";
                        if(((int)c[j]-96)>((int)c[j+1]-96))
                            {
                                temp = c[j];
                                c[j] = c[j+1];
                                c[j+1] = temp;
                                check = 1;
                            }

                    }

                    if(check == 0)
                    break;
                }

            if(k==1)
                {
                cout<<(c[0]-96);
                return 0;
                }

            //cout<<"sorted array = \n";
//for(unsigned int i=0;i<n;i++)
    //cout<<c[i];
//cout<<"\n";


unsigned int counter = 1;
unsigned int weight = ((int)c[0]-96);
bool done = 0;
for(unsigned int i=1,j=0;i<n;i++)
    {
        //cout<<"comparison between "<<((int)c[i]-96)<<" & "<<( ((int)c[j]-96)+1 )<<"weight of c[i] = "<<(c[i]-96)<<"\n";
        if( ( (int)c[i]-96 ) > ( ((int)c[j]-96)+1 ) )
        {
            j = i;
            weight+=((int)c[i]-96);
            counter++;
        }
     //cout<<"weight in i = "<<i<<" & "<<"j == "<<j<<" "<<" is weight "<<weight<<"counter = "<<counter<<" "<<"\n";
    if(counter >= k)
        {
            done = 1;
            break;
        }

    }
if(done == 1)
    {
    cout<<weight;
    }
else
    cout<<"-1";























    }

//cout<<"ascii numbers = \n";
//for(unsigned int i=0;i<n;i++)
    //cout<<(int)c[i]<<" ";


return 0;
}
