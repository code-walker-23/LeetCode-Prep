#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        bool pointOfDiff = false;
        string ans = "";
        sort(s.rbegin(), s.rend());
        if (s <= target) return "";

        for (int i = 0; i < n; i++) {
            bool ok = true;
            string temp = s;

            for (int j = 0; j < i; j++) {
                size_t pos = temp.find(target[j]);
                if (pos != string::npos) {
                    temp.erase(pos, 1);
                } else {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                sort(temp.begin(), temp.end());
                auto p = upper_bound(temp.begin(), temp.end(), target[i]);
                if (p != temp.end()) {
                    char nextChar = *p;
                    temp.erase(p);
                    string str = target.substr(0, i) + nextChar + temp;
                    if (ans == "" || str < ans) ans = str;
                }
            }
        }

        if (ans == "") {
            if (next_permutation(target.begin(), target.end()))
                return target;
            else
                return "";
        }
        return ans;
    }
};