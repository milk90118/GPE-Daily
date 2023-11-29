#include <iostream>
using namespace std;

int main()
{
    int N;

    while(cin >> N && N)
    {
        for(int m = 1; m <= N; ++m)
        {
            int p = 1;

            for(int i = 1; i < N; ++i)
            {
                p = (p + m) % i;
            }

            if(p == 11)
            {
                cout << m << endl;
                break;
            }
        }
    }
    return 0;
}