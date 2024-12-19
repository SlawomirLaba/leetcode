class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> data;
        for (int i = 0 ; ; ++i) {
            auto it = data.find(target - nums[i]);
            if (it != std::end(data)) {
                return { it->second, i };
            } else {
                data[nums[i]] = i;
            }
        }
    }
};