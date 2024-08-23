class Solution {
public:
    int getNumerator(string s){
        int j=0;
        while(s[j]!='/')j++;
        return stoi(s.substr(0,j));
    }
    int getDenominator(string s){
        int i=0;
        while(s[i]!='/') i++;
        return stoi(s.substr(i+1,s.size()-i));
    }
    string fractionAddition(string expression) {
        vector<string>parse;
        string temp="";
        for(auto a:expression){
            if(a=='-' or a=='+'){
                if(temp.size() >0)parse.push_back(temp);
                temp="";
                temp+=a;
                parse.push_back(temp);
                temp="";
            }
            else{
                if(parse.size()==0) parse.push_back("+");
                temp+=a;
            }
        }
        parse.push_back(temp);
        
        for(auto a:parse)cout<<a<<" ";
        cout<<"\n";
        long denominators=1,numerators=0;
        for(int i=0;i<parse.size();i+=2){
            int den=getDenominator(parse[i+1]); 
            denominators*=den;
        }
        for(int i=0;i<parse.size();i+=2){
            int num=getNumerator(parse[i+1]);
            int den=getDenominator(parse[i+1]); 
            cout<<num<<" "<<den<<"\n";
            if(parse[i]=="+"){
                numerators+=(denominators/den)*num;
            }
            else{
                numerators+=((denominators/den)*(-1)*num);
            }
        }
        if(numerators==0) return "0/1";
        for(int i=2;i<denominators;i++){
            while(denominators%i==0 and numerators%i==0){
                denominators/=i;
                numerators/=i;
            }
        }
        cout<<numerators<<" "<<denominators<<"\n";
        string res="";
        res+=to_string(numerators);
        res+='/';
        res+=to_string(denominators);
        return res;
    }
};