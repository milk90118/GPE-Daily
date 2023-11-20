#include <iostream>
#include <string>
using namespace std;

int digitSum(const string& str)
{

    if(str.size() == 1) return (str[0] - '0');

    int sum = 0;
    for(int i = 0; i < str.size(); ++i)
    {
        sum += str[i] - '0';
    }

    string ss = to_string(sum);

    return digitSum(ss);
}

int main()
{
    string s;

    while(cin >> s && str[0] != 0)
    {
        int res = digitSum(s);
        cout << res << endl;
    }

    return 0;
}

