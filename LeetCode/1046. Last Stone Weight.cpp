/*
    We need to find the top two stones in each turn
    which can be found in less complexity with priority queue.
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for (int x : stones)pq.push(x);
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x == y) {
                continue;
            }
            pq.push(x - y);
        }
        return pq.size() ? pq.top() : 0;
    }
};