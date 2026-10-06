#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(vector<int>& height, int i, int k) {
    // Base case
    if (i == 0)
        return 0;

    int best = 1000000000;

    // Check previous k stones
    for (int j = max(0, i - k); j < i; j++) {
        int cost = solve(height, j, k) + abs(height[i] - height[j]);
        best = min(best, cost);
    }

    return best;
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

    cout << "Minimum cost = " << solve(height, n - 1, k);

    return 0;
}
