class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        int a=-1,b=-1;

         for(int i=0;i<nums.size();i++){
            if(nums[i]==mini)
            a=i;
            if(nums[i]==maxi)
            b=i;
         }
         int bothfront=max(a,b)+1;
         int bothback=nums.size()-min(a,b);
         int frontback=min(a,b)+1+nums.size()-max(a,b);

         return min({bothfront,bothback,frontback});
    }
};