#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    int n = 9537;
    char s[20];
    for(int b=2; b<=36; b++) {
        itob(n, s, b);
        printf("%d in base %d is %s\n", n, b, s);
    }
    return 0;
}

// Works for bases up to 36
// For negative numbers -n it will just print a '-' in front of n in base b
void itob(int n, char s[], int b) {
    if(n < 0) {
        printf("Enter a positive number\n");
        return;
    }

    int i, sign = n;

    i = 0;
    do {
        int d = n % b;
        if(sign < 0)
            d = -d;
        if(d <= 9)
            s[i++] = d + '0';
        else
            s[i++] = d - 10 + 'A';
    } while((n /= b) != 0);

    if(sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';

    reverse(s);
}

// Page 62
void reverse(char s[]) {
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
