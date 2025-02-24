#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> bobPath;
    unordered_map<int, int> bobTime;

    // Find Bob's path from his node to the root (node 0)
    bool findBobPath(int node, int parent, int bob) {
        if (node == bob) {
            bobPath.push_back(node);
            return true;
        }
        for (int neighbor : adj[node]) {
            if (neighbor != parent && findBobPath(neighbor, node, bob)) {
                bobPath.push_back(node);
                return true;
            }
        }
        return false;
    }

    // DFS to calculate the most profitable path for Alice
    int dfs(int node, int parent, vector<int>& amount, int time) {
        int aliceGain = 0;

        // Determine profit based on when Alice and Bob reach the node
        if (bobTime.find(node) == bobTime.end()) {
            // Bob never reaches this node, Alice takes the full amount
            aliceGain = amount[node];
        } else if (bobTime[node] > time) {
            // Alice reaches first
            aliceGain = amount[node];
        } else if (bobTime[node] == time) {
            // Both arrive simultaneously, split the amount
            aliceGain = amount[node] / 2;
        } else {
            // Bob reaches first, Alice gets nothing
            aliceGain = 0;
        }

        // Explore child nodes
        int maxChildGain = INT_MIN;  // To handle negative paths properly
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                maxChildGain = max(maxChildGain, dfs(neighbor, node, amount, time + 1));
            }
        }

        // If it's a leaf node, return its profit
        if (maxChildGain == INT_MIN) {
            return aliceGain;
        }

        // Add the current node's gain to the best child path gain
        return aliceGain + maxChildGain;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n);

        // Build the adjacency list for the tree
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Find Bob's path to root and record his arrival times
        findBobPath(0, -1, bob);
        int time = 0;
        for (int node : bobPath) {
            bobTime[node] = time++;
        }

        // Perform DFS for Alice's path and profit calculation
        return dfs(0, -1, amount, 0);
    }
};

int main() {
    Solution solution;

    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};
    int bob = 3;
    vector<int> amount = {-5644, -6018, 1188, -8502};

    int result = solution.mostProfitablePath(edges, bob, amount);
    cout << "Most Profitable Path Value: " << result << endl;

    return 0;
}
