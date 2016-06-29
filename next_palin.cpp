#include <iostream>
#include <list>
#include <vector>

using namespace std;

void work(vector<int>& num, int pos1, int pos2) {
    if (pos1 < 0) {
	num[num.size()-1] = 1;
	num.insert(num.begin(), 1);
	return;
    } else if (num[pos1] < 9) {
	    num[pos1] = num[pos2] = num[pos1] + 1;
	    return;
    } else {
	    num[pos1] = num[pos2] = 0;
	    work(num, pos1-1, pos2+1);
	    return;
    }
}

void mirrorNumber(std::vector<int> &bigNum)
{
  if (0==(bigNum.size()%2)) {
    int mid = bigNum.size()/2;
    int pos1 = mid-1;
    int pos2 = mid;
    int j = mid-1;
    while (j>=0) {
      bigNum[mid++] = bigNum[j];
      j--;
    }
    work(bigNum, pos1, pos2);
  } else {
   int mid = bigNum.size()/2;
   int pos1,pos2;
   pos1 = pos2 = mid;
   int j = mid-1;
   mid++;
   while (j>=0) {
      bigNum[mid++] = bigNum[j];
      j--;
   }
   work(bigNum, pos1, pos2);
  }
  for(int i = 0; i < bigNum.size(); ++i) {
      cout << bigNum[i];
  }
  cout << std::endl;
}

int main() {
  int count;

    cin >> count;
    for(int i = 0; i < count; ++i) {
      std::string number;
      number.reserve(1000000);
      std::vector<int> bigNum;
      cin >> number;
      for (int j = 0; j < number.size(); ++j)
           bigNum.push_back(number[j]-'0');
      mirrorNumber(bigNum);
    }
  return 0;
}

