class Solution {
public:
    unordered_map<int,int> mp;
    bool isHappy(int n) {
        if (n == 1){
            return true;
        }
        else if (mp.find(n) != mp.end()){
            return false;
        }
        else{
            mp[n]++;
            n = sumOfSquares(n);
            return isHappy(n);
        }
        return false;
    }

    int sumOfSquares(int n) {
        int output = 0;

        while (n > 0) {
            int digit = n % 10;
            digit = digit * digit;
            output += digit;
            n /= 10;
        }
        return output;
    }
};
