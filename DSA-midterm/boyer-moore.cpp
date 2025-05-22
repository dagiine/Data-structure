#include <iostream>
#include <string>
using namespace std;


#define NO_OF_CHARS 256


// Тохирохгүй тэмдэгтийн хүснэгт үүсгэх функц
void badCharHeuristic(const string &pattern, int badChar[NO_OF_CHARS]) {
    int m = pattern.length();
    
    // Бүх ASCII тэмдэгтийг -1 утгаар эхлүүлнэ
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;


    // Загвар дахь тэмдэгтүүдийн байрлалыг хадгална
    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}


// Boyer-Moore хайлтын алгоритм
void boyerMooreSearch(const string &text, const string &pattern) {
    int m = pattern.length();
    int n = text.length();
    int badChar[NO_OF_CHARS];


    badCharHeuristic(pattern, badChar);


    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;


        // Хайх дүр болон текстийг баруун талаас харьцуулах
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;


        // Хэрэв дүр текстийн тухайн хэсэгт бүрэн таарвал хэвлэнэ
        if (j < 0) {
            cout << shift << " index d oldloo." << endl;
            if (shift + m < n) {
    			shift += m - badChar[text[shift + m]];
			} else {
    			shift += 1;
			}
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}


int main() {
    string text, pattern;
    
    cout << "Текст: ";
    getline(cin, text);
    
    cout << "Хайх дүр: ";
    getline(cin, pattern);
    
    boyerMooreSearch(text, pattern);
    return 0;
}