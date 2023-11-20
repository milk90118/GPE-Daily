#include <iostream>
using namespace std;

int bigMod(int n, int pow, int mod)
{
    if(pow == 0) return 1;
    if(pow == 1) return (n % mod);

    long long mid = bigMod(n, pow / 2, mod);
    mid = (mid * mid) % mod;

    if(pow % 2 == 1)
    {
        mid = (mid * (n % mod)) % mod;
    }

    return mid;
}

int main()
{
    int b, p, m;

    while(cin >> b >> p >> m){

        int ans = bigMod(b, p, m);
        cout << ans << endl;

    }
    return 0;
}