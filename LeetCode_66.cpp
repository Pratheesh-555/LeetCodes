// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         string s = "";
//         for(int n : digits){
//             s += n-'0';
//         }
//         int res = stoi(s);
//         res+=1;

//         for(int i = 0; i < digits.size(); i++){
//             digits[i] = s[i]-'a';
//         }
//         return digits;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // no carry needed
                return digits;
            }
            digits[i] = 0;     // carry over
        }
        
        // If all digits were 9, we need an extra digit at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};