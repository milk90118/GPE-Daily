#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int countMines(const vector<string> &field, int x, int y, int n, int m) {

    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == '*') {
            cnt++;
        }
    }
    return cnt;
}

int main() {

    int n, m, fieldNum = 0;

    while (cin >> n >> m, n || m) {

        vector<string> field(n);

        for (int i = 0; i < n; ++i) {
            cin >> field[i];
        }

        if (fieldNum) cout << endl;
        cout << "Field #" << ++fieldNum << ":" << endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                if (field[i][j] == '*') 
                {
                    cout << '*';
                } 
                else 
                {
                    cout << countMines(field, i, j, n, m);
                }
            }
            cout << endl;
        }
    }
    return 0;
}
