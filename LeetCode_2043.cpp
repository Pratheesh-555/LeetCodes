class Bank {
public:

     vector<long long> bal;
     int n;
    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }
    bool isValid(int acc){
        if(acc >=1 && acc <= n) return true;
        return false;
    }    
    bool transfer(int account1, int account2, long long money) {
        
        if(isValid(account1) && isValid(account2) && bal[account1-1] >= money){
            bal[account2-1] += money;
            bal[account1-1] -= money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(!isValid(account)) return false;
        bal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account)) return false;
        if(bal[account-1] >= money){
            bal[account-1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */