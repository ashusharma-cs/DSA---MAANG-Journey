class Solution {
public:
    string simplifyPath(string path) {

        stringstream ss(path);

        string word;

        vector<string> res;

        while (getline(ss, word, '/')) {
            if (word == "" || word == ".") {

            } else if (word == "..") {

                if (res.size() > 0) {
                    res.pop_back();
                }
            } else {
                res.push_back(word);
            }
        }

        string finalStr;

        for (auto const& str : res) {
            finalStr += "/";
            finalStr += str;
        }

        return (finalStr.size()==0?"/":finalStr);
    }
};