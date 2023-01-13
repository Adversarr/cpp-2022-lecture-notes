#include<iostream>
#include<cmath>
#include "string"
using namespace std;


#define MAX 20

class ANNCell
{
	double x[MAX], w[MAX];  // 数组存储神经元的输入节点值Xi，以及此输入节点的权重Wi,
	double bias;           // 神经元的偏置值
	double y;              // 根据输入节点Xi和权重Wi、偏置，计算得到的加权输入和
	int numofinput;        // 神经元的输入节点总数
	double output;         // 神经元的最终输出值

public:
	//用数组in初始化输入X，weight初始化加权系统W，用num初始化输入节点总数numofinput，b初始化偏置值。
	ANNCell(double in[],double weight[], int num, double b);
	virtual double fun(double y)=0; // 根据加权输入和计算神经元输出的函数定义。
	virtual ~ANNCell(){}
	void calculate();               // 计算神经元最终输出函数
	void print();                   //输出输入信号和最终输出信号的值
};

class Sigmoid:public ANNCell
{
public:
	Sigmoid(double in[],double weight[], int num, double b):ANNCell( in, weight,  num,  b)
	{
	}
	~Sigmoid(){}
	double fun(double y)
	{
//完善代码
	}
};


class Tanh:public ANNCell
{
public:
	Tanh(double in[],double weight[], int num, double b):ANNCell( in, weight,  num,  b)
	{
	}
	~Tanh(){}
	double fun(double y)
	{ // 完善代码

	}
};

int main(){

	double a[5]={0.2, 0.1};
	double b[5]={2, 3};
	ANNCell *p= new Sigmoid(a,b,2, -1);
	p->print();
	delete p;

	double c[5]={0.6, 0.5, 0.2, 0.3, 0.5};
	double d[5]={2, 3, 2, 3, 1};
	p= new Tanh(c,d,5, -3);
	p->print();
	delete p;
}

ANNCell::ANNCell(double in[],double weight[], int num, double b)
{
//完善代码

}

void ANNCell::calculate()
{
//完善代码
}


void ANNCell::print(){
	int i;
	calculate();
	cout<<"x[i]=";
	for(i=0;i<numofinput;i++)
		cout<<x[i]<<", ";
	cout<<endl;
	cout<<"y="<<y<<endl;
	cout<<"output="<<output<<endl;

}
