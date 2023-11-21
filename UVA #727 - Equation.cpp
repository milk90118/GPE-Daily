#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c)
{
    if(c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    return 0;
}

string toPostfix(string infix)
{
    stack<char> s;

    string pf;

    for(char c : infix)
    {
        if(isdigit(c)) pf += c;

        else if(c == '(') s.push(c);

        else if(c == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                pf += s.top();
                s.pop();
            }

            if(!s.empty()) s.pop(); // remove '(' from stack
        }

        else // operator
        {
            while(!s.empty() && prec(s.top()) >= prec(c))
            {
                pf += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty())
    {
        pf += s.top();
        s.pop();
    }

    return pf;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();

    while(n--)
    {
        string line, input;

        while(getline(cin, line) && line.length())
        {
            input += line;
        }

        cout << toPostfix(input) << (n ? "\n\n" : "\n");
    }

    return 0;
}