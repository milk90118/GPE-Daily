#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test, n;
    cin >> test;

    while(test--)
    {
        cin >> n;
        
        vector<int> v(n);

        for(int i = 0; i < n; ++i) cin >> v[i];

        int cnt = 0;
            
        for(int i = 0; i < n - 1; ++i)
        {
            for(int j = 0; j < n - i - 1; ++j)
            {
                if(v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                    cnt++;
                }
            }
        }
            
        cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
        
    }
    return 0;
}