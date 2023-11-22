#include <iostream>
#include <vector>
#include <string>
using namespace std;

string bigMul(string a, string b) {
    int n = a.size(), m = b.size();

    vector<int> A(n), B(m), res(n + m, 0);

    // Reverse the strings and convert to int vectors
    for (int i = 0; i < n; ++i) {
        A[n - 1 - i] = a[i] - '0';
    }
    for (int i = 0; i < m; ++i) {
        B[m - 1 - i] = b[i] - '0';
    }

    // Perform the multiplication
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i + j] += A[i] * B[j];
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }

    // Remove leading zeros
    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

    // Convert the result to string
    string result = "";
    for (int i = res.size() - 1; i >= 0; --i) {
        result.push_back(res[i] + '0');
    }

    return result;
}

int main() {
    
    int n;

    while(cin >> n && n)
    {
        string ans = "1";

        for (int i = n + 2; i <= 2 * n; ++i) {
            ans = bigMul(ans, to_string(i));
        }
        cout << ans << endl;
    }

    return 0;
}
