#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {

    int i = s.length() - 1;
    int len = 0;

    // Skip spaces from the end
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count last word characters
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }

    return len;
}

int main() {

    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    cout << "Length of last word = "
         << lengthOfLastWord(s);

    return 0;
}
