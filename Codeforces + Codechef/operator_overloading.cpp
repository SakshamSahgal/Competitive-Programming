#include<iostream>
using namespace std;
class Complex
{
int r;
int i;

public:
    void setdata(int x,int y)
    {
      r = x;
      i = y;
    }
    void display()
    {
        cout<<r<<"+ i("<<i<<")\n";
    }
    Complex operator +(Complex C)
    {
        Complex temp;
        temp.r = r + C.r;
        temp.i = i + C.i;
        return temp;
    }
    Complex operator *(Complex C)
    {
        Complex temp;
        temp.r = r*C.r - i*C.i;
        temp.i = r*C.i + i*C.r;
        return temp;
    }
    Complex operator -(Complex C)
    {
        Complex temp;
        temp.r = r - C.r;
        temp.i = i - C.i;
        return temp;
    }
    Complex operator -()
    {
        Complex temp;
        temp.r = -r;
        temp.i = -i;
        return temp;
    }
    Complex operator ++()
    {
        Complex temp;
        temp.r = ++r;
        temp.i = ++i;
        return temp;
    }
    Complex operator --()
    {
        Complex temp;
        temp.r = --r;
        temp.i = --i;
        return temp;
    }
};
int main()
{
Complex c1,c2,c3;
c1.setdata(1,2);
c2.setdata(3,4);
c3 = c1*c2; //c1.operator -(); //-c1;
c3.display();
c3 = c1+c2;
c3.display();
c3 = c1-c2;
c3.display();
c3 = -c1;
c3.display();
c3 = ++c1;
c3.display();
c3 = --c1;
c3.display();
return 0;
}

