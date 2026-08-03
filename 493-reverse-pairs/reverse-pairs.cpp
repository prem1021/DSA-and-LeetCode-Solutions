class Solution {
public:
    void merge(vector<int>& nums, int s,int mid, int e) {
        vector<int> temp;
        int first = s;
        int second = mid + 1;

        while (first <= mid && second <= e) {
            if (nums[first] < nums[second]) {
                temp.push_back(nums[first]);
                first++;
            } else {
                temp.push_back(nums[second]);
                second++;
            }
        }
        while (first <= mid) {
            temp.push_back(nums[first]);
            first++;
        }
        while (second <= e) {
            temp.push_back(nums[second]);
            second++;
        }
        for (int i = s; i <= e; i++) {
            nums[i] = temp[i - s];
        }
    }
    int countPairs(vector<int>& nums, int s, int mid, int e) {
        int cnt = 0;
        int right = mid + 1;
        for (int i = s; i <=mid; i++) {
            while (right <= e && nums[i] > 2LL * nums[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int s, int e) {
        int cnt = 0;
        int mid = (s + e) / 2;

        if (s >= e) {
            return cnt;
        }

        cnt += mergeSort(nums, s, mid);
        cnt += mergeSort(nums, mid + 1, e);
        cnt += countPairs(nums, s, mid, e);
        merge(nums, s, mid, e);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};