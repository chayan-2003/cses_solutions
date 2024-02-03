#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x;
    cin >> n;
    x = n; // Set x to the original value of n

    vector<ll> arr;
    while (n > 0) {
        int d = n % 10;
        n = n / 10;
        arr.push_back(d);
    }

    vector<ll> dp(x + 1, INT_MAX);

    for (ll i = 0; i < x; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;
    n = arr.size();

    for (ll i = 1; i <= x; i++) {
        ll min1 = INT_MAX;
        for (ll j = 0; j < n; j++) {
            if (i >= arr[j]) {
                min1 = min(min1, 1 + dp[i - arr[j]]);
            }
        }
        dp[i] = min1 % MOD;
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x] - 2);

    return 0;
}
