#include<bits/stdc++.h>
using namespace std;
/**
 * First Sort the dimensions of each box.
 * Sort the vector of boxes.
 * Find LIS with path.
*/
struct Box {
    vector<int>dims;
    int id;
    Box() {}
    Box(int n) { dims.resize(n); }
    bool operator<(const Box& o) {
        int n = dims.size();
        for (int i = 0;i < n;i++) {
            if (dims[i] != o.dims[i])
                return dims[i] < o.dims[i];
        }
        return true;
    }
};
bool fits(Box a, Box b) {
    for (int i = 0;i < a.dims.size();i++) {
        if (a.dims[i] >= b.dims[i]) return false;
    }
    return true;
}
int main() {
    int n, d;
    while (scanf("%d%d", &n, &d) != EOF) {
        vector<Box>a(n);
        for (int i = 0;i < n;i++) {
            a[i] = Box(d);
            a[i].id = i + 1;
            for (int j = 0;j < d;j++) {
                scanf("%d", &a[i].dims[j]);
            }
            sort(a[i].dims.begin(), a[i].dims.end());
        }
        sort(a.begin(), a.end());
        int dp[n] = {};
        int path[n] = {};
        memset(path, -1, sizeof path);
        dp[0] = 1;
        // LIS in O(n^2)
        for (int i = 1;i < n;i++) {
            dp[i] = 1;
            for (int j = 0;j < i;j++) {
                if (fits(a[j], a[i])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        path[i] = j;
                    }
                }
            }
        }
        int ans = 1;
        int cur = 0;
        for (int i = 0;i < n;i++) {
            if (dp[i] > ans) {
                ans = dp[i];
                cur = i;
            }
        }
        printf("%d\n", ans);
        stack<int>s;
        while (cur + 1) {
            s.push(a[cur].id);
            cur = path[cur];
        }
        while (s.size()) {
            printf("%d", s.top());
            s.pop();
            printf(" ");
        }
        cout << endl;
    }
}