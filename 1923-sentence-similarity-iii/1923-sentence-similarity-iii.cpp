class Solution {
public:
    vector<string> getStrings(string& s){
        vector<string>res;
        string temp="";
        for(auto a:s){
            if(a!=' '){
                temp+=a;
            }
            else{
                res.push_back(temp);
                temp="";
            }
        }
        if(temp!="") res.push_back(temp);
        return res;
    }
    bool bruteforce(string& sentence1,string& sentence2){
        vector<string>s1,s2;
        s1=getStrings(sentence1);
        s2=getStrings(sentence2);
        if(s1.size()<s2.size()) {
            swap(s1,s2);
        }
        int m=s1.size(),n=s2.size();
        int i=0,j=0;
        while(i<m and i<n and (s1[i]==s2[i])){
            i++;
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        while(j<m and j<n and (s1[j]==s2[j])){
            j++;
        }
        return (i+j)>=n;
    }
    bool optimal(string& sentence1,string& sentence2){
        vector<string>s1,s2;
        s1=getStrings(sentence1);
        s2=getStrings(sentence2);
        if(s1.size()<s2.size()) {
            swap(s1,s2);
        }
        int m=s1.size(),n=s2.size();
        int i=0,k=0,j=m-1,l=n-1;
        while(i<m and k<n and (s1[i]==s2[k])){
            i++,k++;
        }
        while(j>=0 and l>=0 and (s1[j]==s2[l])){
            j--,l--;
        }
        return k>l;
    }
    bool dequeSolution(string& sentence1,string& sentence2){
        deque<string>s1,s2;

        stringstream ss1(sentence1);
        string token;
        while(ss1 >> token ){
            s1.push_back(token);
        }
        stringstream ss2(sentence2);
        while(ss2 >> token ){
            s2.push_back(token);
        }
        while(!s1.empty() and !s2.empty() and (s1.front()==s2.front())){
            s1.pop_front();
            s2.pop_front();
        }
        while(!s1.empty() and !s2.empty() and (s1.back()==s2.back())){
            s1.pop_back();
            s2.pop_back();
        }
        return s2.empty() or s1.empty();
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {

        // return bruteforce(sentence1,sentence2);

        // return optimal(sentence1,sentence2);

        
        return dequeSolution(sentence1,sentence2);
    }
};