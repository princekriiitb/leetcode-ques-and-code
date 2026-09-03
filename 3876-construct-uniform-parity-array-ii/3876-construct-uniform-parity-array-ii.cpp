class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int min=nums1[0];
       bool has_odd=false;
       for(int x:nums1){
           if(x<min)
           min=x;

           if(x%2!=0)
           has_odd=true;
       }

       if(!has_odd || min%2 !=0)
       return true;
       else
       return false;

        
       
    }
};