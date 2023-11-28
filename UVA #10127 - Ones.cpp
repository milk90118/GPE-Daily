#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int num = 1, cnt = 1;

        while (num % n != 0) {
            num = (num * 10 + 1) % n;
            cnt++;
        }

        cout << cnt << "\n";
    }
    return 0;
}
