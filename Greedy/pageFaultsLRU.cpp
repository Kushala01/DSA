#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int pageFaults(int N, int C, int pages[]){
        unordered_set<int> cache;
        list<int> lru;
        int pageFaults=0;

        for(int i=0;i<N;i++){
            int page=pages[i];
            if(cache.find(page)==cache.end()){
                pageFaults++;
                if(cache.size()==C){
                    int lruPage=lru.front();
                    lru.pop_front();
                    cache.erase(lruPage);
                }cache.insert(page);
            }else{
                lru.remove(page);
            }lru.push_back(page);
        }return pageFaults;
    }
};