#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n, x;
    cin >> n >> x;
 
    vector<ll> dp(x + 1);
    vector<ll> arr(n);
 
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    dp[0] = 1;
 
    for (ll i = 1; i <= x; i++) {
        for (ll j = 0; j < n; j++) {
            if (i >= arr[j]) {
                dp[i] += dp[i - arr[j]];
                dp[i] %= MOD;
            }
        }
    }
 
    cout << dp[x];
 
    return 0;
}
