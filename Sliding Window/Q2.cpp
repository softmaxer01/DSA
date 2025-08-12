#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> vec;
  vec.reserve(n);
  for (int i = 0; i < n; i++) {
    int element;
    cin >> element;
    vec.push_back(element);
  }
  int largest = 0;
  queue<int> zeros;
  int i = 0, j = 0;
  while (j < vec.size()) {
    if (vec[j] == 1) {
      j++;
    } else if (vec[j] == 0 && (int)zeros.size() < k) {
      zeros.push(j);
      j++;
    } else if (vec[j] == 0 && k == 0) {
      largest = max(largest, j - i);
      i = j + 1;
      j++;
    } else {
      largest = max(largest, j - i);
      i = zeros.front() + 1;
      zeros.pop();
    }
  }
  largest = max(largest, j - i);
  cout << largest << endl;
  return 0;
}
