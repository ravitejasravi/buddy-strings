class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.length() != goal.length())
            return false;

        if(s == goal)
            return equal(s);

        for(int i = 0; i < s.length(); i++) 
            if(s[i] != goal[i])
                for(int j = i + 1; j < goal.length(); j++)
                    if(goal[i] == s[j]) {

                        char third = s[j];
                        s[j] = s[i];
                        s[i] = third;

                        if(s == goal)
                            return true;

                        third = s[j];
                        s[j] = s[i];
                        s[i] = third;

                    }
                
        return false;
        
    }

    bool equal(string str) {

        unordered_map<char, int> mp;

        for(int i = 0; i < str.length(); i++) {

            if(mp[str[i]] > 0)
                return true;

            mp[str[i]] += 1;
        }

        return false;

    }
};