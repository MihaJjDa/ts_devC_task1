#include <iostream>
#include <vector>
#include "longLongLong.h"

using namespace std;

void test()
{
  longLongLong s("-12345678901234567890");
  longLongLong i(-1234567890);
  longLongLong l(s);
  longLongLong s1("-22345678901234567890");
  longLongLong inc1("-123456789");
  longLongLong inc2("10000");
  longLongLong inc3(0);
  longLongLong inc4("-9999");
  s.print();
  i.print();
  l.print();
  cout << (s == l) << (s != i) << (s < s1) << (s > s1) << (s <= s1) << (s >= s1);
  cout << endl;
  (inc1.operator++(1)).print();
  (inc2.operator++(1)).print();
  (inc3.operator--(1)).print();
  (inc4.operator--(1)).print();
  inc1.print();
  inc2.print();
  inc3.print();
  inc4.print();
  cout << (s[9]) << endl;
  inc1 = longLongLong(1234);
  inc1.print();
}

int main()
{
  test();
  return 0;
}
