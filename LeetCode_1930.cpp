class Solution {
public:
    // string word(int idx, string s, string &temp){
        //  for(int k = i+1; k < j; k++){
        //            if(s[i] == s[j]){
        //              string t = "";
        //             t+= s[i];
        //             t += s[k];
        //             t += s[j];
        //             set.insert(t);
        //            }
        //         }
    // }
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> mp;
        unordered_set<string> set;
        for(char ch : s){
            mp[ch]++;
        }
        int n = s.size();
        int res = 0;
        // for(int i = 0 ; i < n-2; i++){
        //     mp[s[i]]--;
        //     if(mp[s[i]] <= 0) mp.erase(s[i]);
        //     for(int j = n-1; j >= i+2; j--){
        //        mp[s[j]]--;
        //        if(mp[s[j]] <= 0) mp.erase(s[j]);
        //        if(s[i] == s[j]){
        //         res += (mp.size());
        //        }
        //     }
        // }
         for(char c = 'a'; c <= 'z'; c++) {
        int i = 0, j = n - 1;
        
        while(i < n && s[i] != c) i++;
        while(j >= 0 && s[j] != c) j--;
        
        if(i < j) {
            unordered_set<char> mid;
            for(int k = i + 1; k < j; k++) {
                mid.insert(s[k]);
            }
            res += mid.size();
        }
    }
        return res;
    }
};