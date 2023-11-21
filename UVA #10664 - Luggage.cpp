#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int t;

    cin >> t;
    cin.ignore();

    while(t--)
    {
        int n, sum = 0;
        vector<int> v;

        string line;
        getline(cin, line);
        istringstream iss(line);

        while(iss >> n)
        {
            sum += n;
            v.push_back(n);
        }

        if(sum % 2 != 0)
        {
            cout << "No\n";
            continue; 
        }

        int half  = sum / 2;

        vector<int> dp(half + 1, false);
        dp[0] = true;

        for(int num : v)
        {
            for(int j = half ; j >= num; --j)
            {
                if(dp[j - num]) dp[j] = true;
            }
        }
        if(dp[half]) cout << "Yes"<< endl;
        else cout << "No" << endl;
    }

    return 0;
}