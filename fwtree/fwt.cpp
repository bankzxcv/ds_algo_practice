#include <iostream>
using namespace std;

int y[11];
int lsb(int num) { return num & -num; }

int prefixSum(int i) {
  i += 1;
  int sum = 0;
  while (i != 0) {
    sum += y[i];
    i -= lsb(i);
  }
  return sum;
}

void adjust(int i, int v) {
  i += 1;
  while (i < 11) {
    y[i] += v;
    i += lsb(i);
  }
}

void update(int i, int v) {
  // update value in i position with diff value
  int diff = v - sum(i, i);
  adjust(i, diff);
}

int sum(int i, int j) {
  // make sure for j > i
  // if j < i then swap i and j
  if (j < i) {
    i ^= j;
    j ^= i;
    i ^= j;
  }
  return prefixSum(j) - prefixSum(i - 1);
}

int main() {
  int x[10];
  for (int i = 0; i < 10; i++) {
    x[i] = i + 1;
    cout << x[i] << ",";
  }
  cout << endl << "=========" << endl;
  for (int i = 0; i < 10; i++) {
    adjust(i, x[i]);
  }
  for (int i = 0; i <= 10; i++) {
    cout << y[i] << ",";
  }
  cout << endl << "=========" << endl;
  cout << prefixSum(5) << endl;
  cout << sum(0, 9) << endl;
  // update position 0 with value
  update(0, 0);
  for (int i = 0; i <= 10; i++) {
    cout << y[i] << ",";
  }
}
