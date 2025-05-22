#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int CHAR_COUNT = 256; // Боломжит тэмдэгтийн тоо

// ======== KMP алгоритм ========
void computeLPS(const string &pattern, int lps[]) {
    int length = 0; // Өмнөх хамгийн урт давхардсан угтвар-үсгийн урт
    lps[0] = 0;
    int i = 1;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmpSearch(const string &text, const string &pattern) {
    cout << "KMP алгоритм:" << endl;
    int textLength = text.length();
    int patternLength = pattern.length();
    int lps[patternLength];
    computeLPS(pattern, lps);
    
    int i = 0, j = 0;
    while (i < textLength) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == patternLength) {
            cout << (i - j) << " index дээр олдлоо." << endl;
            j = lps[j - 1];
        } else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

// ======== Бойер-Мүүр алгоритм ========
void badCharacterTable(const string &pattern, int badChar[CHAR_COUNT]) {
    for (int i = 0; i < CHAR_COUNT; i++)
        badChar[i] = -1;
    for (int i = 0; i < pattern.length(); i++)
        badChar[(int)pattern[i]] = i;
}

void boyerMooreSearch(const string &text, const string &pattern) {
    cout << "Boyer-Moore алгоритм:" << endl;
    int textLength = text.length();
    int patternLength = pattern.length();
    int badChar[CHAR_COUNT];
    badCharacterTable(pattern, badChar);
    
    int shift = 0;
    while (shift <= (textLength - patternLength)) {
        int j = patternLength - 1;
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            cout << shift << " index дээр олдлоо." << endl;
            shift += (shift + patternLength < textLength) ? patternLength - badChar[text[shift + patternLength]] : 1;
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

// ======== Гол функц ========
int main() {
    string text, pattern;
    
    cout << "Текст оруул: ";
    getline(cin, text);
    
    cout << "Дүр оруул: ";
    getline(cin, pattern);

    // KMP алгоритмын гүйцэтгэлийн хугацааг хэмжих
    auto startKMP = high_resolution_clock::now();
    kmpSearch(text, pattern);
    auto endKMP = high_resolution_clock::now();
    auto durationKMP = duration_cast<microseconds>(endKMP - startKMP);

    // Бойер-Мүүр алгоритмын гүйцэтгэлийн хугацааг хэмжих
    auto startBM = high_resolution_clock::now();
    boyerMooreSearch(text, pattern);
    auto endBM = high_resolution_clock::now();
    auto durationBM = duration_cast<microseconds>(endBM - startBM);

    // Гүйцэтгэлийн үр дүнг хэвлэх
    cout << "\n=== Гүйцэтгэлийн хурд ===" << endl;
    cout << "KMP: " << durationKMP.count() << " микросекунд" << endl;
    cout << "Boyer-Moore: " << durationBM.count() << " микросекунд" << endl;

    return 0;
}
