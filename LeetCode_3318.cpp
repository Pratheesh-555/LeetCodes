class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sum  = 0;
            unordered_map<int, int> mp;
            if(i+k > n ) continue;
            for(int j  = i; j  < i+k ; j++){   
                mp[nums[j]]++;
            }

            vector<pair<int,int>> temp;

            for(auto& it: mp){
                temp.push_back({it.second, it.first});
            }

            sort(temp.begin(), temp.end(), [] (auto& a, auto& b){
                if(a.first == b.first) return a.second > b.second;
                return a.first  >b.first;
            });

            for(int k = 0; k < x && k < temp.size(); k++){
                sum += temp[k].first*temp[k].second;
            }
            res.push_back(sum);
        }
        return res;
    }
};