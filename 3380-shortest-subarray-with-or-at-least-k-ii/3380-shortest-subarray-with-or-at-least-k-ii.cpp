class Solution {
public:
    long long value(vector<long long> temp) {
        long long res = 0;
        for (int i = 0; i < temp.size(); i++) {
            res = res * 2 + (temp[i] != 0);
        }
        return res;
    }
    void oring(vector<long long>& temp, int num) {
        int i = 31;
        while (num) {
            temp[i--] += num % 2;
            num /= 2;
        }
    }
    void minus(vector<long long>& temp, int num) {
        int i = 31;
        while (num) {
            temp[i--] -= num % 2;
            num /= 2;
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n + 1;
        vector<long long> temp(32, 0);
        oring(temp, nums[0]);
        if (value(temp) >= k)
            return 1;
        for (int i = 0, j = 1; i < n, j < n; j++) {
            oring(temp, nums[j]);
            if (value(temp) >= k) {
                while (i < j and value(temp) >= k) {
                    res = min(res, j - i + 1);
                    minus(temp, nums[i]);
                    i++;
                }
                if (value(temp) >= k)
                    res = min(res, j - i + 1);
            }
        }
        if (res == n + 1)
            return -1;
        return res;
    }
};