// class Solution {
// public:
//     int countCollisions(string directions) {
//         int r = 0;
//         int l = 0;
//         int s = 0;
//         int coll = 0;
//         stack<char> st;
//         for(char ch : directions){
//             if(!st.empty()){
//                 char cur = st.top();
//                 if(ch == 'L' && cur == 'R'){    
//                     coll += 2;
//                     st.push('S');
//                     continue;
//                 }
//                 else if(ch == 'L' && cur == 'S'){
//                     coll += 1;
//                     st.push('S');
//                     continue;
//                 }
//                 else if(ch == 'S' && cur == 'R'){
//                     coll += 1;
//                     st.push('S');
//                     continue;
//                 }
//             }
//             st.push(ch);

//         }
//         return coll;
//     }
// };

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        while (i < n && directions[i] == 'L') i++;
        while (j >= 0 && directions[j] == 'R') j--;

        int collisions = 0;
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S') {
                collisions++;
            }
        }
        
        return collisions;
    }
};