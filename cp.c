#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void test(const char *t) {
    int l = strlen(t);
    int d = 0, lt = 0, s = 0;

    // Check character types
    for (int i = 0; i < l; i++) {
        if (isdigit(t[i])) d = 1;
        else if (isalpha(t[i])) lt = 1;
        else s = 1;
    }

    // Calculate pool size
    int p = 0;
    if (d)  p += 10;
    if (lt) p += 26;
    if (s)  p += 32;
    if (p == 0) p = 1;

    printf("\n--- Result ---\n");
    
    // Check strength category
    if (l <= 4) {
        printf("Strength: VERY WEAK\n");
    } else if (l < 8) {
        if (lt && d) printf("Strength: MEDIUM\n");
        else printf("Strength: WEAK\n");
    } else {
        if (lt && d) printf("Strength: STRONG\n");
        else printf("Strength: MEDIUM\n");
    }

    // Calculate time to crack
    double c = pow(p, l);
    double sec = c / 10000000.0;

    printf("Length  : %d\n", l);
    
    if (sec < 0.001) {
        printf("Time    : Instantly\n");
    } else if (sec < 60) {
        printf("Time    : %.2f seconds\n", sec);
    } else if (sec < 3600) {
        printf("Time    : %.2f minutes\n", sec / 60.0);
    } else {
        printf("Time    : %.2f hours\n", sec / 3600.0);
    }
}

int main() {
    char pass[100];
    printf("Enter password: ");
    if (scanf("%99s", pass) == 1) {
        test(pass);
    }
    return 0;
}
