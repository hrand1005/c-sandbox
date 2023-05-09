#include <stdio.h>

int binsearch(int, int[], int);

int main() {
    int i;
    int sorted[] = {2, 4, 6, 7, 9, 10};
    int size = sizeof(sorted) / sizeof(int);

    printf("input array:\n");
    for (i = 0; i < size; i++)
        printf("%d%s", sorted[i], (i < size - 1 ? " ": "\n"));

    printf("binsearch(4): %d\n", binsearch(4, sorted, size));
}

int binsearch(int t, int arr[], int n) {
    int l, r, mid;

    l = 0;
    r = n - 1;
    mid = (l + r) / 2;
    while (l <= r && arr[mid] != t) {
        if (arr[mid] < t)
            l = mid + 1;
        else
            r = mid - 1;
        mid = (l + r) / 2;
    }
    return (arr[mid] == t) ? mid : -1;
}
