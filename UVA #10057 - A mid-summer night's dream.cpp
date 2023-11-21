#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v(n);

        for(int i = 0; i < n; ++i) cin >> v[i];

        sort(all(v));

        int x = n / 2;
        int mid, possible;
        int cnt = 0;

        if(n % 2 == 1)
        {
            mid = v[x];
            cnt = upper_bound(all(v), mid) - lower_bound(all(v), mid);
            possible = 1;
        }
        else
        {
            mid = v[x - 1];
            cnt = upper_bound(all(v), v[x]) - lower_bound(all(v), mid);
            possible = v[x] - mid + 1;
        }

        cout << mid << " " << cnt << " " << possible << endl;
    }

    return 0;
}