// class Solution {
// public:
//     string fractionToDecimal(int numerator, int denominator) {
        
//         int num = numerator%denominator;
        
//         int ans = numerator/denominator;
//         if(num == 0){
//             return to_string(ans);
//         }
//         unordered_map<int, int> mp;
//         string res = to_string(ans)+".";
//         string temp = "";
//         num = num*10;
//         while((num >= 1) && ((num%denominator)!=0)){
//             while(num <= denominator){
//                 num = num*10;
//                 temp += "0";
//             }
//             int rem = num%denominator;
//             if(mp.count(rem)!=0){
//                 int pos = mp[rem];
//                 temp = temp.substr(0,pos) + "(" + temp.substr(pos) + ")" ;
//                 break;
//             }
//             mp[rem] = temp.size();
//             num /= denominator;
//             temp += to_string(num);
//         }
//         return res+temp;
//     }
// };

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";  // ✅ handle 0 case

        long long num = numerator;
        long long den = denominator;

        string res = "";

        // ✅ handle sign separately
        if ((num < 0) ^ (den < 0)) res += "-";
        num = abs(num);
        den = abs(den);

        long long ans = num / den;
        long long rem = num % den;

        if (rem == 0) {
            return res + to_string(ans);
        }

        res += to_string(ans) + ".";
        string temp = "";
        unordered_map<long long, int> mp;

        while (rem > 0) {
            if (mp.count(rem)) {                       // ✅ check remainder before multiplying
                int pos = mp[rem];
                temp = temp.substr(0, pos) + "(" + temp.substr(pos) + ")";
                break;
            }
            mp[rem] = temp.size();                     // ✅ store remainder position

            rem *= 10;                                 // multiply AFTER storing remainder
            temp += to_string(rem / den);              // append quotient
            rem %= den;                                // update remainder
        }

        return res + temp;
    }
};
