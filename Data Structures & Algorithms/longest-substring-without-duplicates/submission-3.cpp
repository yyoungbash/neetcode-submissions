class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char> str;
        int num = 0;

        for(auto c : s) {
            while (find(str.begin(), str.end(), c) != str.end()) {
                str.pop_front();
            }
            str.push_back(c);
            num = max(num, (int)str.size());
        }
        return num;
    }
};
