#include <iostream>
#include <vector>
using namespace std;


// LPS хүснэгт үүсгэх функц
void LPSArray(const string &pattern, vector<int> &lps) {
    int m = pattern.length();
    int len = 0;
    lps[0] = 0; // Эхний тэмдэгт 0 байна
    int i = 1;


    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


// KMP хайлтын алгоритм
void kmpSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m, 0);
    
    LPSArray(pattern, lps);


    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }


        if (j == m) {
            cout << i - j << " индекст олдлоо" << endl;
            j = lps[j - 1]; // Өмнөх тохирсон хэсэгт шилжих
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}


int main() {
    string text, pattern;
    
    cout << "Текст: ";
    getline(cin, text);
    
    cout << "Хайх дүр: ";
    getline(cin, pattern);
    
    kmpSearch(text, pattern);
    return 0;
}
