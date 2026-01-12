// class Solution {
// public:
//     int minTimeToVisitAllPoints(vector<vector<int>>& points) {
//         int res = 0;

//         for(int i = 1; i < points.size(); i++){
//             int x1 = points[i-1][0];
//             int y1 = points[i-1][1];
//             int x2 = points[i][0];
//             int y2 = points[i][1];
//             res += int(sqrt(abs((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)))); 
//         }
//         return res;
//     }
// };
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 1; i < points.size(); i++) {
            int x1 = points[i-1][0], y1 = points[i-1][1];
            int x2 = points[i][0], y2 = points[i][1];
            res += max(abs(x1 - x2), abs(y1 - y2));
        }
        return res;
    }
};