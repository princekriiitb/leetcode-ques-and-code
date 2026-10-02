class Solution {
public:
    bool isPalindrome(int x) {
        int original = x;
        long long newNum = 0;
        while(x>0){
            int lastDigit = x%10;
            newNum = newNum*10 + lastDigit;
            x = x/10;
        }
        if(original == newNum){
            return true;
        }
        else{
            return false;
        }
    }
};