#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    // Initialize all answers with -1
    vector<int> result(n, -1);

    // Stack stores indices
    stack<int> st;

    // Traverse the array twice
    for (int i = 0; i < 2 * n; i++) {

        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            result[st.top()] = nums[i % n];
            st.pop();
        }

        // Push indices only during first traversal
        if (i < n) {
            st.push(i);
        }
    }

    return result;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = nextGreaterElements(nums);

    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}
