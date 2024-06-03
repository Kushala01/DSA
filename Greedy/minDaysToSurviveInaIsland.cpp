int minimumDays(int S, int N, int M) {
    if (M > N) {
        return -1;
    }

    int totalFoodRequired = S * M;

    int daysAvailableToBuy = S - (S / 7);

    int minDaysToBuy = ceil(totalFoodRequired / (float)N);

    if (minDaysToBuy > daysAvailableToBuy) {
        return -1;
    } else {
        return minDaysToBuy;
    }
}