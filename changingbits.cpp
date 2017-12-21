#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
#include <cassert>

class big_num
{
public:
  big_num(int size) : m_size(size), m_bits(size / 64 + 1, false) {}
  big_num(int size, const std::string &start_value) : big_num(size)
  {
    int pos = 0;
    for (auto itr = start_value.crbegin(); itr != start_value.crend(); itr++)
    {
      if (*itr == '0' || *itr == '1')
      {
        set_bit(pos, (*itr == '1'));
        pos++;
      }
    }
  }
  void set_bit(int bit, bool value)
  {
    const auto bit_mask = 1ull << (bit % 64);
    const uint64_t previous_bits = ~bit_mask & m_bits[bit / 64];
    m_bits[bit / 64] &= ~bit_mask;
    m_bits[bit / 64] ^= ((uint64_t)value << (bit % 64));
    const uint64_t new_bits = ~bit_mask & m_bits[bit / 64];

    assert(previous_bits == new_bits);
    assert(get_bit(bit) == value);
  }
  bool get_bit(int bit) const { return m_bits[bit / 64] & (1ull << (bit % 64)); }
  int get_size() const { return m_size; }

  friend big_num operator+(const big_num &lhs, const big_num &rhs);

private:
  uint64_t m_size;
  std::vector<uint64_t> m_bits;
};

big_num operator+(const big_num &lhs, const big_num &rhs)
{
  big_num res(lhs.get_size() + 64);
  bool carry = false;
  size_t i = 0;
  const auto size = lhs.m_bits.size();
  for (; i < size; i++)
  {
    unsigned long long sum;
    auto new_carry = __builtin_uaddll_overflow(lhs.m_bits[i], rhs.m_bits[i], &sum);
    new_carry |= __builtin_uaddll_overflow(sum, carry, &sum);
    
    res.m_bits[i] = sum;
    carry = new_carry;
  }
  res.m_bits[i] = (int)carry;
  return res;
}

int get_number()
{
  int n;
  std::cin >> n;
  return n;
}

int main()
{
  std::ios::sync_with_stdio(false);
  
  int N, Q;
  std::string init_val_a;
  std::string init_val_b;
  std::cin >> N >> Q >> std::ws >> init_val_a >> std::ws >> init_val_b;

  big_num a(N, init_val_a);
  big_num b(N, init_val_b);

  for (int i = 0; i < Q; i++)
  {
    std::string command;
    std::cin >> std::ws >> command >> std::ws;

    int arg1 = get_number();
    if (command[4] == 'a')
    {
      int arg2 = get_number();
      a.set_bit(arg1, arg2);
    }
    else if (command[4] == 'b')
    {
      int arg2 = get_number();
      b.set_bit(arg1, arg2);
    }
    else if (command[4] == 'c')
    {
      const auto sum = a + b;
      std::cout <<  sum.get_bit(arg1);
    }
    else
    {
      std::cout << "Invalid command : \n"
                << command << "iter : " << i << " of " << Q << std::endl;
    }
  }
  return 0;
}
