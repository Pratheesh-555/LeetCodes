#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
    public:
        string smallestNumber(string pattern) {
            stack<int> st;
            string res = "";
            for(int i = 0; i <= pattern.length(); i++){
                st.push(i +1);
                if(pattern.length() == i || pattern[i] == 'I'){
                    while(!st.empty()){
                        res = res + to_string(st.top());
                        st.pop();
                    }
                }
            }
            return res;
        }
    };

int main(){
    Solution solution;
    string pattern;
    cout<<"Enter the ID string: ";
    cin>>pattern;
    cout<<solution.smallestNumber(pattern)<<endl;
    return 0;
}