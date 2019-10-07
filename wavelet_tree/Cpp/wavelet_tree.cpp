// The kth smallest element in subarray
#include <bits/stdc++.h>
using namespace std;

struct wavelet_tree{
   #define vi vector<int>
   #define pb push_back
   int lo, hi;
   wavelet_tree *l, *r;
   vi b;
   
   //nos are in range [x,y]
   //array indices are [from, to)
   wavelet_tree(int *from, int *to, int x, int y){
      lo = x, hi = y;
      if(lo == hi or from >= to) return;
      
      int mid = (lo+hi)/2;
      auto f = [mid](int x){
         return x <= mid;
      };
      b.reserve(to-from+1);
      b.pb(0);
      //b[i] = no of elements from first "i" elements that go to left node
      for(auto it = from; it != to; it++)
         b.pb(b.back() + f(*it));
      
      //see how lambda function is used here 
      auto pivot = stable_partition(from, to, f);
      l = new wavelet_tree(from, pivot, lo, mid);
      r = new wavelet_tree(pivot, to, mid+1, hi);
   }
   
   //kth smallest element in [l, r]
   int kth(int l, int r, int k){
      if(l > r) return 0;
      if(lo == hi) return lo;
      //how many nos are there in left node from [l, r]
      int inleft = b[r] - b[l-1];
      int lb = b[l-1]; //amt of nos from first (l-1) nos that go in left 
      int rb = b[r]; //amt of nos from first (r) nos that go in left
      //so [lb+1, rb] represents nos from [l, r] that go to left
      if(k <= inleft) return this->l->kth(lb+1, rb , k);
      
      //(l-1-lb) is amt of nos from first (l-1) nos that go to right
      //(r-rb) is amt of nos from first (r) nos that go to right
      //so [l-lb, r-rb] represents nos from [l, r] that go to right
      return this->r->kth(l-lb, r-rb, k-inleft);
   }
   ~wavelet_tree(){
      delete l;
      delete r;
   }
   
};
int main()
{
   int a[5] = {4, 7, 8, 1, 2};
   int n = sizeof(a) / sizeof(a[0]);
   wavelet_tree T(a, a+n, 1, 10);

   cout<<"1st smallest element in subarray [1-2] is :- "<<endl;
   cout<<T.kth(1, 2, 1)<<endl;

   cout<<"2nd smallest element in subarray [1-5] is :- "<<endl;
   cout<<T.kth(1, 5, 2)<<endl;

   cout<<"4th smallest element in subarray [1-5] is :- "<<endl;
   cout<<T.kth(1, 5, 4)<<endl;

   return 0;
}