class Solution {
public:
      int f(int num){
        if(num<=9)
        return num;

        int d=num%10;
        num/=10;
        num+=d;
        return f(num);
      }
    int addDigits(int num) {
        return f(num);
    }
};