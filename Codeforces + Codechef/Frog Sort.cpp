#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
struct Frog
    {
    vector<usi> indexes;
    usi weight;
    usi jump;
    };
void bubble_sort(struct Frog f[],int n)
    {
		struct Frog temp;
		bool checker = 0;
		for(usi i=1;i<n;i++)
		{
			checker = 0;
			for(usi j=0;j<=(n-1-i);j++)
			{
					if(f[j].weight>f[j+1].weight)
						{
							checker = 1;
							temp = f[j];
							f[j] = f[j+1];
							f[j+1] = temp;
						}
			}
			if(checker == 0)
				break;
		}
    }
void printer(struct Frog f[],usi n)
    {
        for(usi i=0;i<n;i++)
            {
                cout<<"f["<<i<<"]"<<"\n";
                cout<<"weight = "<<f[i].weight<<"\n";
                cout<<"Jump = "<<f[i].jump<<"\n";

                for(usi j=0;j<f[i].indexes.size();j++)
                    {
                    cout<<f[i].indexes[j]<<" ";
                    }
                cout<<"\n";
            }

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
    struct Frog f[n];
    for(usi i=0;i<n;i++)
        cin>>f[i].weight;

    for(usi i=0;i<n;i++)
        {
        cin>>f[i].jump;

        for(usi j=i;j<=(n+4);j+=f[i].jump)
            {
                //cout<<j<<" ";
                f[i].indexes.push_back(j);
            }
        //cout<<"size = "<<f[i].indexes.size()<<"\n";
        }
    //printer(f,n);
    bubble_sort(f,n);
    //printer(f,n);
    int mini = -1;
    int counter = 0;
    for(usi i=0;i<n;i++)
        {
            for(usi j=0;j<f[i].indexes.size();j++)
                {
                    if(f[i].indexes[j] > mini)
                        {
                            mini = f[i].indexes[j];
                            break;
                        }
                    else
                        counter++;
                }
        }
    cout<<counter<<"\n";
    t--;
    }
return 0;
}

