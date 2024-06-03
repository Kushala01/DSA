vector<int> candyStore(int candies[], int N, int K){
    sort(candies, candies+N);
    int max_sum=0;
    int min_sum=0;
    int s=0;
    int e=N-1;
    while(s<=e){
        min_sum+=candies[s];
        e-=K;
        s++;
    }
     s=0, e=N-1;
    while(s<=e){
        max_sum+=candies[e];
        e--;
        s+=K;
    }
    vector<int> sol={min_sum, max_sum};
    return sol;
}