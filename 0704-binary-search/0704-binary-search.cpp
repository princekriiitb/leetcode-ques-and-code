class Solution {
public:

    int bs(vector<int> &arr,int start,int end,int key){
        if(start>end)
        return -1;

        int mid=start+(end-start)/2;

        if(arr[mid]==key)
        return mid;

        if(arr[mid]>key)
        return bs(arr,start,mid-1,key);
        else
        return bs(arr,mid+1,end,key);
    }
    int search(vector<int>& nums, int target) {

        int start=0;
        int end=nums.size()-1;
        int mid=start +(end-start)/2;

        return bs(nums,start,end,target);
        
    }
};