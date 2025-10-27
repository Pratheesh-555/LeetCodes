class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int prev = 0;
        for(string s:bank){ 
            int cnt = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '1') cnt++;
            }
            if(cnt == 0) continue;
            res += (prev*cnt);
            prev = cnt;
        }
        return res;
    }
};