#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int t;

    cin >> t;

    map<string, int> mp;

    while(t--)
    {
        string country, name;
        cin >> country;
        mp[country]++;
        getline(cin, name);
    }

    for(auto &m : mp)
    {
        cout << m.first << " " << m.second << endl;
    }

    return 0;
}
