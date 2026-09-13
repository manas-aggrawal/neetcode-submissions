class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        set<int>s(nums.begin(), nums.end());
        int count = 1;
        int mx = 1;
        for(auto i = next(s.begin()); i != s.end(); i++){
            if((*i) - (*prev(i)) == 1) count++;
            else {
                mx = max(count, mx);
                count = 1;
            }
        }
        return max(mx, count);
    }
};
