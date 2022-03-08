class Solution {
public:
    string toLowerCase(string str) {
        int i=0;
        while(i<str.length())
        {
            if(str[i]>='A' && str[i]<='Z')
                str[i]=str[i]+32;
            i++;
        }
        return str;
    }
};
/*
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"
 

Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
*/