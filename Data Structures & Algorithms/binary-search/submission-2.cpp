class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1 && target==nums[0]) return 0;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int n = l+((r-l)/2);
            if(target==nums[n]){
                return n;
            }else if(target>nums[n]){
                l=n+1;
            }else{
                r=n-1;
            }
        }
        return -1;
    }
};
