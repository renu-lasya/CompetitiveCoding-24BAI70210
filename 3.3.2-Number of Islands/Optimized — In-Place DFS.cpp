#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {

    int m = grid.size();
    int n = grid[0].size();

    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (grid[r][c] != '1')
        return;

    // Mark as visited
    grid[r][c] = '0';

    // Up
    dfs(grid, r - 1, c);

    // Down
    dfs(grid, r + 1, c);

    // Left
    dfs(grid, r, c - 1);

    // Right
    dfs(grid, r, c + 1);
}

int main() {

    int m, n;

    cout << "Enter rows: ";
    cin >> m;

    cout << "Enter columns: ";
    cin >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    cout << "Enter grid (0 or 1):\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (grid[i][j] == '1') {

                count++;

                dfs(grid, i, j);
            }
        }
    }

    cout << "Number of islands = " << count;

    return 0;
}
