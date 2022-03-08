class Solution {
public:
    bool isValid(string s) {
        vector<char> stck;
        stck.push_back(s[0]);
        for(int i=1;i<s.length();i++)
        {
           if(s[i]=='{' || s[i]=='[' || s[i]=='(')
           {
               stck.push_back(s[i]);
           }
            else
            {
                if(stck.size()==0)
                    return false;
                if(s[i]=='}' && stck.back()=='{')
                    stck.pop_back();
                else if(s[i]==']' && stck.back()=='[')
                    stck.pop_back();
                else if(s[i]==')' && stck.back()=='(')
                    stck.pop_back();
                else
                    return false;
            }
        }
        if(stck.size()>0)
            return false;
        return true;
        
    }
};
/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/