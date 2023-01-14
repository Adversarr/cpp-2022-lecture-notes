#include<iostream>
#include<cmath>
using namespace std;



class Client{
public:
	int id;               //客户号
	char name[20];        //客户姓名
	double  score;        //积分（每消费100元累计1积分）

	Client();  //缺省构造函数，（ID和积分缺省值为0， 名字为空。）
	Client(int nID, const char *str);  //构造函数用实参值为数据成员赋值。）

	void set(int nID, const char *str);  //修改客户姓名，客户号
	char * getname();         //返回客户姓名

	virtual void consume(double n);     //客户消费，每满100元累计一个积分
	virtual void display();        //输出对象的全部数据

};

Client::Client() {
	id = name[0] = 0;
	score = 0;
}

Client::Client(int nID, const char *str) {
//补充必要代码
  id = nID;
  assert(strlen(str) < 20);
  strcpy(name, str);
  score = 0;
}


void Client::set(int nID, const char *str)
{
//补充必要代码
  id = nID;
  assert(strlen(str) < 20);
  strcpy(name, str);
}

char * Client::getname() {
	return name;
}

// 补充完成 display函数，能够输出客户 编号， 姓名，积分值
void Client::display() {
  std::cout << "Client [id="<< id << " name=" << name << " score=" << score << "]" << std::endl; 
}

// 补充完成 消费函数consume， 根据消费满100元获得1积分计算。
void Client::consume(double n) {
  score += 0.01 * n;
}


class VIPClient: public Client {
private:
	int validity;         // 有效期限
	double  discount;        //折扣率
public:
	VIPClient();  //缺省构造函数，（ID和积分缺省值为0， 名字为空。）

	void changeinfo(int vad,double d)  //修改客户有效期和打折率
	{
		validity = vad;
		discount = d;
	}
	int getvalidity ()        //返回有效期限
	{
		return validity;
	}
	// 补充函数 consume
	void consume(double n) { score += n * .02;}     //客户VIP消费，每满50元累计一个积分

	void display()        //输出对象的全部数据
	{
		cout << "VIP编号: " << id << " VIP姓名: " << name << " VIP积分: " << score <<" VIP 折扣"<<discount <<"  有效年："<<validity<< endl;
	}

};

VIPClient::VIPClient() 
{
	validity = 0;
	discount = 0;
}

// 补充函数，根据主函数调用的consumeandshow形式和功能，实现多态完成根据消费金额，计算积分和输出客户信息
// consumeandshow 形参为，传递客户对象和消费金额。
void consumeandshow(Client& client, double n) {
  client.consume(n);
  client.display();
}

int main(void)
{
	Client clientarray[2];
	VIPClient VIParray[2];
	
	int i;
	char name[20];
	int ID;
	double pay;
	int date;
	double discount;

	cout << "读入2名客户的名称、编号：" << endl;
	for( i=0; i<2; i++)
	{
		cin>>name>>ID; 
		clientarray[i].set(ID, name);
	}

	cout << "读入2名VIP客户的名称、编号、有效期，折扣率：" << endl;
	for( i=0; i<2; i++)
	{
		cin>> name>>ID>>date>>discount;
		VIParray[i].set(ID, name);
		VIParray[i].changeinfo(date,discount);
	}

	//普通客户和VIP客户各自消费1000元后，积分计算和信息输出
	for( i=0; i<2; i++)
		consumeandshow(clientarray[i], 1000);

	for( i=0; i<2; i++)
		consumeandshow(VIParray[i], 1000);
}
