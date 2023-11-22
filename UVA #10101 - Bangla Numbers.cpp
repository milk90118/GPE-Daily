#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define ll long long

void bn(ll n) {

    if (n >= 10000000) {
        bn(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if (n >= 100000) {
        bn(n / 100000);
        cout << " lakh";
        n %= 100000;
    }
    if (n >= 1000) {
        bn(n / 1000);
        cout << " hajar";
        n %= 1000;
    }
    if (n >= 100) {
        bn(n / 100);
        cout << " shata";
        n %= 100;
    }
    
    if(n) cout << " " << n;
}

int main() {

    ll num;
    int caseNum = 1;

    while (cin >> num) {

        cout << setw(4) << caseNum << ".";
        ++caseNum;

        if(num) bn(num);

        else cout << " 0";

        cout << endl;
    }

    return 0;
}
