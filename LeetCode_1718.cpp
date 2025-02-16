#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> constructDistancedSequence(int n) {
            vector<int> res(2 * n - 1, 0);  // Corrected size
            vector<bool> used(n + 1, false); 
            backtrack(res, used, n, 0);
            return res;
        }
    
    private:
        bool backtrack(vector<int>& res, vector<bool>& used, int n, int index) {
            int size = res.size();
            if (index == size) return true;
    
            if (res[index] != 0) 
                return backtrack(res, used, n, index + 1);
    
            for (int num = n; num >= 1; num--) {
                if (used[num]) continue;
    
                if (num == 1) {
                    res[index] = num;
                    used[num] = true;
                    if (backtrack(res, used, n, index + 1)) return true;
                    res[index] = 0;
                    used[num] = false;
                } 
                else if (index + num < size && res[index + num] == 0) {
                    res[index] = res[index + num] = num;
                    used[num] = true;
    
                    if (backtrack(res, used, n, index + 1)) return true;
    
                    res[index] = res[index + num] = 0;
                    used[num] = false;
                }
            }
            return false;
        }
    };
    

int main() {
    Solution S;
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    vector<int> res = S.constructDistancedSequence(n);
    
    cout << "Lexicographically Largest Valid Sequence: ";
    for (int s : res)
        cout << s << " ";
    
    cout << endl;
    return 0;
}
