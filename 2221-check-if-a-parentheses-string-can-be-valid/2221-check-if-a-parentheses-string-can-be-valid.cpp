class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2) return false;
        stack<int>open,openclose;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                openclose.push(i);
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]==')'){
                if(!open.empty()){
                    open.pop();
                }
                else if(!openclose.empty()){
                    openclose.pop();
                }
                else return false;
            }
        }
        while(!open.empty() and !openclose.empty()){
            if(open.top() < openclose.top()){
                open.pop();
                openclose.pop();
            }else{
                break;
            }
        }
        return open.empty();
    }
};