//Link: https://leetcode.com/problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        int a = 0, b = 1, x, i, sum = 0, calc, in = 0;
        vector<int> v;
        for (i = 1; i <= int(s.size()); i++) {
            if (s[i - 1] == '(') {
                v.push_back(i);
            } else {
                if (int(v.size()) == 0) {
                    in = i;
                    continue;
                }
                v.pop_back();
                if (int(v.size())!= 0)
                    x = v[int(v.size()) - 1];
                else
                    x = 0;
                x = max(x, in);
                calc = (i - x);
                if (a < calc) {
                    a = calc;
                } 
            }
        }
        return a;
    }
};
