#include<bits/stdc++.h>
using namespace std;
/**
 * Given 2 jobs x and y
 * if x.time*y.fine<x.fine*y.time then
 * x should come first
 */
struct  Job {
    int id, time, fine;
    bool operator<(const Job& o) {
        if (time * o.fine != fine * o.time)
            return time * o.fine < fine* o.time;
        else return id < o.id;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        cin >> n;
        vector<Job>v(n);
        for (int i = 0;i < n;i++) {
            scanf("%d%d", &v[i].time, &v[i].fine);
            v[i].id = i + 1;
        }
        sort(v.begin(), v.end());
        printf("%d", v[0].id);
        for (int i = 1;i < n;i++) {
            printf(" %d", v[i].id);
        }
        puts("");
        if (t > 0)puts("");
    }
}