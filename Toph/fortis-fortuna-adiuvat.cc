
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mem(x, i) memset(x, i, sizeof x)
#define ff first
#define ss second
typedef long long ll;
typedef pair<ll, ll> pll;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mx = 1e5 + 5;
ll dist[2][mx];
bool vis[2][mx];
void Dijkstra(int s, vector <vector<pll>>& adj, int cur) {
    priority_queue<pll, vector<pll>, greater<pll>>pq;
    pq.push({ 0,s });
    dist[cur][s] = 0;
    while (!pq.empty()) {
        int u = pq.top().ss;
        pq.pop();
        if (vis[cur][u])
            continue;
        vis[cur][u] = true;
        for (auto v : adj[u]) {
            if (dist[cur][v.ss] > dist[cur][u] + v.ff) {
                dist[cur][v.ss] = dist[cur][u] + v.ff;
                pq.push({ dist[cur][v.ss],v.ss });
            }
        }
    }
}
void solve() {
    int n, m, t, q;
    scanf("%d %d %d %d", &n, &m, &t, &q);
    vector <vector<pll>> g(n + 1), rg(n + 1);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[v].pb({ w,u });
        rg[u].pb({ w,v });
    }
    mem(dist, LL_INF);
    mem(vis, false);
    Dijkstra(t, g, 0);
    Dijkstra(t, rg, 1);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (dist[0][u] == LL_INF || dist[1][v] == LL_INF)
            printf("Be seeing ya, John\n");
        else
            printf("%lld\n", dist[0][u] + dist[1][v]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1;i <= t;i++) {
        printf("Case %d:\n", i);
        solve();
    }
}