class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> s;

        int n = digits.size();

        // Choose 1st digit (hundreds)
        for (int i = 0; i < n; i++) {

            if (digits[i] == 0)
                continue;

            // Choose 2nd digit (tens)
            for (int j = 0; j < n; j++) {

                if (j == i)
                    continue;

                // Choose 3rd digit (units)
                for (int k = 0; k < n; k++) {

                    if (k == i || k == j)
                        continue;

                    // Number must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    s.insert(num);
                }
            }
        }

        return s.size();
    }
};