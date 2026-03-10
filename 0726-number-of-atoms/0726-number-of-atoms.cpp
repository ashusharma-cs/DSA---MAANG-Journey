class Solution {
public:
    string countOfAtoms(string formula) {

        stack<map<string, int>> st;

        map<string, int> currentMap;

        int n = formula.length();
        int idx = 0;

        while (idx < n) {
            if (formula[idx] == '(') {
                st.push(currentMap);
                currentMap.clear();
                idx++;
            } else if (formula[idx] == ')') {
                idx++;
                int multiplier = 0;
                while (idx < n && isdigit(formula[idx])) {
                    multiplier = multiplier * 10 + (formula[idx] - '0');
                    idx++;
                }

                if (multiplier == 0)
                    multiplier = 1;

                map<string, int> prevMap = st.top();
                st.pop();

                for (auto const& [atom, count] : currentMap) {
                    prevMap[atom] += count * multiplier;
                }

                currentMap = prevMap;

            } else {
                string atom = "";

                atom += formula[idx];
                idx++;

                while (idx < n && islower(formula[idx])) {
                    atom += formula[idx];
                    idx++;
                }

                int count = 0;

                while (idx < n && isdigit(formula[idx])) {
                    count = count * 10 + (formula[idx] - '0');
                    idx++;
                }

                if (count == 0)
                    count = 1;

                currentMap[atom] += count;
            }
        }

        string finalStr = "";

        for (auto const& [atom, count] : currentMap) {
            finalStr += atom;

            if (count > 1) {
                finalStr += to_string(count);
            }
        }

        return finalStr;
    }
};