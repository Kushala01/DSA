#include<bits/stdc++.h>
using namespace std;

int calcuateMaxTeamSize(vector<int>&arr, int k, int teamSize){
    priority_queue<int>frontQueue;
    priority_queue<int>backQueue;
    int front=0;
    int back=arr.size()-1;

    for(int i=0;i<k;i++){
        frontQueue.push(arr[front]);
        front++;
    }
    for(int i=0;i<k && front<=back;i++){//rem this bitch
        backQueue.push(arr[back]);
        back--;
    }
    int maxSize=0;
    while(teamSize--){//checks if the team size is non zero n stops the loop if its zero
        if(!frontQueue.empty() && !backQueue.empty()){
            if(frontQueue.top()>backQueue.top()){
                maxSize+=frontQueue.top();
                frontQueue.pop();
                if(front<=back){
                    frontQueue.push(arr[front]);
                    front++;
                }
            }else{
                maxSize+=backQueue.top();
                backQueue.pop();
                if(front<=back){
                    backQueue.push(arr[back]);
                    back--;
                }
            }
        }else if(!frontQueue.empty()){
            maxSize+=frontQueue.top();
            frontQueue.pop();
            if(front<=back){
                frontQueue.push(arr[front]);
                front++;
            }
        }else if(!backQueue.empty()){
            maxSize+=backQueue.top();
            backQueue.pop();
            if(front<=back){
                backQueue.push(arr[back]);
                back--;
            }
        }
    }
    return maxSize;
}
int main(){
    vector<int>arr={17, 12, 10, 2, 7, 2, 11, 20};
    int k=4, teamSize=3;
    int result=calcuateMaxTeamSize(arr,k,teamSize);
    cout<<"the resultant is "<<result<<endl;
    return 0;
}