class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        for(int n: nums){
            if(n==0) zeroCount++;
        }
        cout<<zeroCount;
        if(zeroCount>=2) {
            vector<int>v(nums.size(), 0);
            return v;
        }
        int pro = 1;
        for(int n: nums){
            if(n!=0)
                pro*=n;
        }
        if(zeroCount==1){
            vector<int>v(nums.size(), 0);
            for(int i=0; i<nums.size(); i++){
                if(nums[i]==0) v[i] = pro;
            }
            return v;
        }
        for(int i=0; i<nums.size(); i++){
            nums[i] = pro/nums[i];
        }
        return nums;
    }
};
