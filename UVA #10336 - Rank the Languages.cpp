#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 105

int n, m, cnt[26];
char grid[MAXN][MAXN];

void dfs(int x, int y, char c) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != c) return;
    grid[x][y] = '*';
    dfs(x - 1, y, c); dfs(x + 1, y, c);
    dfs(x, y - 1, c); dfs(x, y + 1, c);
}

int main() {
    int test;
    cin >> test;
    for(int t = 1; t <= test; ++t) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> grid[i];

        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (grid[i][j] != '*') {
                    cnt[grid[i][j] - 'a']++;
                    dfs(i, j, grid[i][j]);
                }
        
        vector<pair<int, char>> v;
        for (int i = 0; i < 26; i++) 
            if (cnt[i]) 
                v.emplace_back(-cnt[i], 'a' + i);

        sort(v.begin(), v.end());
        cout << "World #" << t << endl;

        for (auto pair : v) cout << pair.second << ": " << - (pair.first) << endl;
    }
    return 0;
}