#include<iostream>
#include<cmath>
using namespace std;

class Newton
{    double epsilon,result;
public:
     virtual double fun(double x)=0;  //  ！！！！注意这里函数声明为纯虚函数
     Newton(double ep=0.00001)
     {  
	//补充构造函数
	 }
     void root()
     {   
	//补充函数求根，利用说明中的递推函数，调用fun，按照精度要求把结果存入result

      }
//补充其他必要函数  
};


class Myroot:public Newton
{
    public:
       Myroot(double ra):Newton(ra){ };

//补充其他必要函数
};

int main()
{
   Myroot a1(0.0000001);
   Newton *s=&a1;
   s->root();   
   s->Print();
   return 0;
}
