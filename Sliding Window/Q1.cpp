// Longest Substring without repeating characters

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int largest = 0;
  map<char, int> mpp;
  int i = 0, j = 0;

  while (j < s.size()) {
    if (mpp[s[j]] < 1) {
      mpp[s[j]]++;
      j++;
    } else {
      largest = max(largest, j - i);
      while (s[j] != s[i])
        i++;
      i++;
      j++;
    }
  }
  largest = max(largest, j - i);
  cout << largest << endl;
  return 0;
}
