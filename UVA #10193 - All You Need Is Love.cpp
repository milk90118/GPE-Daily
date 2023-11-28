#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int binToDec(const string &bin) {

    int decimal = 0;

    for (char digit : bin) {
        decimal = decimal * 2 + (digit - '0');
    }
    return decimal;
}

int main() {
    
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {

        string s1, s2;
        cin >> s1 >> s2;

        int a = binToDec(s1);
        int b = binToDec(s2);

        cout << "Pair #" << i << ": " << (gcd(a, b) == 1 ? "Love is not all you need!" : "All you need is love!") << endl;
    }

    return 0;
}