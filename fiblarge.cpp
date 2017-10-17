/*
 * Author: Vijay Nag
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class BigNum
{
    private:
    std::vector<char> num_;

    public:
        BigNum()
        {
            BigNum(1);
        }

        BigNum(int l)
        {
            num_.resize(l);
            for(int i=0;i<l;++i)
                num_[i]='0';
        }

        BigNum(std::string &n)
        {
           setFromString(n);
        }

        std::string toString(void) const
        {
            std::string s;

            s="";
            for(int i=num_.size()-1;i>=0;--i)
                s+=num_[i];
            return s;
        }

        void zero(void)
        {
           num_.clear();
           num_.push_back('0');
        }

        size_t size(void) const
        {
          return num_.size();
        }

        void setFromString(const std::string &n)
        {
            num_.resize(n.size());
            for(int i=n.size()-1;i>=0;i--) {
                num_[n.size()-1-i] = n[i];
            }
        }

        void printNum(ostream &out) const
        {
            out << toString();
        }

        int getDigit(char c)
        {
          return c-'0';
        }

        int getNumIdx(const std::string &s, int idx)
        {
          if (idx > s.size()-1)
            return 0;
          return s[s.size()-1-idx]-'0';
        }

        int getNum(int idx) const
        {
          if (idx < num_.size())
            return num_[idx] - '0';
          return 0;
        }

        void pushNum(int digit)
        {
          num_.push_back(digit+'0');
        }

        const BigNum &addNum(const std::string &n)
        {
          int i,j;
          int carry=0;
          BigNum res(0); //zero
          int larger= num_.size() < n.size() ? n.size() : num_.size();

          if (n.size()==1 && n[0]=='0') {
            return *this;
          }

          for(i=j=0;larger;++i,++j) {
            int d1 = getNum(i);
            int d2 = getNumIdx(n,j);
            int s = d1 + d2 + carry;
            if (s >= 10) {
              s=s%10;
              carry=1;
            } else {
              carry=0;
            }
            res.pushNum(s);
            larger--;
          }
          if (carry) {
            res.pushNum(carry);
          }

          *this=res;
          return *this;
        }

        void addNum(const BigNum &b)
        {
          addNum(b.toString());
        }

        const BigNum &mulNum(int digit)
        {
          int carry=0, product=0;
          int len = num_.size();

          if (digit==1) {
            return *this;
          } else if (digit==0) {
            zero();
            return *this;
          } else if (digit == 10) {
            num_.insert(num_.begin(),'0');
            return *this;
          }

          for(int i=0;i<len;++i) {
            product = getNum(i) * digit + carry;
            carry = product / 10;
            num_[i] = '0' + (product % 10);
          }

          while (carry !=0) {
            num_.push_back('0'+ (carry % 10));
            carry /= 10;
          }
          return *this;
        }

        friend istream & operator >> (istream & in, BigNum & big)
        {
            std::string s;
            in>>s;
            big = BigNum(s);
            return in;
        }

        const BigNum& operator=(const BigNum &rhs)
        {
          setFromString(rhs.toString());
          return *this;
        }

        const BigNum& operator+=(const BigNum &rhs)
        {
             addNum(rhs.toString());
             return *this;
        }

        const BigNum& operator+=(const int n)
        {
          addNum(std::to_string(n));
          return *this;
        }

        BigNum operator*(const int digit)
        {
          BigNum result(*this);
          result.mulNum(digit);
          return result;
        }

        const BigNum& operator*=(const int digit)
        {
          return mulNum(digit);
        }

        const BigNum operator*=(const BigNum &rhs)
        {
          BigNum result(*this);
          BigNum sum(0);
          int len = rhs.size();

          for(int i=0;i<len;++i) {
            sum += result * rhs.getNum(i);
            result *= 10;
          }

          *this = sum;
          return *this;
        }

        friend BigNum power(const BigNum &num, int n)
        {
          if (!n) return 1;
          if (n==1) return num;

          BigNum result = power(num, n/2);
          result *= result;

          if (n%2==0) return result;
          return result * num;
        }

        friend ostream & operator <<(ostream & out, const BigNum & big)
        {
            big.printNum(out);
            return out;
        }

        friend BigNum operator +(const BigNum &lhs, const BigNum &rhs)
        {
          BigNum num(lhs);
          num.addNum(rhs.toString());
          return num;
        }

        friend BigNum operator*(const BigNum &lhs, const BigNum &rhs)
        {
          BigNum result(lhs);
          result *= rhs;
          return result;
        }
};

BigNum fact[21];

void computeFactorial(int num)
{
  for(int i=2;i<=num;++i) {
    BigNum c(fact[i-1]);
    c+=1;
    fact[i] = fact[i-2] + power(c, 2);
  }
}

int main(int argc, char **argv)
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  BigNum t1, t2;
  int n;

  cin >> t1 >> t2 >> n;
  fact[0]=t1;
  fact[1]=t2;

  computeFactorial(n);
  cout << fact[n-1] << std::endl;
}
