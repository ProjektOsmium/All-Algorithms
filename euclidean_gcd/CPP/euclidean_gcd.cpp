#include <iostream>
using namespace std;

int euclidean_algorithm(int a, int b) {
  if (b == 0)
    return a;

  return euclidean_algorithm(b, a % b);
}

int main() {
  int input[2];

  cin >> input[0] >> input[1];

  int GCD = euclidean_algorithm(input[0], input[1]);

  cout << GCD << endl;
}
