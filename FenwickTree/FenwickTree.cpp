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

	cin >> n;

	bit.initialize(N);

	for (int i = 0; i < N; ++i)
	{
		bit.update(i, i);
	}

	for (int i = 0; i < N; ++i)
	{
		cout<<bit.query(i)<<endl;
	}

}
