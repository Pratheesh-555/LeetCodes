#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> result;
        string current;
        backtrack(n, k, result, current);
        return (result.size() >= k) ? result[k - 1] : "";
    }

private:
    void backtrack(int n, int k, vector<string>& result, string& current) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {  // Ensure happy condition
                current.push_back(ch);
                backtrack(n, k, result, current);
                current.pop_back();
                if (result.size() >= k) return; // Stop early if we have enough
            }
        }
    }
};

int main() {
    int n = 3, k = 9;
    Solution sol;
    cout << sol.getHappyString(n, k) << endl;
    return 0;
}
