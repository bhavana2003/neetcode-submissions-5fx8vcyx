class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = 1;
        for(auto p:piles)   m = max(m,p);
        int k = m;
        int l = 1, r = m;
        while (l<=r){
            int mid = (l+r)/2;
            // cout << l << " "<< r << " "<<mid<<endl;
            int hours = 0;
            for(int i=0; i<n; i++){
                hours += (piles[i] + mid - 1) / mid;
                // cout <<hours;
            }
            // cout<<endl;
            if (h >= hours){
                k = min(k, mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return k;
    }
};
