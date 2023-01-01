#include "student.hpp"
#include <iostream>
using namespace std;

int main() {
  Student StuArray1[10] = {Student(61525101, "A1", 72, 79, 76),
                           Student(61525102, "B1", 81, 89, 80),
                           Student(61525103, "C1", 95, 98, 91),
                           Student(61525104, "D1", 100, 100, 100)};

  Student StuArray2[10] = {
      Student(61525201, "A2", 60, 70, 71), Student(61525202, "B2", 80, 79, 80),
      Student(61525203, "C2", 82, 92, 81), Student(61525204, "D2", 99, 99, 99),
      Student(61525205, "E2", 60, 70, 99)};

  SeuClass class1(StuArray1, 4);
  SeuClass class2(StuArray2, 5);
  cout << "一班最高平均分：" << class1.get_maxavg() << endl;
  cout << "二班最高平均分：" << class2.get_maxavg() << endl;
  cout << endl;

  cout << "测试添加同学功能:" << endl;
  Student e1(61516105, "E1", 97, 96, 95);
  cout << "添加学生：" << endl;
  e1.Print();
  class1.append(e1);
  cout << "添加成功" << endl;
  cout << endl;

  cout << "测试查询功能：" << endl;
  cout << "在1班里查找D2" << endl;
  class1.query("D2").Print();
  cout << endl;
  cout << "在1班里查找新添加的E1" << endl;
  class1.query("E1").Print();
  cout << endl;
  class1.sort();

  return 0;
}
