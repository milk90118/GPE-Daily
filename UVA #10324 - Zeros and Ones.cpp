#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    
    int test = 1;
    string s;

    while (cin >> s) {
        int n = s.length();
        vector<int> nextDiff(n, n);

        // Preprocessing
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] != s[i + 1]) nextDiff[i] = i + 1;
            else nextDiff[i] = nextDiff[i + 1];
        }

        int t;
        cin >> t;

        cout << "Case " << test << ":\n";

        while (t--) {
            int x, y;
            cin >> x >> y;

            if (x > y) swap(x, y);

            // Query Processing
            cout << ((nextDiff[x] > y) ? "Yes\n" : "No\n");
        }
        test++;
    }

    return 0;
}