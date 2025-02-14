class ProductOfNumbers {
public:
    vector<int>prod;
    ProductOfNumbers() {
        prod.clear();
        prod.push_back(1);
    }
    
    void add(int num) {
        if(num==0) prod.clear();
        else{
            if(prod.size()==0){
                prod.push_back(num);
            }
            else{
                prod.push_back(prod.back()*num);
            }
        }
    }
    
    int getProduct(int k) {
        if(prod.size()<k) return 0;
        if(prod.size()==k) return prod.back();
        int prev=prod[prod.size()-1-k];
        
        return prod.back()/prev;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */