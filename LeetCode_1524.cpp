#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd = 0, even = 1; // even = 1 to count the empty prefix sum as even
        int prefixSum = 0, result = 0;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                result = (result + odd) % MOD; // Even prefix can extend odd subarrays
                even++;
            } else {
                result = (result + even) % MOD; // Odd prefix can extend even subarrays
                odd++;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr;
    int n, num;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }

    int result = solution.numOfSubarrays(arr);
    cout << "Number of subarrays with an odd sum: " << result << endl;

    return 0;
}
