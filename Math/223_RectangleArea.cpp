class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int I, J, K, L;
        I = E >= A ? E : A;
        J = F >= B ? F : B;
        K = G <= C ? G : C;
        L = H <= D ? H : D;

        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);

        int commonArea = 0;
        if (K > I && L > J)
            commonArea = (K - I) * (L - J);

        return area1 + area2 - commonArea;
    }
};