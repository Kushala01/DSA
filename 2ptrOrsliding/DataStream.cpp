class DataStream {
public:
    int val;
    int k;
    int cnt=0;
    DataStream(int value, int k) {
        this->val=value;
        this->k=k;
    }
    
    bool consec(int num) {
        if(num==val)
            cnt++;
        else
            cnt=0;

        if(cnt < k)
            return false;
        else if(cnt==k){
            cnt--;
        }
        return true;
    }
};
