class Solution {
public:
     int sum(int n){
        int s=0;
        int p=1;
        while(n>0){
            int x=n%10;
            s+=x;
            p*=x;
            n/=10;
        }

        return s+p;
     }
    bool checkDivisibility(int n) {
        if(n%sum(n)==0)
        return true;
        else
        return false;
        
    }
};