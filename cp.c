
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PASSWORD 256

void analyze_password(const char *password) {
    int length = (int)strlen(password);

    int lower = 0, upper = 0, digit = 0, special = 0;
    int pool = 0;

    for (int i = 0; i < length; i++) {
        unsigned char c = (unsigned char)password[i];

        if (islower(c)) lower = 1;
        else if (isupper(c)) upper = 1;
        else if (isdigit(c)) digit = 1;
        else if (isprint(c)) special = 1;
    }

    if (lower) pool += 26;
    if (upper) pool += 26;
    if (digit) pool += 10;
    if (special) pool += 33;

    printf("\n========== PASSWORD ANALYSIS ==========\n");
    printf("Length: %d characters\n", length);
    printf("Lowercase: %s\n", lower ? "Yes" : "No");
    printf("Uppercase: %s\n", upper ? "Yes" : "No");
    printf("Digits: %s\n", digit ? "Yes" : "No");
    printf("Special characters: %s\n", special ? "Yes" : "No");

    if (pool == 0 || length == 0) {
        printf("Invalid password input.\n");
        return;
    }

    long double entropy = length * log2l(pool);

    printf("Estimated search space: 2^%.2Lf combinations\n", entropy);
    printf("Theoretical entropy: %.2Lf bits\n", entropy);

    if (length < 8 || entropy < 40)
        printf("Strength: WEAK\n");
    else if (entropy < 60)
        printf("Strength: MODERATE\n");
    else if (entropy < 80)
        printf("Strength: STRONG\n");
    else
        printf("Strength: VERY STRONG\n");

    printf("\nNote: This is a theoretical estimate, not a real-world"
           " password security guarantee.\n");
}

int main(void) {
    char password[MAX_PASSWORD];

    printf("====================================\n");
    printf("       PASSWORD STRENGTH CHECKER\n");
    printf("               v1.1.0\n");
    printf("====================================\n");

    printf("Enter a sample password: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    password[strcspn(password, "\n")] = '\0';

    if (strchr(password, '\n') == NULL &&
        strlen(password) == sizeof(password) - 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Input too long. Maximum length is 254 characters.\n");
        return 1;
    }

    if (password[0] == '\0') {
        printf("Password cannot be empty.\n");
        return 1;
    }

    analyze_password(password);

    return 0;
}
