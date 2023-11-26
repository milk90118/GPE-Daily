#include <iostream>
#include <cstring>
using namespace std;

char a[1000001];
char b[2000002];

int main()
{
    while(cin >> a && a[0] != '.')
    {
        int n = strlen(a);

        sprintf(b, "%s%s", a + 1, a); // Form b by concatenating a (excluding first char) with a

        char *search = strstr(b, a); // Find first occurrence of a in b

        int period = search - b; // Calculate pattern length in b
        
        cout << n / (period + 1) << '\n'; // Number of pattern repetitions
    }
    return 0;
}