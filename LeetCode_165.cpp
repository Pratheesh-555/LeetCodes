class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        string temp = "";
        for(int i = 0; i < version1.size(); i++){
            if(version1[i] == '.'){
                v1.push_back(stoi(temp));
                temp = "";
            }
            else if(i == version1.size()-1){
                temp+=version1[i];
                v1.push_back(stoi(temp));
            }
            else{
                temp+=version1[i];
            }
        }
        temp = "";
        for(int i = 0; i < version2.size(); i++){
            if(version2[i] == '.'){
                v2.push_back(stoi(temp));
                temp = "";
            }
            else if(i == version2.size()-1){
                temp+=version2[i];
                v2.push_back(stoi(temp));
            }
            else{
                temp+=version2[i];
            }
        }
        int n = v1.size() - v2.size();
        if(n < 0) n = -n;
        for(int i = 0; i < n; i++){
            if(v1.size() > v2.size()){
                v2.push_back(0);
            }
            else{
                v1.push_back(0);
            }
        }
        n = v1.size();

        for(int i = 0; i < n; i++){
            if(v1[i] < v2[i]) return -1;
            else if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};