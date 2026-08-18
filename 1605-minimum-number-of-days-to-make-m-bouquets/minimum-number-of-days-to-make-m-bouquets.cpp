class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                noOfB += cnt / k;
                cnt = 0;
            }
        }
        noOfB += cnt / k;
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int val = m * 1LL * k * 1LL;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        if (val > bloomDay.size())
            return -1;
        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1; // bcz we have to find the smallest one
            } else {
                low = mid + 1; // else we have to go right it is obvious
            }
        }
        return low;
    }
};