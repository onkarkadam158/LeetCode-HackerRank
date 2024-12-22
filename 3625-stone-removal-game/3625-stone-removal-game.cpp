class Solution {
public:
    bool canAliceWin(int n) {
        int flag=0;
        int stone=10;
        while(n>=0){
            n=n-stone;
            stone--;
            flag++;
        }
        return flag%2==0;
    }
};