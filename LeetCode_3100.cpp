class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = 0;
        int full = numBottles;
        int empty = 0;
        while(full > 0){
            full--;
            drunk++;
            empty++;
            
            if(empty >= numExchange){
                full++;
                empty -= numExchange;
                numExchange++;
            }

        }
        return drunk;
    }
};