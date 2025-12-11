class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> rowMap, colMap;

        for(auto &b : buildings) {
            int x = b[0], y = b[1];
            rowMap[y].push_back(x);
            colMap[x].push_back(y);
        }

        for(auto &p : rowMap) sort(p.second.begin(), p.second.end());
        for(auto &p : colMap) sort(p.second.begin(), p.second.end());

        int res = 0;

        for(auto &b : buildings) {
            int x = b[0], y = b[1];

            auto &row = rowMap[y];
            auto &col = colMap[x];

            // find position of x in row
            auto itRow = lower_bound(row.begin(), row.end(), x);
            bool hasLeft = (itRow != row.begin());
            bool hasRight = (itRow != row.end()-1);

            // find position of y in col
            auto itCol = lower_bound(col.begin(), col.end(), y);
            bool hasAbove = (itCol != col.begin());
            bool hasBelow = (itCol != col.end()-1);

            if(hasLeft && hasRight && hasAbove && hasBelow) res++;
        }

        return res;
    }
};