class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> ans;
        for (int k = 0; k < nums.size(); k++) {
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int s = nums[k] + nums[i] + nums[j];
                if (s == 0) {
                    ans.insert({nums[k], nums[i], nums[j]});
                    i++;
                    j--;
                } else if (s < 0) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        vector<vector<int>>vec(ans.begin(), ans.end());
        return vec;
    }
};
