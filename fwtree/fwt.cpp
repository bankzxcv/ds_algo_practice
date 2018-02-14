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

void adjust(int k, int v) {
  k += 1;
  while (k < 11) {
    y[k] += v;
    k += lsb(k);
  }
}

int sum(int i, int j) {
  if (j < i) {
    i ^= j;
    j ^= i;
    i ^= j;
  }
  return prefixSum(j) - prefixSum(i - 1);
}

void update(int i, int v) {
  int diff = v - sum(i, i);
  cout<<diff<<endl;
  adjust(i, diff);
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
  update(0, 0);
  for (int i = 0; i <= 10; i++) {
    cout << y[i] << ",";
  }
}
