class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int p:piles) high=max(high, p);
        int answer=high;
        while (low<=high) {
            int mid=low+(high-low)/2;
            if(Finish(piles,h,mid)) {
                answer =mid;     
                high=mid- 1;  
            }else{
                low = mid + 1;  
            }
        }
        return answer;
    }
private:
    bool Finish(const vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (int p : piles) {
            totalHours += (p + k - 1) / k;
        }
        return totalHours <= h;
    }
};