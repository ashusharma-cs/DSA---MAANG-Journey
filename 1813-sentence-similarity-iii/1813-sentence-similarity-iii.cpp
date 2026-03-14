class Solution {
public:

    vector<string> splitWords(string s)
    {
        vector<string> words;
        string word;

        stringstream ss(s);


        while(ss>>word)
        {
            words.push_back(word);
        }

        return words;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> s1=splitWords(sentence1);
        vector<string> s2=splitWords(sentence2);

        if(s2.size()<s1.size())
        {
            swap(s1,s2);
        }

        int l=0;
        int r1=s1.size()-1;
        int r2=s2.size()-1;

        while(l<=r1 && s1[l]==s2[l])
        {
            l++;
        }

        while(l<=r1 && s1[r1]==s2[r2])
        {
            r1--;
            r2--;
        }

        return l>r1;


        
    }
};