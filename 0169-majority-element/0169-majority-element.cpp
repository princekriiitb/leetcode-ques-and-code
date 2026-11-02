class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

         unordered_map<int,int>map;

         for(int i=0;i<n;i++){
            map[nums[i]]++;
         }
         int highestElement = nums[0];
       int maxCount = 0;

        
    for (auto const& [element, count] : map) {
        if (count > maxCount) {
            maxCount = count;
            highestElement = element;
        }
    }

    return highestElement;
    }
};