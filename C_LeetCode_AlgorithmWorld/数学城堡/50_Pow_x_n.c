double myPow(double x, int n) {
    double result = 1;
    int is=0;
    if (n < 0) {
        n = (-n-1);
        is=1;
        result=x;
    }
    while (n > 0) {
        if (n & 1) {
            result = result * x;
        }
        x = x * x;
        n /= 2;
    }
    if(is==0)return result;
    return 1/result;
}