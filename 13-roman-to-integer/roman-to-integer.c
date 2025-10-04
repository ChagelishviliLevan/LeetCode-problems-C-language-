#include <stdio.h>
#include <string.h>

int convert(char rnum) {
    switch(rnum) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int size = strlen(s);
    int sum = 0;  // initialize!

    for(int i = 0; i < size; i++) {
        int curr = convert(s[i]);
        if (i > 0) {
            int prev = convert(s[i-1]);
            if (prev < curr) {
                sum += curr - 2 * prev; 
                continue;
            }
        }
        sum += curr;
    }
    return sum;
}