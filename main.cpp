#include <iostream>
#include <vector>
#include <string>
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

bool isNumber(string s)
{
  bool res = true;
  int i = 0;
  while (res && i < s.length())
  {
    res = (s[i] == '0') || (s[i] == '1') || (s[i] == '2') || (s[i] == '3') || (s[i] == '4') ||
          (s[i] == '5') || (s[i] == '6') || (s[i] == '7') || (s[i] == '8') || (s[i] == '9');
    ++i;
  }
  return res;
}

longLongLong execute(string s)
{
  if (s[0] == '(' && s[s.length()-1] == ')')
  {
    return execute(s.substr(1, s.length()-2));
  }
  if (s.find("operator++") != string::npos)
  {
    return (execute(s.substr(0, s.length()-14))).operator++(1);
  }
  if (s.find("operator--") != string::npos)
  {
    return (execute(s.substr(0, s.length()-14))).operator--(1);
  }
  if (s.find("++") == 0)
  {
    return ++(execute(s.substr(2)));
  }
  if (s.find("--") == 0)
  {
    return --(execute(s.substr(2)));
  }
  else if (s.find("longLongLong") == 0)
  {
    return execute(s.substr(12));
  }
  else if (isNumber(s))
  {
    return longLongLong(s);
  }
  else
    return longLongLong();
}

int main()
{
  string s;
  cin >> s;
  execute(s).print();
  ((longLongLong("12345678")).operator++(1)).print();
  return 0;
}
