/* The following is the dynamic programming approach for the 0/1 Knapsack problem.
   Problem link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

void solve() {
    memset(dp,-1,sizeof(dp));   // clear the array 
    int n, w;                   // n => number of elements     w => capacity of knapsack  
    cin >> n >> w;
    int val[n], wt[n];          // val => value array  wt => weight array
    for(int i = 0; i < n; i++)
        cin >> val[i];
    for(int i = 0; i < n; i++)
        cin >> wt[i];
    
    // initialization of matrix 
    
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    
    // filling matrix

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){
            if(wt[i-1] <= j)
                dp[i][j] = max((val[i-1] + dp[i-1][j-wt[i-1]]), dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][w] << '\n';
}

int main() {
	int t = 1;
	cin >> t;
	while(t--){
	    solve();
	}
}
