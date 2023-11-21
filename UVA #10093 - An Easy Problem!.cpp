#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main()
{
    string str;
    ll sum;
    int tmp, base;

    while(getline(cin, str))
    {
        sum = 0;
        base = 1;
        tmp = 0;

        for(char c : str)
        {
            if(isdigit(c)) tmp = c - '0';

            else if(isupper(c)) tmp = c - 'A' + 10;

            else if(islower(c)) tmp = c - 'a' + 36;

            else continue;

            sum += tmp;

            if(base < tmp) base = tmp;
        }

        bool flag = false;

        for(int i = base; i < 62; i++)
        {
            if(sum % i == 0)
            {
                flag = true;
                cout << i + 1 << endl;
                break;
            }
        }

        if(!flag) cout << "such number is impossible!\n";
    }
    
    return 0;
}