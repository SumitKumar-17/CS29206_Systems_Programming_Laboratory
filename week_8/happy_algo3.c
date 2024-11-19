#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 9999

typedef struct {
    int nums[MAX_NUM];
    int count;
} NumberDictionary;

void markvisited(NumberDictionary *dict, int n) {
    if (dict->count < MAX_NUM) {
        dict->nums[dict->count++] = n;
    }
}

int isvisited(NumberDictionary *dict, int n) {
    for (int i = 0; i < dict->count; i++) {
        if (dict->nums[i] == n) {
            return 1;
        }
    }
    return 0;
}

int nextnum(int n) {
    // Assuming the logic for calculating the next number remains the same
    if (n < 100)
        return 162;
    else
        return 738;
}

int ishappy(int n) {
    NumberDictionary dict;
    dict.count = 0;
    
    markvisited(&dict, n);
    
    while (1) {
        n = nextnum(n);
        if (!isvisited(&dict, n)) {
            markvisited(&dict, n);
            continue;
        }
        if (n == 1)
            return 1;
        else
            return 0;
    }
}

int main() {
    for (int n = 1; n <= 9999; n++) {
        if (ishappy(n)) {
            printf("%d\n", n);
        }
    }
    return 0;
}
