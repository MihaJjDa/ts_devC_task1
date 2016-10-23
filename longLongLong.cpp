#include "longLongLong.h"
#include <iostream>
#include <cstdlib>

#include <vector>
#include <string>

#include <iostream>

longLongLong::longLongLong()
{
  digits.push_back(0);
  sign = 1;
}

longLongLong::longLongLong(const long long x)
{
  long long y = x;
  if (y >= 0)
    sign = 1;
  else
  {
    y = abs(y);
    sign = -1;
  }
  if (y == 0)
    digits.push_back(0);
  else
    while (y > 0)
    {
      digits.push_back(y % 10);
      y /= 10;
    }
}

longLongLong::longLongLong(const string s)
{
  int j = 0;
  if (s[0] == '-')
  {
    sign = -1;
    j = 1;
  }
  else
    sign = 1;
  for (int i = s.length()-1; i >= j; --i)
    digits.push_back(s[i]-'0');
}

longLongLong::longLongLong(const longLongLong& a)
{
  digits = a.digits;
  sign = a.sign;
}

longLongLong longLongLong::operator++ ()
{
  if (this->sign == 1)
  {
    bool adding = true;
    int i = 0;
    while (adding && i < this->digits.size())
    {
      if (this->digits[i] == 9)
      {
        this->digits[i] = 0;
        ++i;
      }
      else
      {
        ++(this->digits[i]);
        adding = false;
      }
    }
    if (i == this->digits.size())
      this->digits.push_back(1);
  }
  else
  {
    if (this->digits.size() == 1 && this->digits[0] == 1)
    {
      this->digits[0] = 0;
      this->sign = 1;
    }
    else
    {
      bool adding = true;
      int  i = 0;
      while (adding && i < this->digits.size())
      {
        if (this->digits[i] == 0)
        {
          this->digits[i] = 9;
          ++i;
        }
        else
        {
          --(this->digits[i]);
          adding = false;
        }
      }
      if (this->digits[i] == 0 && this->digits.size() == ++i)
        this->digits.pop_back();
    }
  }
  return *this;
}

longLongLong longLongLong::operator-- ()
{
  if (this->sign == 1)
  {
    if (this->digits.size() == 1 && this->digits[0] == 0)
    {
      this->digits[0] = 1;
      this->sign = -1;
    }
    else
    {
      bool adding = true;
      int  i = 0;
      while (adding && i < this->digits.size())
      {
        if (this->digits[i] == 0)
        {
          this->digits[i] = 9;
          ++i;
        }
        else
        {
          --(this->digits[i]);
          adding = false;
        }
      }
      if (this->digits[i] == 0 && this->digits.size() == ++i)
        this->digits.pop_back();
    }
  }
  else
  {
    bool adding = true;
    int i = 0;
    while (adding && i < this->digits.size())
    {
      if (this->digits[i] == 9)
      {
        this->digits[i] = 0;
        ++i;
      }
      else
      {
        ++(this->digits[i]);
        adding = false;
      }
    }
    if (i == this->digits.size())
      this->digits.push_back(1);
  }
  return *this;
}

longLongLong longLongLong::operator++ (int)
{
  longLongLong tmp(*this);
  ++(*this);
  return tmp;
}

longLongLong longLongLong::operator-- (int)
{
  longLongLong tmp(*this);
  --(*this);
  return tmp;
}

ushort longLongLong::operator[] (const long long a) const
{
  return this->digits[a];
}

bool longLongLong::operator< (const longLongLong& a) const
{
  bool res;
  if (this->sign == 1)
  {
    if (a.sign == 1)
    {
      if (this->digits.size() < a.digits.size())
        res = true;
      else if (this-> digits.size() > a.digits.size())
        res = false;
      else
      {
        res = false;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
          {
            res = true;
            lookingFor = false;
          }
          else if (this->digits[i] > a.digits[i])
            lookingFor = false;
          else
            --i;
        }
      }
    }
    else
    {
      res = false;
    }
  }
  else
  {
    if (a.sign == -1)
    {
      if (this->digits.size() < a.digits.size())
        res = false;
      else if (this-> digits.size() > a.digits.size())
        res = true;
      else
      {
        res = false;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
            lookingFor = false;
          else if (this->digits[i] > a.digits[i])
          {
            res = true;
            lookingFor = false;
          }
          else
            --i;
        }
      }
    }
    else
    {
      res = true;
    }
  }
  return res;
}

bool longLongLong::operator> (const longLongLong& a) const
{
  bool res;
  if (this->sign == 1)
  {
    if (a.sign == 1)
    {
      if (this->digits.size() < a.digits.size())
        res = false;
      else if (this->digits.size() > a.digits.size())
        res = true;
      else
      {
        res = false;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
            lookingFor = false;
          else if (this->digits[i] > a.digits[i])
          {
            res = true;
            lookingFor = false;
          }
          else
            --i;
        }
      }
    }
    else
    {
      res = true;
    }
  }
  else
  {
    if (a.sign == -1)
    {
      if (this->digits.size() < a.digits.size())
        res = true;
      else if (this->digits.size() > a.digits.size())
        res = false;
      else
      {
        res = false;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
          {
            res = true;
            lookingFor = false;
          }
          else if (this->digits[i] > a.digits[i])
            lookingFor = false;
          else
            --i;
        }
      }
    }
    else
    {
      res = false;
    }
  }
  return res;
}

