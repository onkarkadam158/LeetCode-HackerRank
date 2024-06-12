class Solution {
public:
    int bruteforce(int start,int goal){
        int count=0;
        while(start or goal){
            if(start%2!=goal%2)
                count++;
            start=start/2;
            goal=goal/2;
        }
        return count;
    }
    int optimal(int start,int goal){
        int count=0;
        start=start^goal;
        //do XOR of two and then count the set bits in it
        while(start){
            start=start&(start-1);
            count++;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        // return bruteforce(start,goal); time O(logn) space O(1)
        return optimal(start,goal);  //time O(no. of flip bits) space O(1)
    }
};