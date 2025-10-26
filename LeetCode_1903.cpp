class Solution {
public:
    string largestOddNumber(string num) {
        int pos = -1;
        for(int i = num.size(); i >= 0; i--){
            if((num[i]-'0')%2 != 0){
                pos = i;
                break;
            }
        }
        return num.substr(0,pos+1);
    }
};