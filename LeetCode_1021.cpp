class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        int close = 0;
        string res = "";
        string temp = "";
        for(char ch : s){
            if(ch == '('){
                open++;
                if(open > 1) temp += ch;
            }
            else{
                close++;
                if(open == close){
                    open = 0;
                    close = 0;
                    res += temp;
                    temp = "";
                    continue;
                }
                temp+= ch;
            }
        }
        return res;
    }
};