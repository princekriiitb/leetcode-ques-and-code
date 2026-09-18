class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int n=cost.size();
        int sum=0;
         int i;
        for( i=0;i+1<n;i=i+3){
            sum+=cost[i]+cost[i+1];
        }
        if(i<n)
        sum+=cost[i];
        
        return sum;


    }
};