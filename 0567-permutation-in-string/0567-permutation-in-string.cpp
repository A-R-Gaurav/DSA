class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        int freq[26] = {0};

        // Frequency of characters in s1
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();
        int windFreq[26] = {0};

        // First window
        for (int i = 0; i < s2.length(); i++) {

            // Add current character
            windFreq[s2[i] - 'a']++;

            // Remove character outside the window
            if (i >= windSize) {
                windFreq[s2[i - windSize] - 'a']--;
            }

            // Check when window size becomes equal to s1
            if (i >= windSize - 1) {
                if (isFreqSame(freq, windFreq)) {
                    return true;
                }
            }
        }

        return false;
    }
};