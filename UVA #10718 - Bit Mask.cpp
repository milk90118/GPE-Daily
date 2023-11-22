#include <iostream>
using namespace std;

int main()
{
    unsigned int N, L, R, ans;

    while(cin >> N >> L >> R)
    {
        ans = 0;

        for(int i = 31; i >= 0; --i)
        {
            unsigned int bit = 1 << i;

            if((ans | bit) > R) continue;
            if((ans | bit) <= L || !(N & bit)) ans |= bit;
        }

        cout << ans << endl;
    }

    return 0;
}