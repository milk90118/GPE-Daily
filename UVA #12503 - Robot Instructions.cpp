#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();

        vector<char> v;

        int p = 0;

        for (int i = 0; i < n; ++i)
        {
            string line, dir;
            getline(cin, line);
            istringstream iss(line);

            while (iss >> dir)
            {
                if (dir == "LEFT") v.push_back('L');
                else if (dir == "RIGHT") v.push_back('R');
            
                else if (dir == "SAME")
                {
                    string AS;
                    iss >> AS;

                    int step;
                    iss >> step;

                    step--;

                    if(step < v.size())
                    {
                        if(v[step] == 'L')  v.push_back('L');
                        else if(v[step] == 'R') v.push_back('R');
                    }
                    
                }
            }
        }
        
        for(char c : v)
        {
            if(c == 'L') p--;
            else if(c == 'R') p++;
        }

        cout << p << endl;
    }

    return 0;
}
