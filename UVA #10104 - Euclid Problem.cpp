#include <iostream>
using namespace std;

void extEuclid(int a, int b, int &x, int &y, int &gcd) {

    if (b == 0) { x = 1; y = 0; gcd = a; return; }
    
    extEuclid(b, a % b, x, y, gcd);

    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() {

    int a, b, x, y, gcd;

    while(cin >> a >> b)
    {
        extEuclid(a, b, x, y, gcd);
        
        cout << x << " " << y << " " << gcd << endl;
    }

    return 0;
}
