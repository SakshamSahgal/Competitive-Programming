#include<iostream>
#include<string>
using namespace std;

class Exam
{
    string EName;
    string Date;
    string Ccode[2];
    float Score[2];
public:
    void get_Data()
    {
        try
        {
            cout<<"\n--------------------------------\n";
            cout<<"Enter Exam Name : ";
            cin>>EName;

            if( EName != "T1" && EName != "T2" && EName != "Endsem")
                throw 1;

            cout<<"Enter date in MM/DD/YYYY : ";
            cin>>Date;
            if(Date.length() != 10 || Date[2] != '/' || Date[5] != '/')
                throw 2;
            cout<<"\n";
            cout<<"Enter Course Code for first subject: ";
            cin>>Ccode[0];
            cout<<"Enter Your Score for this subject : ";
            cin>>Score[0];
             cout<<"\n";
            cout<<"Enter Course Code for second subject: ";
            cin>>Ccode[1];
            cout<<"Enter Your Score for this subject : ";
            cin>>Score[1];
             cout<<"\n";
            if( ((EName == "T1" || EName == "T2") && Score[0] > 20)  || (EName  == "Endsem" && Score[1] > 40) )
                throw 3;
            cout<<"\n--------------------------------\n";
        }
        catch(int x)
        {
            if(x == 1)
                cout<<"Wrong Exame name \n";
            if(x == 2)
                cout<<"Wrong date format \n ";
            if(x == 3)
                cout<<"Marks entered are greater than max marks \n";
        }

    }
    void Print()
    {
        cout<<"\n--------------------------------\n";
        cout<<"Enter Exam Name : "<<EName<<"\n";
        cout<<"Enter date in MM/DD/YYYY : "<<Date<<"\n";
        cout<<"Enter Course Code : "<<Ccode[0]<<"\n";
        cout<<"Enter Your Score : "<<Score[0]<<"\n";
        cout<<"Enter Course Code : "<<Ccode[1]<<"\n";
        cout<<"Enter Your Score : "<<Score[1]<<"\n";
        cout<<"\n--------------------------------\n";
    }
};
int main()
{
    Exam lists[3];
    for(int i=0; i<3; i++)
    {
        lists[i].get_Data();
    }
    for(int i=0; i<3; i++)
    {
        lists[i].Print();
    }
    return 0;
}
