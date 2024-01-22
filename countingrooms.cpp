#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, size_t i, size_t j) 
 {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] == '#')
        return;

    vis[i][j] = true;

  
    dfs(grid, vis, i, j + 1);
    dfs(grid, vis, i + 1, j);
    dfs(grid, vis, i - 1, j);
    dfs(grid, vis, i, j - 1);
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n, ' '));
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int c = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                dfs(grid, vis, i, j);
                c++;
            }
        }
    }
    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
