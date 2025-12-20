// class Solution {
// public:
//     int minDeletionSize(vector<string>& strs) {
//         int cnt = 0;
//         for(int i = 0; i < strs.size(); i++){
//             string temp = strs[i];
//             bool flag = true;
//             if(temp.size() == 1) continue;
//             for(int j = 1; j < temp.size(); j++){
//                 if(temp[j]<temp[j-1]){
//                     continue;
//                 }
//             }
//             if(flag) cnt++;
//         }
//         return cnt;
//     }
// };


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();       // number of rows
        int n = strs[0].size();    // number of columns
        int cnt = 0;

        // Check each column
        for (int col = 0; col < n; col++) {
            for (int row = 1; row < m; row++) {
                if (strs[row][col] < strs[row-1][col]) {
                    cnt++; // column is unsorted
                    break; // move to next column
                }
            }
        }
        return cnt;
    }
};