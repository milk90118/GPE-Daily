#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

#define MAX 10005

vector<pair<int, int>> adj[MAX];
vector<bool> visited(MAX, false);
int max_distance;
int farthest_node;

void dfs(int node, int distance) {
    visited[node] = true;
    if (distance > max_distance) {
        max_distance = distance;
        farthest_node = node;
    }
    for (auto &neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            dfs(neighbor.first, distance + neighbor.second);
        }
    }
}

void reset() {
    for (int i = 0; i < MAX; ++i) {
        adj[i].clear();
    }
    fill(visited.begin(), visited.end(), false);
    max_distance = 0;
    farthest_node = 0;
}

int main() {
    string line;
    bool is_new_test_case = true;
    
    while (getline(cin, line)) {
        if (line.empty()) {
            // End of a test case
            if (!is_new_test_case) {
                
                dfs(1, 0);
                fill(visited.begin(), visited.end(), false);
                max_distance = 0;
                
                dfs(farthest_node, 0);
                cout << max_distance << endl;
            }
            // Reset for the next test case
            reset();
            is_new_test_case = true;
        } else {
            
            istringstream iss(line);
            int u, v, w;
            iss >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            is_new_test_case = false;
        }
    }
    
    // Handle the last test case if the input doesn't end with an empty line
    if (!is_new_test_case) {
        dfs(1, 0);
        fill(visited.begin(), visited.end(), false);
        max_distance = 0;
        dfs(farthest_node, 0);
        cout << max_distance << endl;
    }

    return 0;
}
