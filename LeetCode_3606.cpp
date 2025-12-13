class Solution {
public:
    bool check1(string s){
        if(s == "") return false;
        for(char ch : s){
            if(ch == '_') continue;
            if(!isalnum(ch)) return false;
        }
        return true;
    }
    bool check2(string s){
        if( s == "electronics" || s == "grocery" || s == "pharmacy" || s== "restaurant"){
            return true;
        }
        else{
            return false;
        }
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string,string>> valid; // {businessLine, code}

        for(int i = 0; i < n; i++){
            if(check1(code[i]) && check2(businessLine[i]) && isActive[i]){
                valid.push_back({businessLine[i], code[i]});
            }
        }

        // custom order map
        unordered_map<string,int> order = {
            {"electronics",0}, {"grocery",1}, {"pharmacy",2}, {"restaurant",3}
        };

        sort(valid.begin(), valid.end(), [&](auto &a, auto &b){
            if(order[a.first] == order[b.first]) return a.second < b.second;
            return order[a.first] < order[b.first];
        });

        vector<string> res;
        for(auto &p : valid) res.push_back(p.second);
        return res;

    }
};