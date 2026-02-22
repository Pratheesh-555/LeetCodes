// class Solution {
// public:
//     int binaryGap(int n) {
//         string s = bitset<32>(n).to_string();
//         int res = 0,prev = -1;
//         cout<<s<< " ";
//         for(int i =0; i <  s.size(); i++){
//             if(s[i] == '1'){
//                 prev = i;
//                 break;
//             }
//         }
//         if(prev = -1) return 0;
//         for(int i = prev+1; i < s.size(); i++){
//             if(s[i] == '1'){
//                 res = max(res,i-prev);
//                 prev = i;
//                 cout<<prev<<" ";
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();
        int res = 0, prev = -1;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                if(prev != -1) {
                    res = max(res, i - prev);
                }
                prev = i;
            }
        }
        return res;
    }
};