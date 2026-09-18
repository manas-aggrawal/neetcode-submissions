class Solution {
   public:
    int trap(vector<int>& h) {
        // int l=0;
        // int r=h.size()-1;
        // int lmax=h[l];
        // int rmax=h[r];
        // int res=0;
        // while(l<r){
        //     if(lmax<rmax){
        //         ++l;
        //         lmax=max(lmax,h[l]);
        //         res+=lmax-h[l];
        //     }else{
        //         --r;
        //         rmax=max(rmax,h[r]);
        //         res+=rmax-h[r];
        //     }
        // }
        // return res;

        /* Method 2 */
        int n = h.size();
        if (n == 0) {
            return 0;
        }

        vector<int> lmax(n);
        vector<int> rmax(n);

        lmax[0] = h[0];
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], h[i]);
        }

        rmax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], h[i]);
        }

        int res = 0;
        for (int i = 0; i < h.size(); i++) {
            res += min(lmax[i], rmax[i]) - h[i];
        }
        return res;
    }
};
