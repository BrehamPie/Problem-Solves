#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    queue<int>q;
    map<int, int>cnt;
    int dis = 0;
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
        if (cnt[x] == 1) dis++;
        q.push(x);
        while (dis > k) {
            int y = q.front();
            q.pop();
            cnt[y]--;
            if (cnt[y] == 0)dis--;
        }
        ans += (long long)q.size();
    }
    cout << ans << endl;
}