class Solution {
public:
    unordered_map<char,int>mp;
    bool islexico(string s1,string s2)
    {
        int m=s1.size(),n=s2.size();
        int size=min(m,n);
        for(int i=0;i<size;i++)
        {
            if(mp[s1[i]]>mp[s2[i]])
                return false;
            if(mp[s1[i]]<mp[s2[i]])
                return true;
        }
        if(m>n)
            return false;
        return true;        
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<26;i++)
            mp[order[i]]=i;
        
        for(int i=0;i<words.size()-1;i++)
            for(int j=i+1;j<words.size();j++)
                if(!islexico(words[i],words[j]))
                    return false;
        return true;
    }
};
/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

*/