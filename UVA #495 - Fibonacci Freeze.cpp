#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string fib[5011];

string addBigNum(string a, string b)
{
    if(a.length() < b.length()) swap(a, b);

    string res = "";

    long long len1 = a.length();
    long long len2 = b.length();
    int carry = 0;  

    for(int i = 0; i < len2; ++i)
    {
        int sum = a[len1 - 1 - i] - '0' + b[len2 - 1 - i] - '0' + carry;
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
    }

    for(int i = 0; i < len1 - len2; ++i)
    {
        int val = a[i] - '0' + carry;
        carry = val / 10;
        res.push_back(val % 10 + '0');
    }

    if(carry) res.push_back(carry + '0');

    reverse(res.begin(), res.end());
    return res;
}

void fibonacci()
{
    fib[0] = "0";
    fib[1] = "1";

    for(int i = 2; i <= 5002; ++i)
    {
        fib[i] = addBigNum(fib[i - 1], fib[i - 2]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    fibonacci();

    while(cin >> n)
    {
        cout << "The Fibonacci number for "<< n << " is "  << fib[n] << endl;
    }
    return 0;
}