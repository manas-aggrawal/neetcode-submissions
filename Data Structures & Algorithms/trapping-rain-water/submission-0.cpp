class Solution {
public:
    int trap(vector<int>& h) {
        int l=0;
        int r=h.size()-1;
        int lmax=h[l];
        int rmax=h[r];
        int res=0;
        while(l<r){
            if(lmax<rmax){
                ++l;
                lmax=max(lmax,h[l]);
                res+=lmax-h[l];
            }else{
                --r;
                rmax=max(rmax,h[r]);
                res+=rmax-h[r];
            }
        }
        return res;
    }
};
