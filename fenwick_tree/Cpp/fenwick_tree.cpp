#include <bits/stdc++.h>
using namespace std;

const int N = 100;

template <typename T>
struct fenwick_tree {
private:
   int n;
   vector <T> a;
public:
   void initialize(int k) {
      n=k;
      a.assign(n+1,0);
   }
   
   void update(int pos, T val) {
      for(;pos<=n;pos+=pos&(-pos)) a[pos]+=val;
   }
 
   T query(int pos) {
      T ans=0;
      for(;pos>=1;pos-=pos&(-pos)) ans+=a[pos];
      return ans;
   }
   
   T get(int from, int to) {
      return query(to)-query(from-1);
   }

   int lower_bound(T x){
      int index = 0;
      int sum = 0;
      for (int i = (log2(n) + 1); i >= 0; --i)
      {
         if((index+(1<<i)) <= n and (sum + a[index+(1<<i)]) < x){
            sum += a[index+(1<<i)];
            index += (1<<i);
         }
      }
      return index+1;
   }
};

fenwick_tree <int> bit;

int32_t main(){

   cout << "Initializing size to be 5" << endl;
   bit.initialize(5);

   cout << "Updating Value at 1" << endl;
   bit.update(1, 1);
   cout << "Updating Value at 2" << endl;
   bit.update(2, 2);
   cout << "Updating Value at 3" << endl;
   bit.update(3, 3);
   cout << "Updating Value at 4" << endl;
   bit.update(4, 4);
   cout << "Updating Value at 5" << endl;
   bit.update(5, 5);

   cout<<"The sum of values from 1 to 1 is : "<<endl;
   cout<<bit.query(1)<<endl;
   cout<<"The sum of values from 1 to 2 is : "<<endl;
   cout<<bit.query(2)<<endl;
   cout<<"The sum of values from 1 to 3 is : "<<endl;
   cout<<bit.query(3)<<endl;
   cout<<"The sum of values from 1 to 4 is : "<<endl;
   cout<<bit.query(4)<<endl;
   cout<<"The sum of values from 1 to 5 is : "<<endl;
   cout<<bit.query(5)<<endl;
}