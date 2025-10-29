class Solution {
public:
    string bin(int n){
        string s = "";
        while(n != 0){
            int rem = n%2;
            s+= rem + '0';
            n/=2;
        }
        return s;
    }
    int smallestNumber(int n) {
        string s = bin(n);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') s[i] = '1';
        }

        int res = 0;
        int j = 0;
        for(int i = s.size()-1; i >=0; i--){
           if(s[i] == '1'){
                res += 1*pow(2,j);
           }
           j++;
        }
        
        return res;
    }
};