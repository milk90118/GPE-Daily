#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n;

    while(cin >> n && n != 0)
    {
        cin.ignore();

        unordered_map<string, int> mp;

        int maxCNT = 0;

        for(int i = 0; i < n; ++i)
        {
            string line;
            getline(cin, line);
            istringstream iss(line);

            vector<int> v(5);

            for(int i = 0; i < 5; ++i) iss >> v[i];

            sort(v.begin(), v.end());

            string str = "";

            for(int num : v) str += to_string(num);

            mp[str]++;
            maxCNT = max(maxCNT, mp[str]);
        }

        int ans = 0;

        for(const auto& pa : mp)
        {
            if(pa.second == maxCNT) ans += pa.second;
        }

        cout << ans << endl;
    }

    return 0;
}
