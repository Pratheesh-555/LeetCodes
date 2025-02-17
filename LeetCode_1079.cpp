#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int numTilePossibilities(string tiles) {
            vector<int> frequency(26, 0);
            for(char c:tiles)
                frequency[c-'A']++;
            return backtrack(frequency);
        }

        int backtrack(vector<int>& frequency){
            int count =0;

            for(int i = 0; i < 26; i++){
                if(frequency[i] > 0){
                    count++;
                    frequency[i]--;
                    count = count + backtrack(frequency);
                    frequency[i]++;
                }
            }
            return count;
        }
    };

int main(){
    Solution solution;
    string tile;
    cout<<"Enter the tile : " ;
    cin>>tile;
    cout<<solution.numTilePossibilities(tile);
}