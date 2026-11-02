#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find maximum subsequence of required length
vector<int> maxSubseq(vector<int>& nums, int len) {
    int drop = nums.size() - len;
    vector<int> st;

    for (int x : nums) {
        while (drop > 0 && !st.empty() && st.back() < x) {
            st.pop_back();
            drop--;
        }
        st.push_back(x);
    }

    st.resize(len);
    return st;
}

// Merge two subsequences
vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> res;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (lexicographical_compare(
            b.begin() + j, b.end(),
            a.begin() + i, a.end())) {
            res.push_back(a[i++]);
        } else {
            res.push_back(b[j++]);
        }
    }

    while (i < a.size())
        res.push_back(a[i++]);

    while (j < b.size())
        res.push_back(b[j++]);

    return res;
}

// Find the maximum number of length k
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();

    vector<int> best;

    for (int i = max(0, k - n); i <= min(k, m); i++) {
        vector<int> s1 = maxSubseq(nums1, i);
        vector<int> s2 = maxSubseq(nums2, k - i);

        vector<int> merged = merge(s1, s2);

        if (merged > best)
            best = merged;
    }

    return best;
}

int main() {
    int m, n, k;

    cout << "Enter size of first array: ";
    cin >> m;

    vector<int> nums1(m);

    cout << "Enter first array elements: ";
    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n;

    vector<int> nums2(n);

    cout << "Enter second array elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    cout << "Enter value of k: ";
    cin >> k;

    vector<int> result = maxNumber(nums1, nums2, k);

    cout << "Maximum Number: [";

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i < result.size() - 1)
            cout << ", ";
    }

    cout << "]";

    return 0;
}
