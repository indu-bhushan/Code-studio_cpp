#include <bits/stdc++.h> 
const int mod = int(1e9+7);
int f(int n,vector<int>&dp){
    if(n==0) return 1;
    if(n==1) return 1;
    
    if(dp[n]!=-1) return dp[n];

    int jump1 = f(n-1,dp)%mod;
    int jump2 = f(n-2,dp)%mod;

    dp[n] = jump1+jump2;
    dp[n]%=mod;
    return dp[n];
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int>dp(nStairs+1,-1);
    int ans = f(nStairs,dp);
    return ans;
}