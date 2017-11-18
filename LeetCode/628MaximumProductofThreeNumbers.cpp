/*
Given an integer array, find three numbers 
whose product is maximum and output the maximum product.
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int temp1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int temp2 = nums[0] * nums[1] * nums[size - 1];
        return temp1 > temp2 ? temp1 : temp2;
    }
};