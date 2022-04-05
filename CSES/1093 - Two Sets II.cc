#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll powmod(ll a, ll b, ll MOD) { ll res = 1;a %= MOD;assert(b >= 0);for (; b; b >>= 1) { if (b & 1)res = res * a % MOD;a = a * a % MOD; }return res; }

const int mod = 1e9 + 7;
ll dp[62630][502];
int n;
int req;
ll call(int sum, int cur) {
    if (sum > req) return 0;
    if (cur > n) { return sum == req; }
    if (dp[sum][cur] + 1)return dp[sum][cur];
    ll ret = 0;
    ret = call(sum, cur + 1) + call(sum + cur, cur + 1);
    return dp[sum][cur] = ret % mod;
}

int main() {
    cin >> n;
    int sum = (n * n + n) / 2;
    if (sum % 2)cout << 0 << endl;
    else {
        req = sum / 2;
        memset(dp, -1, sizeof dp);
        ll ans = call(0, 1);
        ll d = powmod(2, mod - 2, mod);
        ans = (ans * d) % mod;
        cout << ans << endl;

    }


}