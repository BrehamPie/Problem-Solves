#include<bits/stdc++.h>
using namespace std;
int dp[200000];
int main() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0;i < n;i++)cin >> v[i];
    dp[0] = 1;
    for (int i = 0;i < n;i++) {
        for (int j = 100000;j >= 0;j--) {
            if (dp[j] == 1)dp[v[i] + j] = 1;
        }
    }
    vector<int>ans;
    for (int i = 1;i <= 100000;i++)if (dp[i])ans.push_back(i);
    cout << ans.size() << endl;
    for (int x : ans)cout << x << ' '; cout << endl;

}