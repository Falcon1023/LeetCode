#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

class ToSmallest
{
public:
    static std::vector<long long> smallest(long long n);
};

std::vector<long long> ToSmallest::smallest(long long n)
{
  std::string str = std::to_string(n);
  std::vector<std::vector<long long>> vec = {{n, 0, 0}};
  int len = str.length();
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      std::string tmp = str;
      tmp.erase(i, 1);
      tmp.insert(j, 1, str[i]);
      vec.push_back({std::stoll(tmp), i, j});
    }
  }
  return *(std::min_element(vec.begin(), vec.end()));
}

int main() {
  std::vector<long long> res = ToSmallest::smallest(123456);
  std::cout << res[0] << std::endl << res[1] <<std::endl << res[2] << std::endl;
}
