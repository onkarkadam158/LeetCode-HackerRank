class Solution {
public:
    unordered_map<int,string> mp = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        {100, "Hundred"},
        {1000, "Thousand"},
        {1000000, "Million"},
        {1000000000, "Billion"}
    };
    
    vector<string> getThree(int num){
        if(num<=20) return {mp[num]};
        vector<string> res;
        if(num>=100){
            res.push_back(mp[(num/100)]);
            res.push_back("Hundred");
        }
        num-=(num/100)*100;
        int k=10;
        while(num){
            if(mp.find(num)!=mp.end()) {    
                res.push_back(mp[num]);
                return res;
            }
            int tnum=(num/k)*k;
            num-=tnum;
            // cout<<tnum<<"\n";
            res.push_back(mp[tnum]);
            
            k=k/10;
        }
        return res;
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        if(num<=20) return mp[num];
        long long k=1000;
        vector<string>res;
        while(num){
            int tnum=num%(k);
            tnum=tnum/(k/1000);
            vector<string> tresult=getThree(tnum);
            for(auto a:tresult)cout<<"<"<<a<<"> ";
            cout<<endl;
            cout<<tnum<<"  "<<k<<"\n\n";
            if(tnum and k/1000==1000) tresult.push_back(mp[1000]);
            if(tnum and k/1000==1e6) tresult.push_back(mp[1e6]);
            if(tnum and k/1000==1e9) tresult.push_back(mp[1e9]);
            for(auto a:res){
                tresult.push_back(a);
            }
            res=tresult;
            num-=num%(k);
            k=k*1000;
        }
        string result="";
        for(auto str:res){
            if(str.size()>0)result+=str+" ";
        }
        result.pop_back();
        return result;   
    }
};