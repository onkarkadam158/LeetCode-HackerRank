class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0;i<ransomNote.size();i++)
            a[ransomNote[i]-97]++;
        for(int i=0;i<magazine.size();i++)
            b[magazine[i]-97]++;
        for(int i=0;i<26;i++)
            if(a[i]>b[i])
                return false;
        return true;
    }
};
/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/