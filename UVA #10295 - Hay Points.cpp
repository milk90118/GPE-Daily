#include <iostream>
#include <map>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    string s;
    int v;
    map<string, int> mp;

    for(int i = 0; i < m; ++i)
    {
        cin >> s >> v;
        mp[s] = v;
    }

    for(int i = 0; i < n; ++i)
    {
        int sum = 0;

        while(true)
        {
            cin >> s;
            if(s == ".") break;

            auto it = mp.find(s);

            if(it != mp.end()) sum += it->second;
        }
        cout << sum << endl;
    }
    return 0;
}