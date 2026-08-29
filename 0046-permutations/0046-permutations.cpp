class Solution {
public:

    void  solve(vector<int>nums,vector<int>output,int index, vector<vector<int>> & ans){

        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            output=nums;
            solve(nums,output,index+1,ans);
            output.clear();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;

        int index=0;

        solve(nums,output,index,ans);
        return ans;
        
    }
};