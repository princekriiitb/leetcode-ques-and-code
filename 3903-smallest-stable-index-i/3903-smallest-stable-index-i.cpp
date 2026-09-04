class Solution {
public:
    int score(vector<int>nums,int n,int i){
        int max=INT_MIN,min=INT_MAX;
        for(int j=0;j<=i;j++){
              if(nums[j]>max)
              max=nums[j];
        }
        for(int j=i;j<n;j++){
            if(nums[j]<min)
            min=nums[j];
        }

        return max-min;
    }
    int value(vector<int>ans){
        int n=ans.size();
        if(n==0)
        return -1;
        else
        return *min_element(ans.begin(),ans.end());
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
       vector <int> ans;
        for(int i=0;i<n;i++){
            s=score(nums,n,i);
            if(s<=k)
            ans.push_back(i);
        }
        return value(ans);
        
    }
};