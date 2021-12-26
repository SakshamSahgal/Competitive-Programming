#include <iostream>
#include <string>
using namespace std;
class A
{
int a, b;
float d;
public:
void change(int i){
a = i;
}
void value_of_a(){
cout<<a;
}
};
class B: private A
{
};
int main(int argc, char const *argv[])
{
B b;
cout<<sizeof(B);
return 0;
}
