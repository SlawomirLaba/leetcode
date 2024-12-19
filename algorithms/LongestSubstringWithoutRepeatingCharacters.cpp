class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> indexes;
        size_t input_size = s.size();
        int low_index = 0;
        int longest = 0;
        for(int i = 0 ; i < input_size ; ++i) {
            auto it = indexes.find(s[i]);
            if (it == std::end(indexes) || it->second < low_index) {
                indexes[s[i]] = i;
            } else {
                int length = i - low_index;
                if (length > longest)
                    longest = length;

                low_index = it->second + 1;
                indexes[s[i]] = i;
            }
        }
        int length = input_size - low_index;
        if (length > longest)
            longest = length;
    
        return longest;
    }
};