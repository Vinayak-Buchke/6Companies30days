class DataStream {
public:
    int value,k,count=0;    

    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        return (num == value) ? (++count >= k) : (count = 0) == 1;
    }
};

