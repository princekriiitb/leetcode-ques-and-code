class Solution {
public:
    int getLucky(string s, int k) {
        string str = "";
        
        // 1. Convert each character to its numerical position in the alphabet
        for (int i = 0; i < s.size(); i++) {
            str += to_string(s[i] - 'a' + 1); 
        }
        
        int ans = 0;
        
        // 2. Perform the digit sum transformation k times
        while (k--) {
            ans = 0;
            // Sum the digits of the current string
            for (int i = 0; i < str.size(); i++) {
                ans += str[i] - '0';
            }
            // Convert the sum back to a string for the next iteration
            str = to_string(ans);
        }
        
        return ans;
    }
};