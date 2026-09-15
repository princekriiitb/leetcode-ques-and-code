class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> seen;
        for(int i:nums){
            seen[i]++;
        }
       int x=0;
        for(int i:nums){
            if(seen[i]>1){
                x=i;
            }
        }
        return x;
    }
};