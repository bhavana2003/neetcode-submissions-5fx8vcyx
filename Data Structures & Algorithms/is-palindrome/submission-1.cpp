class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        while (l < r){
            while (l<r && !isValidChar(s[l])) l++;
            while (l<r && !isValidChar(s[r])) r--;

            if (tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++; r--;
        }
        return true;
    }

    bool isValidChar(char c){
        if (c >= 'a' && c <= 'z')   return true;
        if (c >= 'A' && c <= 'Z')   return true;
        if (c >= '0' && c <= '9')   return true;
        return false;
    }
};
