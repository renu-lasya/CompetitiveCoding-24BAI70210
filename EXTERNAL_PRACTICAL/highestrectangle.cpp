#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() &&
               heights[st.top()] > currentHeight) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    return maxArea;
}
int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    cout << "Largest Rectangle Area = "
         << largestRectangleArea(heights);
    return 0;
}
