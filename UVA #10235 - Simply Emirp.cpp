#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool checkPrime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverse(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main() {
    int n;
    while (cin >> n) {
        if (checkPrime(n)) 
        {
            int rev = reverse(n);

            if (n != rev && checkPrime(rev)) {
                cout << n << " is emirp.\n";
            } 
            else {
                cout << n << " is prime.\n";
            }
        } 
        
        else {
            cout << n << " is not prime.\n";
        }
    }
    return 0;
}
