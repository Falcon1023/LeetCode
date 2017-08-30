#include <iostream>
#include <string>
using namespace std;

string post_order(string str1, string str2) {
  size_t len = str1.length();
  if (len == 0)
    return "";
  char root = str1[0];
  size_t pos;
  string str1l = "", str1r = "", str2l = "", str2r = "";
  for (pos = 0; pos < str2.length(); pos++) {
    if (str2[pos] == root)
      break;
    else
      str2l += str2[pos];
  }
  for (size_t j = 1; j <= pos; j++)
    str1l += str1[j];
  for (size_t j = pos+1; j < len; j++)
    str1r += str1[j];
  for (size_t j = pos+1; j < len; j++)
    str2r += str2[j];
  string strl = post_order(str1l, str2l);
  string strr = post_order(str1r, str2r);
  string str = strl + strr + root;
  return str;
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  string str = post_order(str1, str2);
  cout << str << endl;
  return 0;
}
