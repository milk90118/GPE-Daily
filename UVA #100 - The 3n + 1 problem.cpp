#include <iostream>
#include <vector>
using namespace std;

int cnt;

void solve(int n)
{
    //cout << n << " ";
    cnt++;

    if(n == 1) return;

    if(n % 2 == 1) n = 3 * n + 1;

    else n /= 2;

    solve(n);
}

int main()
{
    int a, b;

    while(cin >> a >> b)
    {
        int max_cnt = 0;
        for(int i = min(a, b); i <= max(a, b); ++i)
        {
            cnt = 0;
            solve(i);

            if(cnt > max_cnt)
            {
                max_cnt = cnt;
            }
        }

        cout << a  << " " << b << " " << max_cnt << endl;
    }

    return 0;
}