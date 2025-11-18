int birthdayCakeCandles(int candles_count, int* candles) {
    int max = candles[0], i, cnt = 0;

    for (i = 1; i < candles_count; i++) {
        if (max < candles[i]) {
            max = candles[i];
        }
    }
    for (i = 0; i < candles_count; i++) {
        if (candles[i] == max) {
            cnt++;
        }
    }
    return cnt;
}
