// class Solution {
// public:
//     int countTrapezoids(vector<vector<int>>& points) {
//         set<pair<int, int>> s;

//         for(auto& it: points){
//             for(auto& jt: points){
//                 if(it!=jt){
//                     if(it[0] == 0 && jt[0] == 0)
//                         if(it[1] == jt[1]){
//                             s.insert({{it[0], it[1]}, {jt[0], jt[1]}});
//                         s.insert({{jt[0], jt[1]}, {it[0], it[1]}});
//                         }
                            
//                     if(it[0] == 0 || jt[0] == 0)
//                         continue;
//                     if(jt[1]/jt[0] == it[1]/it[0]){
//                         s.insert({{it[0], it[1]}, {jt[0], jt[1]}});
//                         s.insert({{jt[0], jt[1]}, {it[0], it[1]}});
//                     }
                        
//                 }
//             }
//         }

//         return (s.size()/2)*(points.size()-2)-1;
//     }
// };
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> t, v;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx < 0 || (dx == 0 && dy < 0))
                    dx = -dx, dy = -dy;

                int g = std::gcd(dx, std::abs(dy));

                int sx = dx / g;
                int sy = dy / g;

                int des = sx * points[i][1] - sy * points[i][0];

                int key1 = (sx << 12) | (sy + 2000);
                int key2 = (dx << 12) | (dy + 2000);

                ++t[key1][des];
                ++v[key2][des];
            }
        }

        return count(t) - count(v) / 2;
    }

    int count(unordered_map<int, unordered_map<int, int>>& mp) {
        long long ans = 0;

        for (auto& [k1, inner] : mp) {
            long long sum = 0;
            for (auto& [k2, val] : inner)
                sum += val;

            for (auto& [k2, val] : inner)
                ans += val * (sum -= val);
        }

        return ans;
    }
};