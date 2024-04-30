#include<stdio.h>
int num[100000];
int main() {
    int w, n, d;
    scanf("%d %d %d", &w, &n, &d);
    num[0] = 1;
    num[n + 1] = w;
    int min = n;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &num[i]);
    }
    if (w - 1 <= d) printf("-1\n");
    else {
        for (int i = 0;i < n;i++) {
            for (int j = i;j <= n;j++) {
                if (num[j + 1] - num[i] > d) {
                    if (j - i < min) {
                        min = j - i;
                    }
                    break;
                }
            }
        }
        printf("%d\n", min);
    }
    return 0;
}