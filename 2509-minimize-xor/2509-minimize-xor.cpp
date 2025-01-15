class Solution {
public:
    vector<int>toarray(int num,int &count){
        vector<int>temp(32,0);
        int i=0;
        while(num){
            temp[i++]=(num%2);
            if(num%2)
            count++;
            num=num/2;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    int tonum(vector<int> num1arr){
        int res=0;
        for(int i=0;i<num1arr.size();i++)
            res=res*2+num1arr[i];
        return res;
    }
    int minimizeXor(int num1, int num2) {
        int count1=0,count2=0;
        vector<int>num1arr=toarray(num1,count1);
        vector<int>num2arr=toarray(num2,count2);
        int result=0;
        if(count1==count2) return num1;
        int diff=abs(count1-count2);
        if(count1>count2){
            //remove bits
            for(int i=31;i>=0;i--){
                if(num1arr[i]==1)
                    num1arr[i]=0,diff--;
                if(diff==0)
                    break;
            }
        }
        else{
            //add bits
            for(int i=31;i>=0;i--){
                if(num1arr[i]==0)
                    num1arr[i]=1,diff--;
                if(diff==0)
                    break;
            }
        }
        result=tonum(num1arr);
        return result;

    }
};