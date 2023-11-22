#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m)
    {

        vector<int> v(n);

        int max_milk = 0, total = 0, mid;

        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];

            max_milk = max(max_milk, v[i]); // left bound
            total += v[i]; // right bound
        }

        while(max_milk < total)
        {
            mid = (max_milk + total) / 2;

            int cnt = 1; // count the number of containers
            int current = 0; // current milk volume

            for(int i = 0; i < n; ++i)
            {
                if(current + v[i] > mid)
                {
                    cnt++;
                    current = 0;
                }
                current += v[i];
            }

            if(cnt > m) max_milk = mid + 1; // the volume of each container is too small
            else total = mid; // we can find smaller number of containers
        }

        cout << max_milk << endl;
    }

    return 0;
    
}