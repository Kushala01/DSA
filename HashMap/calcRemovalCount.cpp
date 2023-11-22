#include<bits/stdc++.h>
using namespace std;

int calcRemovalCount(string &word, string &target) {
    unordered_map<char, int>target_count, word_count;
    for(char ch : word){
        word_count[ch]++;
    }
    for(char ch : target){
        target_count[ch]++;
    }
    int ans=INT_MAX;
    for(auto const &entry : target_count){
        char ch=entry.first;
        int t_count=entry.second;
        if(word_count.find(ch)==word_count.end()){
            return -1;
        }
        int w_count=word_count[ch];
        int len=w_count/t_count;
        ans=min(ans,len);
    }
    return ans;
}
