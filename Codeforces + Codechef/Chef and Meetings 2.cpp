#include<iostream>
#include<algorithm>
#include<string>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
struct
{
int HH;
int MM;
bool m;
}Time[24][60];

void printer()
{
for(usi i=0;i<24;i++)
    {
        for(usi j=0;j<60;j++)
            {
                if(Time[i][j].m == 0)
                cout<<Time[i][j].HH<<":"<<Time[i][j].MM<<" AM ";
                else
                cout<<Time[i][j].HH<<":"<<Time[i][j].MM<<" PM ";
            }
    cout<<"\n---------------------------------------------------------------------------------------------------------------\n";
    }
}

int checker(int LI,int RI,int LJ,int RJ,int PHH,int PMM,int m)
    {
        if(LI == RI)
            {
                for(usi i=LI;i<=RI;i++)
                {
                    for(usi j=LJ;j<=RJ;j++)
                    {
						if(Time[i][j].HH == PHH && Time[i][j].MM == PMM && Time[i][j].m == m)
						return 1;
                    }
                }
            }
        else
            {
                for(usi i=LI;i<=RI;i++)
                    {
                            if(i == LI)
                                {
                                     for(usi j=LJ;j<=59;j++)
                                        {
                                           if(Time[i][j].HH == PHH && Time[i][j].MM == PMM && Time[i][j].m == m)
                                                return 1;
                                        }
                                }
							else if(i == RI)
							{
								for(usi j=0;j<=RJ;j++)
                                        {
											if(Time[i][j].HH == PHH && Time[i][j].MM == PMM && Time[i][j].m == m)
                                                return 1;
										}
							}
						else
						{
							for(usi j=0;j<=59;j++)
                                        {
                                           if(Time[i][j].HH == PHH && Time[i][j].MM == PMM && Time[i][j].m == m)
                                                return 1;
                                        }
						}

                    }

            }
	return 0;
    }
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
for(usi i=0;i<12;i++)
    {
        if(i==0)
            {
                for(usi j=0;j<60;j++)
                    {
                        Time[i][j].HH = 12;
                        Time[i][j].MM = j;
                        Time[i][j].m = 0;

                        Time[i+12][j].HH = 12;
                        Time[i+12][j].MM = j;
                        Time[i+12][j].m = 1;
                    }
            }
        else
            {
                for(usi j=0;j<60;j++)
                    {
                        Time[i][j].HH = i;
                        Time[i][j].MM = j;
                        Time[i][j].m = 0;

                        Time[i+12][j].HH = i;
                        Time[i+12][j].MM = j;
                        Time[i+12][j].m = 1;
                    }
            }
    }

usi t;
cin>>t;
cin.ignore(256, '\n');
while(t)
    {
    usi n;
    string S;
    getline(cin,S);
	int PHH,PMM;
	bool m;
	PHH = (S[0]-48)*10+(S[1]-48);
	PMM = (S[3]-48)*10+(S[4]-48);
	if(S[6] == 'A')
		m = 0;
	else
		m = 1;

	//cout<<" "<<PHH<<" "<<PMM<<"\n";
    cin>>n;
    cin.ignore(256, '\n');
    string T[n];
    int LHH,RHH;
    int LMM,RMM;
    bool LM,RM;
    int LI,LJ,RI,RJ;

    for(usi i=0;i<n;i++)
        {
         getline(cin,T[i]);

         LHH = (T[i][0]-48)*10 + (T[i][1]-48);
         LMM = ((T[i][3]-48)*10) + (T[i][4]-48);
         if(T[i][6] == 'A')
         LM = 0;
         else
         LM = 1;

         RHH = (T[i][9]-48)*10 + (T[i][10]-48);
         RMM = (T[i][12]-48)*10 + (T[i][13]-48);
         if(T[i][15] == 'A')
         RM = 0;
         else
         RM = 1;

        //cout<<"LHH = "<<LHH<<" LMM = "<<LMM<<" LM = "<<LM<<" RHH = "<<RHH<<"RMM = "<<RMM<<" RM = "<<RM<<"\n";

        if(LM == 0)
            {
                if(LHH == 12)
                    LI = 0;
                else
                    LI = LHH;
            }
        else
            {
                if(LHH == 12)
                    LI = 12;
                else
                    LI = LHH + 12;

            }

        if(RM == 0)
            {
                if(RHH == 12)
                    RI = 0;
                else
                    RI = RHH;
            }
        else
            {
                if(RHH == 12)
                    RI = 12;
                else
                   RI = RHH + 12;

            }
        LJ = LMM;
        RJ = RMM;

        //cout<<"("<<LI<<","<<LJ<<")"<<" "<<"("<<RI<<","<<RJ<<")\n";
        cout<<checker(LI,RI,LJ,RJ,PHH,PMM,m);
		}
    cout<<"\n";
    t--;
    }
//printer();
return 0;
}
