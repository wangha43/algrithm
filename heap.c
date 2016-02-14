#include <stdio.h>
 //当前i,j,k三个节点最大的一个 n为限制
int max (int *a, int n, int i, int j, int k) {
    int m = i;
    if (j < n && a[j] > a[m]) {
        m = j;
    }
    if (k < n && a[k] > a[m]) {
        m = k;
    }
    return m;
}
 
void downheap (int *a, int n, int i) {
    while (1) {
        int j = max(a, n, i, 2 * i + 1, 2 * i + 2);
        //j为最大 
        if (j == i) {
            break;
        }
        //替换
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i = j;
    }
}
 
void heapsort (int *a, int n) {
    int i;
    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(a, n, i);
        printf("%d:", i);
        for (int j = 0; j < n; j++)
            printf("%d%s", a[j], j == n - 1 ? "\n" : " ");
    }
    printf("\n");

    for (int j = 0; j < n; j++)
            printf("%d%s", a[j], j == n - 1 ? "\n" : " ");

    printf("\n");
    //建堆 排序

    for (i = 0; i < n; i++) {
        int t = a[n - i - 1];
        a[n - i - 1] = a[0];
        a[0] = t;
        downheap(a, n - i - 1, 0);
        for (int j = 0; j < n; j++)
            printf("%d%s", a[j], j == n - 1 ? "\n" : " ");
    }
}
 
int main () {
    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    heapsort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
 