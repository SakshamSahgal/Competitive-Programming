#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

struct Time
{
    usi hour;
    usi hour_first_digit;
    usi hour_second_digit;
    usi minute;
    usi min_first_digit;
    usi min_second_digit;
    bool reflected_correct;
    string time_in_string;
    string Reflected_time_in_string;
};

bool checker(usi x)
{
    if(x == 0 || x == 1 || x == 2 || x == 5 || x == 8)
        return 1;
    else
        return 0;
}

usi Reflected(usi x)
{
    if(x == 0 || x == 1 || x == 8)
        return x;
    if(x == 2)
        return 5;
    if(x == 5)
        return 2;
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
        string s;
        usi h,m;
        cin>>h>>m;
        cin>>s;
        usi HH = (s[0]-48)*10 + (s[1]-48);
        usi MM = (s[3]-48)*10 + (s[4]-48);
        //cout<<"---"<<HH<<" "<<MM<<"\n";
        usi reflected_H = Reflected(s[4]-48)*10 + Reflected(s[3]-48);
        usi reflected_M = Reflected(s[1]-48)*10 + Reflected(s[0]-48);
        if(checker(s[0]-48) == 1 && checker(s[1]-48) == 1  && checker(s[3]-48) == 1  && checker(s[4]-48) == 1 && reflected_H < h && reflected_M < m )
        {
            cout<<s<<"\n";
        }
        else
        {
            Time Clock[h][m];
            for(int i=0; i<h; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(i<=9)
                    {
                        Clock[i][j].hour_first_digit=0;
                        Clock[i][j].hour_second_digit=i;
                        Clock[i][j].time_in_string += (Clock[i][j].hour_first_digit+48);
                        Clock[i][j].time_in_string += (Clock[i][j].hour_second_digit+48);
                    }
                    else
                    {
                        Clock[i][j].hour_first_digit=(i/10);
                        Clock[i][j].hour_second_digit= (i%10);
                        Clock[i][j].time_in_string += (Clock[i][j].hour_first_digit + 48);
                        Clock[i][j].time_in_string += (Clock[i][j].hour_second_digit + 48);
                    }


                    Clock[i][j].time_in_string += ":";

                    if(j<=9)
                    {
                        Clock[i][j].min_first_digit=0;
                        Clock[i][j].min_second_digit=j;
                        Clock[i][j].time_in_string += (Clock[i][j].min_first_digit+48);
                        Clock[i][j].time_in_string += (Clock[i][j].min_second_digit+48);
                    }
                    else
                    {

                        Clock[i][j].min_first_digit=(j/10);
                        Clock[i][j].min_second_digit=(j%10);

                        Clock[i][j].time_in_string += (Clock[i][j].min_first_digit + 48);
                        Clock[i][j].time_in_string += (Clock[i][j].min_second_digit + 48);
                    }


                    Clock[i][j].hour =  Clock[i][j].hour_first_digit*10 + Clock[i][j].hour_second_digit;
                    Clock[i][j].minute =  Clock[i][j].min_first_digit*10 + Clock[i][j].min_second_digit;

                    if( checker(Clock[i][j].hour_first_digit) == 1 && checker(Clock[i][j].hour_second_digit) == 1  && checker(Clock[i][j].min_first_digit) == 1 && checker(Clock[i][j].min_second_digit) == 1 )
                    {
                        //cout<<"yes for "<<i<<":"<<j<<" ";
                        usi reflected_Hour = Reflected(Clock[i][j].min_second_digit)*10 + Reflected(Clock[i][j].min_first_digit);
                        usi reflected_Min = Reflected(Clock[i][j].hour_second_digit)*10 + Reflected(Clock[i][j].hour_first_digit);

                        if(reflected_Hour < h && reflected_Min<m  )
                        {
                            Clock[i][j].reflected_correct = 1;
                            if(reflected_Hour<=9)
                            {
                                Clock[i][j].Reflected_time_in_string+= '0';
                                Clock[i][j].Reflected_time_in_string+=(reflected_Hour+48);

                            }
                            else
                            {
                                Clock[i][j].Reflected_time_in_string += ((reflected_Hour/10) + 48);
                                Clock[i][j].Reflected_time_in_string += ( (reflected_Hour%10) + 48);
                            }


                            Clock[i][j].Reflected_time_in_string += ":";

                            if(reflected_Min<=9)
                            {
                                Clock[i][j].Reflected_time_in_string+= '0';
                                Clock[i][j].Reflected_time_in_string+=(reflected_Min+48);
                            }
                            else
                            {

                                Clock[i][j].Reflected_time_in_string += ((reflected_Min/10) + 48);
                                Clock[i][j].Reflected_time_in_string += ( (reflected_Min%10) + 48);
                            }
                        }

                        else
                            Clock[i][j].reflected_correct = 0;
                    }
                    else
                        Clock[i][j].reflected_correct = 0;





                    /*if(Clock[i][j].reflected_correct == 1)
                        cout<<"|"<<Clock[i][j].hour_first_digit<<Clock[i][j].hour_second_digit<<":"<<Clock[i][j].min_first_digit<<Clock[i][j].min_second_digit<<"| "<<Clock[i][j].time_in_string<<" reflected to = "<<Clock[i][j].Reflected_time_in_string<<"|"<<Clock[i][j].reflected_correct<<"|\n";
                    else
                        cout<<"|"<<Clock[i][j].hour_first_digit<<Clock[i][j].hour_second_digit<<":"<<Clock[i][j].min_first_digit<<Clock[i][j].min_second_digit<<"| "<<Clock[i][j].time_in_string<<"|"<<Clock[i][j].reflected_correct<<"|\n"<<"\n";
                    */

                }
                //cout<<"\n-----\n";
            }

            for(usi i = HH; i<=HH; i++)
            {
                for(usi j= MM; j<m; j++)
                {
                    if(Clock[i][j].reflected_correct == 1 )
                    {
                        cout<<Clock[i][j].time_in_string<<"\n";
                        goto z;
                    }
                }

            }


            for(usi i = HH+1; i<h; i++)
            {
                for(usi j=0; j<m; j++)
                {
                    if(Clock[i][j].reflected_correct == 1 )
                    {
                        cout<<Clock[i][j].time_in_string<<"\n";
                        goto z;
                    }
                }

            }

            for(usi i=0; i<h; i++)
            {
                for(usi j=0; j<m; j++)
                {
                    if(Clock[i][j].reflected_correct == 1 )
                    {
                        cout<<Clock[i][j].time_in_string<<"\n";
                        goto z;
                    }
                }

            }
        }

z:
        t--;
    }

    return 0;
}

