#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int stringToNumber(string s)
    {
        int num = 0; 
        for (char c : s)
        {
            num = num * 10 + (c - '0');
        } 
        return num;
    }

    bool canPartition(string num, int target, int index = 0, int tempSum = 0)
    {
        if (index == num.length())
            return tempSum == target;

        for (int i = index; i < num.length(); i++)
        {
            int part = stringToNumber(num.substr(index, i - index + 1));
            if (canPartition(num, target, i + 1, tempSum + part))
                return true;
        }
        return false;
    }

    int punishmentNumber(int n)
    {
        int total = 0;
        for (int i = 1; i <= n; i++)
        {
            string num = to_string(i * i);
            if (canPartition(num, i))
                total += (i * i);
        }
        return total;
    }
};

int main()
{
    Solution S;
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Punishment Number: " << S.punishmentNumber(n) << endl;
    return 0;
}
