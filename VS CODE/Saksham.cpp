#include<iostream>
#include<string.h>
using namespace std;
struct Book
{
int number;
char name[20];
float cost;
};

int main()
{
  Book b3;
  Book b1 = {2,"saksham",12.4};
  Book b2 = {3,"saksham2",13.5};
  cout<<b2.name;
  strcpy(b2.name,"saksham hehe");
    cout<<"\n"<<b2.name;
    b3 = b2;

    cout<<"\n"<<b3.name;
  return 0;  
}