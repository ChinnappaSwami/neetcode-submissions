class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0, r = 0;

        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 2 > r - l) {
                l = left + 1;
                r = right - 1;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 2 > r - l) {
                l = left + 1;
                r = right - 1;
            }
        }

        return s.substr(l, r - l + 1);
    }
};