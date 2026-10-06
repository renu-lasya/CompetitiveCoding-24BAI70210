#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minCost(vector<int>& height, int k) {
    int n = height.size();

    vector<int> dp(n, 0);

    // Calculate minimum cost for every stone
    for (int i = 1; i < n; i++) {

        int best = 1000000000;

        // Check previous k stones
        for (int j = max(0, i - k); j < i; j++) {

            int cost = dp[j] + abs(height[i] - height[j]);

            best = min(best, cost);
        }

        dp[i] = best;
    }

    return dp[n - 1];
}

int main() {
    int n, k;

    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << "Enter maximum jump distance k: ";
    cin >> k;

    cout << "Minimum cost = " << minCost(height, k);

    return 0;
}
