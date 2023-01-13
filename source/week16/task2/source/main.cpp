// Exam1.cpp : 定义控制台应用程序的入口点。
//定义本科生类并派生研究生类，，创建对象读入信息，利用多态进行毕业审核

#include <iostream>
#include <string>
using namespace std;

/*---------封装本科生类-----------*/
class UStudent
{
	string strId;                //学号
	string strName;              //姓名
	double dCredits;             //已修学分
	bool   bResult;              //毕业审核结果
public:
	UStudent(string = "", string = "", double = 0);     //构造函数，初始化学号、姓名及学分
	void SetUStu(string id, string name, double cred);  //修改3个基本信息
	double GetCredits() { return dCredits; }            //获取学分   
	string GetId() { return strId; }                    //获取学号
	string GetName() { return strName; }                //获取姓名
	void SetResult(bool res){ bResult = res; }          //设置审核结果
	bool GetResult(){ return bResult; }                 //获取审核结果
	virtual void Check();                               //学籍审核，虚函数用以支持多态
	virtual void Print();                               //输出全部信息，虚函数与统一支持多态
}; 

/*----------由本科生派生研究生类----------*/
class GStudent : public UStudent
{
	bool bTeaching, bResearch;                               //增加成员：教学实践和科研实践考核结果，通过与否
public:              
	//添加代码，补充必要成员函数                       
};

/*--------定义UStudent类成员函数-----------*/
UStudent::UStudent(string id, string name, double cred)      //构造函数
{
	strId = id;
	strName = name;
	dCredits = cred;
}

void UStudent::SetUStu(string id, string name, double cred)  //修改基本信息
{
	strId = id;
	strName = name;
	dCredits = cred;
}

void UStudent::Check()                                        //毕业审核
{
	//添加代码
  bResult = dCredits > 160.0;
}
void UStudent::Print()                                        //输出所有信息
{
	cout << strId << "  " <<  strName << "  " << dCredits << "  " << bResult << endl;
}

/*-------定义GStudent类成员函数-------*/
//添加代码，定义类中的成员函数，包括构造函数，修改成员数据、重构毕业审核及输出信息


//添加代码：定义统一接口GraduationCheck函数，实现运行时多态，对不同对象进行毕业审核。
void GraduationCheck(const UStudent& stu) {
}

//添加代码：定义统一接口Display函数，实现运行时多态，支持不同对象的信息输出。

//对以上函数的提示：使用基类指针或基类引用，作为操作对象的参数，并调用基类的虚函数

int main()
{
	UStudent ustu[3];                     //本科生数组
	GStudent gstu[2];                     //研究生数组
	int i;
	string id, name;                      //变量用于保存学号姓名
	double cred;                          //变量用于保存学分
	bool teach, research;                 //变量用于保存教学实践与科研实践考核结果
	cout << "读入3名本科生学号、姓名及已修学分,并进行审核：" << endl;
	for (i = 0; i < 3; i++)
	{
		cin >> id >> name >> cred;
		ustu[i].SetUStu(id, name, cred);  //创建本科生对象并使其获得信息
		GraduationCheck(&ustu[i]);        //实现对本科生对象的审核
	}
	cout << endl;
	cout << "读入2名研究生学号、姓名已修学分、教学、科研考核结果，并审核：" << endl;
	for (i = 0; i < 2; i++)
	{
		cin >> id >> name >> cred >> teach >> research;;
		gstu[i].SetGStu(id, name, cred, teach,research);     //创建研究生对象并使其获得信息
		GraduationCheck(&gstu[i]);                           //实现对研究生对象的审核
	}

	cout << endl;
	cout << "输出本科生信息及审核结果：" << endl;
	for (i = 0; i < 3; i++)                                 //调用统一接口输出本科生信息
		Display(ustu[i]);
	
	cout << endl;
	cout << "输出研究生信息及审核结果：" << endl; 
	for (i = 0; i < 2; i++)                                 //调用统一接口输出研究生信息
		Display(gstu[i]);

	system("pause");
	return 0;
}
