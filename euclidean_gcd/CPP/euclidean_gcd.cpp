#include <iostream>
using namespace std;

int euclidean_algorithm(int a, int b) {
  if (b == 0)
    return a;

  return euclidean_algorithm(b, a % b);
}

int main() {
  int GCD = euclidean_algorithm(20, 30);

  cout << GCD << endl;
}
