// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int m = a.size();
//         int n = b.size();
//         int i = m-1, j = n-1;
//         string res = "", carry = "";
//         string temp = "";
//         while(i > 0 && j > 0){
//             if(a[i] == 1 && b[j] == 1){
//                 carry = "1";
//                 res += "0";
//             }
//             else if(a[i] == 0 && b[j] == 0){
//                 carry = "0";
//                 res += "0";
//             }
//             else{
                
//             }
//         }
//     }
// };



class Solution {
public:
    string addBinary(string a, string b) {
        string &res = (a.size() >= b.size()) ? a : b; //choose larger string as output
        int i = a.size() - 1, j = b.size() - 1;
        int k = res.size() - 1;
        int C = 0;

        while (k >= 0) {
            int A = i < 0 ? 0 : a[i] & 1; // '0' & 1 = 0, '1' & 1 = 1
            int B = j < 0 ? 0 : b[j] & 1; //

            int S = (A ^ B) ^ C; 
            int C_out = ((A ^ B) & C) | (A & B);

            res[k] = S + '0'; //char conversion

            C = C_out;
            i--; j--; k--; //decrement pointers
        }

        return C ? (res.insert(res.begin(), '1'), res) : res;
    }
};
