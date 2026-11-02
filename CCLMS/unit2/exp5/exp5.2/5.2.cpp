#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    int freq[26] = {0};

    // Count task frequencies
    for (char t : tasks) {
        freq[t - 'A']++;
    }

    // Find maximum frequency
    int maxFreq = *max_element(freq, freq + 26);

    // Count tasks having maximum frequency
    int countMaxFreq = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            countMaxFreq++;
        }
    }

    // Calculate minimum intervals
    int intervals = (maxFreq - 1) * (n + 1) + countMaxFreq;

    return max((int)tasks.size(), intervals);
}

int main() {
    int m, n;

    cout << "Enter number of tasks: ";
    cin >> m;

    vector<char> tasks(m);

    cout << "Enter tasks: ";
    for (int i = 0; i < m; i++) {
        cin >> tasks[i];
    }

    cout << "Enter cooldown period: ";
    cin >> n;

    cout << "Minimum CPU intervals: "
         << leastInterval(tasks, n);

    return 0;
}
