#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxPerformance(int n, vector<int>& speed,
                   vector<int>& efficiency, int k) {

    vector<pair<int, int>> engineers;

    // Store efficiency and speed
    for (int i = 0; i < n; i++) {
        engineers.push_back({efficiency[i], speed[i]});
    }

    // Sort by decreasing efficiency
    sort(engineers.rbegin(), engineers.rend());

    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    long long speedSum = 0;
    long long result = 0;

    for (auto eng : engineers) {

        int eff = eng.first;
        int spd = eng.second;

        pq.push(spd);
        speedSum += spd;

        // Remove smallest speed if size exceeds k
        if (pq.size() > k) {
            speedSum -= pq.top();
            pq.pop();
        }

        long long performance = speedSum * eff;

        result = max(result, performance);
    }

    return result % 1000000007;
}

int main() {

    int n, k;

    cout << "Enter number of engineers: ";
    cin >> n;

    vector<int> speed(n);
    vector<int> efficiency(n);

    cout << "Enter speeds: ";
    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }

    cout << "Enter efficiencies: ";
    for (int i = 0; i < n; i++) {
        cin >> efficiency[i];
    }

    cout << "Enter maximum team size k: ";
    cin >> k;

    cout << "Maximum Performance = "
         << maxPerformance(n, speed, efficiency, k);

    return 0;
}
