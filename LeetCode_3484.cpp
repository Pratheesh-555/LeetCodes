/*
A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.

Implement the Spreadsheet class:

Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
void resetCell(String cell) Resets the specified cell to 0.
int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.

*/

class Spreadsheet {
public:
    vector<vector<int>> ss;
    Spreadsheet(int rows) {
        ss = vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int j = cell[0]-'A';
        cell.erase(0,1);
        int i = stoi(cell)-1;

        ss[i][j] = value;
    }
    
    void resetCell(string cell) {
        int j = cell[0]-'A';
        cell.erase(0,1);
        int i = stoi(cell)-1;

        ss[i][j] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        int pos = formula.find('+');
        int res = 0;
        string a = formula.substr(0,pos);
        string b = formula.substr(pos+1);
        if(isalpha(a[0])){
            int j = a[0] -'A';
            a = a.substr(1);
            int i = stoi(a)-1;
            res = ss[i][j]; 
        }
        else{
            res = stoi(a);
        }

        if(isalpha(b[0])){
            int j = b[0] -'A';
            b = b.substr(1);
            int i = stoi(b)-1;
            res += ss[i][j]; 
        }
        else{
            res += stoi(b);
        }
        return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */