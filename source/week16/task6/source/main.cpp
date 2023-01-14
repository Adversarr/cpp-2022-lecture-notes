#include "string"
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

// 判断数组内容是否为从大到小排序的函数模板  isDecSorted

// 图书类
class CBook {

  string bookname;   // 书名
  string bookauthor; // 作者
  char *description; // 简介
  int lendingtimes;  // 借出次数，借阅量
public:
  CBook(string name, string author, const char *des, int times)
      : bookname(name), bookauthor(author), description(strdup(des)),
        lendingtimes(times) {
    // 添加代码
  }

  ~CBook() {
    if (description)
      delete[] description;
  }
  CBook() {
    description = new char[20];
    description[0] = '\0';
    bookauthor = "";
    bookname = "";
    lendingtimes = 0;
  }

  // 完成必要的构造函数
  CBook(const CBook &s) {
    // 完成复制构造函数
    bookname = s.bookname;
    bookauthor = s.bookauthor;
    description = new char[strlen(s.description) + 1];
    strcpy(description, s.description);
    lendingtimes = s.lendingtimes;
  }

  void setinfo(string name, string author, const char *des, int times) {
    //  完成重新设置图书信息的函数  完成代码
    bookname= name;
    bookauthor = author;
    delete[] description;
    description = strdup(des);
    lendingtimes = times;
  }

  void getinfo(string &name, string &au, char *des, int &num) {
    // 完成代码
    name = bookname;
    au = bookauthor;
    des = description;
    num = lendingtimes;
  }

  void print() {
    cout << "书名：" << bookname << "  作者：" << bookauthor << "  借阅次数："
         << lendingtimes << endl;
    cout << description << endl;
  }

  // 完成必要的运算符重载支持判断有序的函数模板
  bool operator< (const CBook& rhs)const {
    return lendingtimes < rhs.lendingtimes;
  }
  bool operator> (const CBook& rhs)const {
    return lendingtimes > rhs.lendingtimes;
  }
};

bool isDecSorted(const CBook* book_array, int n) {
  for (int i = 1; i < n; ++i) {
    if (book_array[i] > book_array[i - 1]) {
      return false;
    }
  }
  return true;
}

int main() {

  int i;
  CBook bookarray[5] = {
      CBook("一句顶一万句", "刘震云", "底层百姓人物的故事", 200),
      CBook("蛙", "莫言", "乡村女医生的人生经历", 180),
      CBook("推拿", "毕飞宇", "推拿中心盲人的情感、尊严和梦想", 170),
      CBook("你在高原", "张炜", "地质队员的故事", 160),
      CBook("天行者", "刘醒龙", "乡村民办教师的故事", 150),
  };

  for (i = 0; i < 5; i++) {
    bookarray[i].print();
  }

  if (isDecSorted(bookarray, 5))
    cout << "已经按借阅量排序" << endl;
  else
    cout << "没有按借阅量排序" << endl;

  CBook book1;
  book1.setinfo("人世间", "梁晓声", "描写了中国社会的巨大变迁和百姓生活", 150);

  CBook book2 = book1;
  book2.print();

  return 0;
}
