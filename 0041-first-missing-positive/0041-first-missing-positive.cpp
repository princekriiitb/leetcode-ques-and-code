class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int mini=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0)
            continue;
            else
            mini=min(mini,nums[i]);
            if(mini==nums[i]) mini++;
        }
        return mini;
    }
};