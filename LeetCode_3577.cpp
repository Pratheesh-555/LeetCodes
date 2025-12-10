// class Solution {
// public:
//     int countPermutations(vector<int>& complexity) {
//         int res = 0;
//         for(int i = 1; i < complexity.size(); i++){
//             if(complexity[i] > complexity[i-1]) res++;
//             else{
//                 return 0;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int first = complexity[0];

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= first) return 0;
        }

        long long fact = 1;
        for (int i = 2; i < n; i++) {
            fact = (fact * i) % MOD;
        }

        return (int)fact;
    }
};