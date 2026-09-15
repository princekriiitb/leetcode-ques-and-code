class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>map;

        for(int i:nums){
            map[i]++;

        } 
        int ans=0;
        for(int i:nums){
            if(map[i]==1)
            ans=i;
            
        }

     return ans;
    }
};