bool longLongLong::operator<= (const longLongLong& a) const
{
  bool res;
  if (this->sign == 1)
  {
    if (a.sign == 1)
    {
      if (this->digits.size() < a.digits.size())
        res = true;
      else if (this-> digits.size() > a.digits.size())
        res = false;
      else
      {
        res = true;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
            lookingFor = false;
          else if (this->digits[i] > a.digits[i])
          {
            res = false;
            lookingFor = false;
          }
          else
            --i;
        }
      }
    }
    else
    {
      res = false;
    }
  }
  else
  {
    if (a.sign == -1)
    {
      if (this->digits.size() < a.digits.size())
        res = false;
      else if (this-> digits.size() > a.digits.size())
        res = true;
      else
      {
        res = true;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
          {
            res = false;
            lookingFor = false;
          }
          else if (this->digits[i] > a.digits[i])
            lookingFor = false;
          else
            --i;
        }
      }
    }
    else
    {
      res = true;
    }
  }
  return res;
}

bool longLongLong::operator>= (const longLongLong& a) const
{
  bool res;
  if (this->sign == 1)
  {
    if (a.sign == 1)
    {
      if (this->digits.size() < a.digits.size())
        res = false;
      else if (this->digits.size() > a.digits.size())
        res = true;
      else
      {
        res = true;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
          {
            res = false;
            lookingFor = false;
          }
          else if (this->digits[i] > a.digits[i])
            lookingFor = false;
          else
            --i;
        }
      }
    }
    else
    {
      res = true;
    }
  }
  else
  {
    if (a.sign == -1)
    {
      if (this->digits.size() < a.digits.size())
        res = true;
      else if (this->digits.size() > a.digits.size())
        res = false;
      else
      {
        res = true;
        bool lookingFor = true;
        int i = a.digits.size();
        while (lookingFor && i >= 0)
        {
          if (this->digits[i] < a.digits[i])
            lookingFor = false;
          else if (this->digits[i] > a.digits[i])
          {
            res = false;
            lookingFor = false;
          }
          else
            --i;
        }
      }
    }
    else
    {
      res = false;
    }
  }
  return res;
}

bool longLongLong::operator== (const longLongLong& a) const
{
  bool res = true;
  if (this->digits.size() != a.digits.size() || this->sign != a.sign)
    res = false;
  else
  {
    for (int i = 0; res && i < a.digits.size(); ++i)
      res = this->digits[i] == a.digits[i];
  }
  return res;
}

bool longLongLong::operator!= (const longLongLong& a) const
{
  bool res = false;
  if (this->digits.size() != a.digits.size() || this->sign != a.sign)
    res = true;
  else
  {
    for (int i = 0; !res && i < a.digits.size(); ++i)
      res = this->digits[i] != a.digits[i];
  }
  return res;
}

/*longLongLong longLongLong::operator+ (const longLongLong& a) const
{
  longLongLong res(*this);
  ushort cf = 0;
  if (res.sign == a.sign) 
  {
    for (int i = 0; i < min(res.digits.size(), a.digits.size()); ++i)
    {
      res.digits[i] += a.digits[i] + cf;
      cf = res[i] / 10;
      if (cf > 0)
        res[i] - 10;
    }
    for (; i < a.digits.size(); ++i)
    {
      res.push_back(a.digits[i] + cf);
      cf = res[i] / 10;
      if (cf > 0)
        res[i] - 10;
    }
    if (cf > 0)
      res.push_back(cf);
  }
  else
  {
    if (      
  }
  return res;
}*/

longLongLong longLongLong::operator= (const longLongLong& a)
{
  this->digits = a.digits;
  this->sign = a.sign;
  return *this;
}

/*   longLongLong operator= (longLongLong a)
    {
      this->digits = a.digits;
      this->sign = a.sign;
    }

    longLongLong operator+ (longLongLong a)
    {
      longLongLong res();
      if (this->sign == a.sign)
      {
        res.sign = this->sign;
        for (int i = 0; i < max((this->digits).length(), a.digits.length()), ++i)
      }

    }

    longLongLong operator- (longLongLong a)
    {
      return *this;
    }

    longLongLong operator* (longLongLong a)
    {
      return *this;
    }

    longLongLong operator/ (longLongLong a)
    {
      return *this;
    }

    longLongLong operator+= (longLongLong a)
    {
      return *this;
    }

    longLongLong operator-= (longLongLong a)
    {
      return *this;
    }

    longLongLong operator*= (longLongLong a)
    {
      return *this;
    }

    longLongLong operator/= (longLongLong a)
    {
      return *this;
    }
    
    longLongLong operator- ()
    {
      if (this->sign = 1)
        this->sign = -1
      else
        this->sign = 1;
      return *this;
    }
    
    bool operator== (longLongLong a)
    {
      return true;
    }
    
    bool operator!= (longLongLong a)
    {
      return true;
    }

    bool operator< (longLongLong a)
    {
      return true;
    }

    bool operator<= (longLongLong a)
    {
      return true;
    }


    bool operator> (longLongLong a)
    {
      return true;
    }

    bool operator>= (longLongLong a)
    {
      return true;
    }*/

void longLongLong::print()
{
  if (sign == -1)
    cout << '-';
  for (int i = digits.size()-1; i >= 0; --i)
    cout << digits[i];
  cout << endl;
}

longLongLong::~longLongLong()
{
  digits.clear();
}
