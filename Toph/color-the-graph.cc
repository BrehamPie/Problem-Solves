#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
ll powmod(ll a, ll b, ll MOD) { ll res = 1;a %= MOD;assert(b >= 0);for (; b; b >>= 1) { if (b & 1)res = res * a % MOD;a = a * a % MOD; }return res; }
const int mod = 1e9+7;
const int mx = 5e5 + 5;
vector<int>adj[mx];
int sub[mx];
bool vis[mx];
void dfs(int u, int p) {
    sub[u] = 1;
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int>mals;
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {
            dfs(i, 0);
            mals.pb(sub[i]);
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        ll ans = 1;
        for (int i = 0;i < mals.size();i++) {
            ll add = 1ll * x * powmod(x - 1, mals[i] - 1, mod);
            add %= mod;
            ans = ans * add;
            ans %= mod;
        }
        cout << ans << endl;
    }

}
