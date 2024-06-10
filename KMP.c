//O(m+n)
#include <stdio.h>
#include <string.h>

void computeLPSArray(char *pattern, int M, int *lps) {
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            // This is tricky. Consider the example AAACAAAA and i = 7.
            if (len!= 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i = 0; // index for text[]
    int j = 0; // index for pattern[]
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Found pattern at index %d \n", i-j);
            j = lps[j-1];
        }

        // mismatch after j matches
        else if (i < N && pattern[j]!= text[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j!= 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    KMPSearch(pattern, text);
    return 0;
}
