class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int l = 0;
        int r = n.size()-1;
        while(l<r){
            int s = n[l]+n[r];
            if(s==t) return {l+1, r+1};
            else if(s<t) l++;
            else r--;
        }
        return {};
    }
};
