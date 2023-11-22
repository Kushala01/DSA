#include<bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string> &words){
    unordered_map<char, int> min_frequency;
    vector<string> answer;
    for (char ch = 'a'; ch <= 'z'; ch++){
        min_frequency[ch] = 1000;
    }
    for (auto word : words){
        unordered_map<char, int> frequency;
        for (auto ch : word){
            frequency[ch]++;
        }
        for (char ch = 'a'; ch <= 'z'; ch++){
            min_frequency[ch] = min(min_frequency[ch], frequency[ch]);
        }
    }
    for (char ch = 'a'; ch <= 'z'; ch++){
        while (min_frequency[ch] > 0){
            answer.push_back(string(1, ch));
            min_frequency[ch]--;
        }
    }
    return answer;
}

int main(){
    vector<string> words = {"bella", "label", "roller"};
    vector<string> answer = commonChars(words);
    for (auto a : answer){
        cout << a << " ";
    }
    return 0;
}
