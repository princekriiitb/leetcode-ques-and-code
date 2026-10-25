class Solution {
public: 
    int sum(int n){
        int s=0;
        while(n>0){
            s+=(n%10) * (n%10);
            n/=10;
        }
        return s;
    }
    bool isHappy(int n) {
        if(n==4)
        return false;  // it forms a loop which can make it to TLE
        if(n==1)
        return true;

        else
        {
            n=sum(n);
            return  isHappy(n);
        }

        return false;
        
    }
};