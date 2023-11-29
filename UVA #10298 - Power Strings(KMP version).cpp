#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> KMP(const string& str)
{
    int len = str.length();

    vector<int> prefix(len + 1);

    prefix[0] = 0;

    int idx = 0;

    for(int k = 1; k < len; ++k)
    {
        while(idx > 0 && str[idx] != str[k])
        {
            idx = prefix[idx - 1];
        }

        if(str[idx] == str[k]) idx++;

        prefix[k] = idx;
    }

    return prefix;
}

int main()
{
    string s;

    while(getline(cin, s))
    {
        if(s == ".") break;

        vector<int> pre = KMP(s);

        int n = s.length();

        int pattern = n - pre[n - 1];

        int rep = n / pattern;

        printf("%d\n", rep);
    }
    
    return 0;
}