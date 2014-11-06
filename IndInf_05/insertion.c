/*
 * Quelle: http://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort#C
 */
#include <stddef.h>
#include "sortieren.h"

/*
 * Sortiert einen Vektor mittels Insertionsort
 */
void insertion(int *a, int n) {
    size_t i, j;
    int value;
    for (i = 1; i < n; i++) {
        value = a[i];
        for (j = i; j > 0 && value < a[j - 1]; j--) {
            a[j] = a[j - 1];
        }
        a[j] = value;
    }
}
