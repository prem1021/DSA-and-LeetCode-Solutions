class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod = prod * nums[j];
                maxProd = max(prod, maxProd);
            }
        }
        return maxProd;
    }
};