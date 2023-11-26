#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_N = 1e5 + 5;
int parent[MAX_N];

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {

    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {

        cin >> n;
        cin.ignore();
        
        for (int i = 1; i <= n; i++) parent[i] = i;
    
        string line;
        int yes = 0, no = 0;

        while (getline(cin, line) && !line.empty()) {
            char ch;
            int a, b;

            sscanf(line.c_str(), "%c %d %d", &ch, &a, &b);

            if (ch == 'c') union_sets(a, b);
        
            else if (ch == 'q') 
            {
                yes += (find_set(a) == find_set(b));
                no += (find_set(a) != find_set(b));
            }
        }
        
        cout << yes << "," << no << "\n";

        if (t) {
            cout << "\n";
        }
    }
    return 0;
}
