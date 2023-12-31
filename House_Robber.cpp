#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Recursive function to calculate the maximum value by robbing houses
ll f(vector<ll>& vec, ll ind, vector<ll>& dp) {
    if (ind == 0) return vec[ind];
    if (ind < 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    ll pick = vec[ind] + f(vec, ind - 2, dp);
    ll notpick = f(vec, ind - 1, dp);
    return dp[ind] = max(pick, notpick);
}

long long int houseRobber(vector<int>& valueInHouse) {
    ll n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];

    // Create two vectors excluding the first and last houses
    vector<ll> v1, v2;
    for (ll i = 0; i < n; i++) {
        if (i != 0) v1.push_back(valueInHouse[i]);
        if (i != n - 1) v2.push_back(valueInHouse[i]);
    }

    // Initialize DP arrays for both vectors
    vector<ll> dp1(v1.size(), -1);
    vector<ll> dp2(v2.size(), -1);

    // Calculate the maximum value by considering two cases (excluding first and last houses)
    ll ans = max(f(v1, v1.size() - 1, dp1), f(v2, v2.size() - 1, dp2));
    return ans;
}

