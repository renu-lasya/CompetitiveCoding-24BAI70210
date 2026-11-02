#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {

    vector<string> result;
    int i = 0;
    int n = words.size();

    while (i < n) {

        int j = i + 1;
        int lineLen = words[i].size();

        // Find words that fit in the line
        while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
            lineLen += 1 + words[j].size();
            j++;
        }

        int numWords = j - i;
        int spaces = maxWidth - (lineLen - numWords + 1);

        string line = words[i];

        // Last line or single word
        if (numWords == 1 || j == n) {

            for (int k = i + 1; k < j; k++) {
                line += " " + words[k];
            }

            line += string(maxWidth - line.size(), ' ');
        }

        // Fully justify the line
        else {

            int eachSpace = spaces / (numWords - 1);
            int extra = spaces % (numWords - 1);

            for (int k = i + 1; k < j; k++) {

                int count = eachSpace;

                if (k - i <= extra) {
                    count++;
                }

                line += string(count, ' ') + words[k];
            }
        }

        result.push_back(line);
        i = j;
    }

    return result;
}

int main() {

    int n, maxWidth;

    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter words: ";

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << "Enter maximum width: ";
    cin >> maxWidth;

    vector<string> result = fullJustify(words, maxWidth);

    cout << "\nJustified Text:\n";

    for (string line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}
