#include <bits/stdc++.h>

using namespace std;

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

int main(){

   cout<<"Euler totient function from 10 to 14 is : "<<endl;
   cout<<phi(10)<<endl;
   cout<<phi(11)<<endl;
   cout<<phi(12)<<endl;
   cout<<phi(13)<<endl;
   cout<<phi(14)<<endl;

   return 0;
}