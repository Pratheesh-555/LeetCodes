class Solution {
public:
    string addA(string s, int a) {
        for (int i = 1; i < s.size(); i += 2)
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        return s;
    }

    string rotateB(string s, int b) {
        rotate(s.begin(), s.begin() + b, s.end());
        return s;
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        string res = s;
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            res = min(res, cur);

            string op1 = addA(cur, a);
            string op2 = rotateB(cur, b);

            if (!vis.count(op1)) { vis.insert(op1); q.push(op1); }
            if (!vis.count(op2)) { vis.insert(op2); q.push(op2); }
        }
        return res;
    }
};
