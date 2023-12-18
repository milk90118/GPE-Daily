#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> &a, pair<char, int> &b)
{
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int main()
{
    int t;

    cin >> t;
    cin.ignore();

    map<char, int> mp;

    while(t--)
    {
        string line;

        getline(cin, line);

        for(char c : line)
        {
            if(c >= 'A' && c <= 'Z') mp[c]++;
            else if(c >= 'a' && c <= 'z') mp[c - 'a' + 'A']++;
        }
    }

    vector<pair<char, int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), cmp);

    for(auto& p : v)
    {
        if(p.second >= 1)
            cout << p.first << " " << p.second << endl;
    }

    return 0;
}

