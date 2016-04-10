int accum = 123;

int sum(int x, int y) {
    int t = x + y;
    accum += t;
    return t;
}
