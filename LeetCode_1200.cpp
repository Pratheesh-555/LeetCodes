class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
         vector<vector<int>> res;
        int n = arr.size();
        int md = INT_MAX;
        for(int i = 1; i < n; i++){
            if(arr[i]-arr[i-1] < md){
                md = arr[i]-arr[i-1];
            }
        }
        int i =0, j = 1;
        while(j<n){
            if(arr[j]-arr[i] == md){
                res.push_back({arr[i],arr[j]});
                i++;
                j++;
            }
            else if(arr[j]-arr[i] < md){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return res;
    }
};