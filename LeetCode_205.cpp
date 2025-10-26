class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1,mp2;
        int n = s.size();
        if(s.size() != t.size()) return false;

        for(int i = 0; i < n; i++){
            if(mp1.find(s[i]) != mp1.end() || mp2.find(t[i]) != mp2.end()){
                if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i]){
                    return false;
                }
            }
            mp2[t[i]] = s[i];
            mp1[s[i]] = t[i];
        }
        return true;
    }
};