#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    int n = nums.size();

    for (int i = 0; i <= n - k; i++) {
        int maximum = nums[i];

        for (int j = i; j < i + k; j++) {
            maximum = max(maximum, nums[j]);
        }

        result.push_back(maximum);
    }

    return result;
}

int main() {
    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    if (k <= 0 || k > n) {
        cout << "Invalid window size";
        return 0;
    }

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximum in each window: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
