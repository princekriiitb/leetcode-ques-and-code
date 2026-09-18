class Solution {
public:
    int sum(int num){
        int s=0;
        while(num>0){
            s+=num%10;
            num/=10;
        }
        return s;

    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=sum(nums[i]);

        }
         sort(nums.begin(),nums.end());

    return nums[0];
    }
   
};