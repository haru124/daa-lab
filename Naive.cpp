#include <iostream>
#include <cstring>
using namespace std;

// Function to perform pattern matching using the Naive algorithm
void naivePatternMatching(char* text,char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLength) {
            cout << "Pattern found at index "<<i<<endl;
        }
    }
}

int main() {
    char* text = "AABAACAADAABAAABAA";
    char* pattern = "AABA";

    naivePatternMatching(text, pattern);

    return 0;
}
