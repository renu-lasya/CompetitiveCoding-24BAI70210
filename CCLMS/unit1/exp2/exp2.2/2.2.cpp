#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generate(int open, int close, int n,
              string current, vector<string>& result) {

    // If length becomes 2*n, store the answer
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // Add opening bracket
    if (open < n) {
        generate(open + 1, close, n, current + "(", result);
    }

    // Add closing bracket
    if (close < open) {
        generate(open, close + 1, n, current + ")", result);
    }
}

int main() {

    int n;

    cout << "Enter number of pairs: ";
    cin >> n;

    vector<string> result;

    generate(0, 0, n, "", result);

    cout << "Valid parentheses combinations:\n";

    for (string s : result) {
        cout << s << endl;
    }

    cout << "Total combinations: " << result.size();

    return 0;
}
