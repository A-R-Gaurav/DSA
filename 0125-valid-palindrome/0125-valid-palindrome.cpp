class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size() - 1;

        while (st < end) {

            // Skip non-alphanumeric characters
            while (st < end && !isalnum(s[st])) {
                st++;
            }

            while (st < end && !isalnum(s[end])) {
                end--;
            }

            // Compare after converting to lowercase
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};