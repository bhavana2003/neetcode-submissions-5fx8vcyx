class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;

        double twoPow = x*x;
        double temp = (abs(n)%2 == 0) ? 1 : x;
        temp *= myPow(twoPow, abs(n)/2);

        if (n < 0){
            return (double) 1 / temp;
        }
        else{
            return temp;
        }
    }
};
