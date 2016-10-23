#include <vector>
#include <string>

using namespace std;

typedef unsigned short ushort;

class longLongLong
{
    vector<ushort> digits;
    short sign;
  public:
    longLongLong();
    longLongLong(const long long x);
    longLongLong(const string s);
    longLongLong(const longLongLong& a);
    longLongLong operator++ ();
    longLongLong operator-- ();
    longLongLong operator++ (int);
    longLongLong operator-- (int);
    ushort operator[] (const long long a) const;
    //longLongLong operator+ ();
    //longLongLong operator- ();
    //longLongLong operator! ();
    //longLongLong operator~ ();
    //longLongLong operator* (const longLongLong& a) const;
    //longLongLong operator/ (const longLongLong& a) const;
    //longLongLong operator% (const longLongLong& a) const;
    //longLongLong operator<< (const longLongLong& a) const;
    //longLongLong operator>> (const longLongLong& a) const;
    bool operator< (const longLongLong& a) const;
    bool operator> (const longLongLong& a) const;
    bool operator<= (const longLongLong& a) const;
    bool operator>= (const longLongLong& a) const;
    bool operator== (const longLongLong& a) const;
    bool operator!= (const longLongLong& a) const;
    //longLongLong operator+ (const longLongLong& a) const;
    //longLongLong operator- (const longLongLong& a) const;
    //longLongLong operator& (const longLongLong& a) const;
    //longLongLong operator^ (const longLongLong& a) const;
    //longLongLong operator| (const longLongLong& a) const;
    //longLongLong operator&& (const longLongLong& a) const;
    //longLongLong operator|| (const longLongLong& a) const;
    longLongLong operator= (const longLongLong& a);
    //longLongLong operator+= (longLongLong a);
    //longLongLong operator-= (longLongLong a);
    //longLongLong operator*= (longLongLong a);
    //longLongLong operator/= (longLongLong a);
    //longLongLong operator%= (longLongLong a);
    //longLongLong operator<<= (longLongLong a);
    //longLongLong operator>>= (longLongLong a);
    //longLongLong operator&= (longLongLong a);
    //longLongLong operator^= (longLongLong a);
    //longLongLong operator|= (longLongLong a);
    void print();
    ~longLongLong();
};
