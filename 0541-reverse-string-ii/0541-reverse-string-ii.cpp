class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += 2 * k) {
            int j = i;
            int p = min(i + k - 1, n - 1);

            while (j < p) {
                swap(s[j], s[p]);
                j++;
                p--;
            }
        }

        return s;
    }
};