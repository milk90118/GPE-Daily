#include <iostream>
using namespace std;

char map[1000][1000];

bool isSquare(int x, int y, int a, int row, int col) 
{
    if (x - a < 0 || y - a < 0 || x + a >= row || y + a >= col) return false;
    
    for (int i = x - a; i <= x + a; ++i) 
    {
        for (int j = y - a; j <= y + a; ++j) 
        {
            if (map[i][j] != map[x][y]) return false;
        }
    }

    return true;
}

int main() {
    int t, row, col, n, x, y, a;

    cin >> t;
    while (t--) {
        
        cin >> row >> col >> n;

        cout << row << " " << col << " " << n << endl;

        for (int i = 0; i < row; ++i) 
        {
            for (int j = 0; j < col; ++j) 
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < n; ++i) 
        {
            cin >> x >> y;
            a = 0;

            while (isSquare(x, y, a, row, col)) {
                a++;
            }

            cout << 2 * a - 1 << endl; // 2 * (a - 1) + 1
        }
    }
    return 0;
}
