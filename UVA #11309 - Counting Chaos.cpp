#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> v;

bool isPalindrome(const string& s)
{
    int left = 0; int right = s.size() - 1;

    while(left < right)
    {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }

    return true;
}

void precomp()
{
    for(int h = 0; h < 24; ++h)
    {
        for(int m = 0; m < 60; ++m)
        {
            int t = 100 * h + m;
            string s = to_string(t);

            if(isPalindrome(s)) v.push_back(t);
        }
    }
}

pair<int, int> solve(int h, int m)
{
    int t = 100 * h + m;
    auto it = upper_bound(v.begin(), v.end(), t);

    if(it == v.end()) it = v.begin();

    int nextTime = *it;

    return {nextTime / 100, nextTime % 100};
}

int main()
{
    precomp();
    int t;
    cin >> t;

    while(t--)
    {
        int hr, min;
        char colon;

        cin >> hr >> colon >> min;

        pair<int, int> next = solve(hr, min);

        cout << setw(2) << setfill('0') << next.first << ":";
        cout << setw(2) << setfill('0') << next.second << endl;
    }

    return 0;
}

