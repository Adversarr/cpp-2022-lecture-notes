//利用动态存储顺序表类模板，定义多边形类CPolygon

#include <iostream>
#include <string>
using namespace std;

//-------------- 动态数组模板类 Array-----------------
template <typename T>class Array{
	T *elements;										//存储空间首地址
	int Subscript;										//已用最大下标值
	int maxSize;										//最大可存储元素个数
public:
	Array(int=2);										//缺省元素数为2
	Array(Array &arr);									//拷贝构造
	~Array();											//析构
	Array& operator=(Array &arr);						//赋值运算符重载
	bool IsFull() const{return Subscript==maxSize-1;}	//判断数组满
	void renews(int cap=10);							//存储空间在原来的基础上扩充cap大小的容量	
	void InsertRear(T&);								//将x插入数组尾部
	int Insert(T&, int pos);							//将x插入数组在下标pos位置
	void InitArray();									//清空数组
	int GetElemNum(){return Subscript+1;};				//返回数组已存储元素个数
	T& operator[](int i){return elements[i];};			//重载下标运算符[]

	template <typename T>
	friend ostream&operator<<(ostream &dist, Array<T> &ar);	//重载插入运算符
};


//构造函数
template <typename T> Array<T>::Array(int maxs){
	//添加代码
}

//拷贝构造函数
template <typename T>Array<T>::Array(Array<T> &arr){
	maxSize = arr.maxSize;	
	elements=new T[maxSize];
	Subscript = arr.Subscript;	
	for(int i=0;i<=Subscript;i++) elements[i] = arr.elements[i];
}

template <typename T> Array<T>::~Array(){
	delete[]elements;
}


template <typename T>Array<T>& Array<T>::operator=(Array<T> &arr){
	//添加代码
}

//存储空间在原来的基础上扩充cap大小的容量
template <typename T> void Array<T>::renews(int cap){
	int i;	
	T *temp = elements;
	maxSize = maxSize+cap;
	elements = new T[maxSize];
	for(i=0;i<=Subscript;i++) elements[i] = temp[i];
	delete[]temp;
}


template <typename T> void Array<T>::InsertRear(T & elem){				//插入尾部
	if(IsFull()) renews();
	elements[++Subscript] = elem;
}


//将x插入数组在下标pos位置:插入成功，返回1，否则返回0
template <typename T> int Array<T>::Insert(T&elem, int pos){	
	//添加代码

}

//清空线性表
template <typename T> void Array<T>::InitArray(){
	Subscript = -1;
}

//插入流操作符重载
template <typename T> ostream&operator<<(ostream&dist, Array<T>&ar){
	//添加代码
	
}


//---------点CPoint-----------
class CPoint{
	double x;							 //x坐标
	double y;							 //y坐标

public:
	CPoint(double dx=0, double dy=0):x(dx), y(dy){};
	void Get(double &dx, double &dy) const;
	void Set(double dx, double dy);
	double Distance(CPoint &p);
	
	friend ostream & operator<<(ostream &os, CPoint &s);
	friend istream & operator>>(istream &is, CPoint &s);
};


void CPoint::Get(double &dx, double &dy)const{
	dx=x; dy=y;
}


void CPoint::Set(double dx, double dy){
	x=dx; y=dy;
}


double CPoint::Distance(CPoint &p){
	double d=0.0;
	double x1,y1;
	p.Get(x1,y1);
	d = sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
	return d;
}

ostream & operator<<(ostream &os, CPoint &s)
{
	os << " (" << s.x << " , " << s.y << ") ";
	return os;
}


istream & operator>>(istream &is, CPoint &s){
	is >> s.x >> s.y ;
	return is;
}


//---------多边形CPolygon-----------
class CPolygon{
	Array<CPoint>	VexList;					//记录多边形顶点
	double	perimeter;							//多边形周长						
	
public:
	CPolygon();									//缺省构造函数，初始化数据成员
	CPolygon(CPolygon &sc);						//拷贝构造函数	
	void ShowPolygonInfo();						//显示多边形信息
	double CalPerimeter();						//计算多边形周长
	void AddVex(CPoint &p, int pos);			//将点p插入多边形第i顶点（顶点从0开始)
	void AddVex(CPoint p[],int len);			//将数组p中len个点加入多边形顶点
	int GetVexNum(){return VexList.GetElemNum();};//获得多边形顶点个数
};


CPolygon::CPolygon(){
	VexList.InitArray();	
	perimeter = 0.0;
}

//拷贝构造函数
CPolygon::CPolygon(CPolygon &s):VexList(s.VexList),perimeter(s.perimeter){};


//输出多边形信息
void CPolygon::ShowPolygonInfo(){
	cout << VexList.GetElemNum() << "边形：";
	//输出顶点信息
	cout << VexList;
	cout << endl;
	//输出周长
	cout << "周长: ";
	cout << perimeter << endl ;
}

//将点p插入多边形第i顶点（顶点从0开始)
void CPolygon::AddVex(CPoint &p, int pos){				
	VexList.Insert(p, pos);
	CalPerimeter();
}

//将数组p中len个点加入多边形顶点：逐个加入尾部
void CPolygon::AddVex(CPoint p[], int len){
	for (int i=0; i<len; i++)
		VexList.InsertRear(p[i]);
	CalPerimeter();
}

//计算多边形周长
double CPolygon::CalPerimeter(){
	//添加代码
	
}

int main(){	
	CPolygon gon;
	CPoint VexSet[]={CPoint(0,0),CPoint(1,0),CPoint(0,1)};
	gon.AddVex(VexSet, sizeof(VexSet)/sizeof(CPoint));	
	gon.ShowPolygonInfo();
	
	CPolygon gon1(gon);
	CPoint p(1,1);

	//添加代码：将点(1,1)加入到多边形gon1中顶点(1,0)之后

	cout << "插入点" << p << "后：" << endl;
	gon1.ShowPolygonInfo();
	return 0;
}
