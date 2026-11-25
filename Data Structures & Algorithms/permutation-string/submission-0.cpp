class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char, int> seen, seen2;
       for (char c : s1) {
            seen[c]++;
        }

       for (int i = 0; i < s2.size(); i++) {
        seen2[s2[i]]++;
        if(i >= s1.size()) {
            char l = s2[i-s1.size()];
            seen2[l]--;
            if (seen2[l] == 0) seen2.erase(l);
        }

        if (seen == seen2) return true;
       }
       return false;
    }
};
