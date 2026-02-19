// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         int n = s.size();
//         int res = 0;
//         for(int i =0; i < n; i++){
//             int zero = 0;
//             int one = 0;
//             int j = i;
//             if(s[j] == '0'){
//                 while(s[j] == '0'){
//                     zero++;
//                     j++;
//                 }
//                 while(s[j] == '1'){
//                     one++;
//                     j++;
//                     if(one == zero) res++;
//                 }
                
//             }
//             else{
//                 while(s[j] == '1'){
//                     one++;
//                     j++;
//                 }
//                 while(s[j] == '0'){
//                     zero++;
//                     j++;
//                     if(one == zero) res++;
//                 }
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int countBinarySubstrings(string& s) {
        const int n=s.size();
        int prev=0, cur=1, cnt=0;
        for(int i=1; i<n; i++){
            bool same=s[i]==s[i-1];
            prev=(-same & prev)+(-!same & cur);
            cur=1+(-same & cur );
            cnt+=cur<=prev;
        }
        return cnt;
    }
};