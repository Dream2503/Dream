int maximizingXor(int l, int r) {
    int x = l ^ r, res = 1;
    
    while (x > 0) {
        res <<= 1;
        x >>= 1;
    }
    return res - 1;
}