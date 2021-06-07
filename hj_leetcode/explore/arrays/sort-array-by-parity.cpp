class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size = nums.size();
        vector<int> ret(size);
        int left = 0, right = size - 1;
        
        for(int i=0; i < size; i++){
            int &ref = (nums[i]%2 == 0) ? ret[left++] : ret[right--];
            ref = nums[i];
        }
        
        return ret;
    }
};