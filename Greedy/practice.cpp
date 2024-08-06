#include<bits/stdc++.h>
using namespace std;

struct item{
    int value;
    int weight;
};
class Solution{
    public:

    bool static comp(item A, item B){
        double r1=(double) a.value / (double) a.weight;
        double r2=(double) b.value / (double) b.weight;
        return r1 > r2;
    }

    
};