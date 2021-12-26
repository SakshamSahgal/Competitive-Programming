#include<iostream>
using namespace std;
//32 bit CPU Cycle -> 4 byte
//32 bit CPU Cycle -> 8 byte
struct abc
{
char a; //1
char b; //1
int c; //4
};
struct def
{
char a; //1
int c; //4
char b; //1
};
struct ghi
{
int a; //4
int b; //4
int c; //4
};
struct jkl
{
char a; //1
float b; //4
int c; //4
};
int main()
{
cout<<sizeof(abc)<<"\n";
cout<<sizeof(def)<<"\n";
cout<<sizeof(ghi)<<"\n";
cout<<sizeof(jkl)<<"\n";
}

