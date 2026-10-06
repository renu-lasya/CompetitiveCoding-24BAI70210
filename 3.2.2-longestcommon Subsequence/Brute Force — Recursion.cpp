#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string a, string b, int i, int j) {

    // If any string is finished
    if (i == a.length() || j == b.length())
        return 0;

    // If characters are same
    if (a[i] == b[j]) {
        return 1 + lcs(a, b, i + 1, j + 1);
    }

    // If characters are different
    return max(
        lcs(a, b, i + 1, j),
        lcs(a, b, i, j + 1)
    );
}

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    cout << "LCS length = "
         << lcs(text1, text2, 0, 0) << endl;

    return 0;
}
