#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
void crack_password(const char *target) {
    char guess[100];
    long long iterations = 0;
    
    clock_t start = clock();
    bool found = false;
    printf("Analyzing complexity...\n");
    for (long long i = 0; i < 1000000000; i++) {
        iterations++;
        sprintf(guess, "%lld", i); 
        
        if (strcmp(guess, target) == 0) {
            found = true;
            break;
        }
    }
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n--- Analysis Complete ---\n");
    if (found) {
        printf("Password Cracked Successfully!\n");
    } else {
        printf("Search space exhausted or password too complex.\n");
    }
    printf("Total Iterations: %lld\n", iterations);
    printf("Time Elapsed:     %.6f seconds\n", time_taken);
}

int main() {
    char password[100];
    
    printf("=====================================\n");
    printf("   EXPERT PASSWORD STRENGTH TESTER   \n");
    printf("=====================================\n");
    printf("Enter target password (try a number like 123456): ");
    
    if (scanf("%99s", password) == 1) {
        crack_password(password);
    }
    
    return 0;
}
