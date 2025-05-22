#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <unordered_map>
#include <cstring>

using namespace std;
using namespace std::chrono;

// KMP алгоритм (Кнут-Моррис-Пратт)
vector<int> computeLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);  // LPS массивыг тэгээр эхлүүлэх
    int length = 0;         // Өмнөх хамгийн урт префикс суффиксын урт
    int i = 1;              // Загвар дахь одоогийн байрлал
    
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            // Тэмдэгт таарч байгаа бол уртыг нэмэгдүүлэх
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // Өмнөх хамгийн урт префикс суффикс руу буцах
                length = lps[length - 1];
            } else {
                // Таарах префикс байхгүй, LPS-г 0 гэж тохируулах
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmpSearch(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);  // Загварыг бэлтгэх
    int i = 0;      // Текст дэх индекс
    int j = 0;      // Загвар дэх индекс
    int count = 0;   // Тохиолдлын тоо
    
    while (i < n) {
        if (text[i] == pattern[j]) {
            // Тэмдэгт таарч байгаа бол хоёр индексийг нэмэгдүүлэх
            i++; 
            j++;
        }
        if (j == m) {
            // Загвар бүтэн олдсон, тоолуурыг нэмэгдүүлэх
            count++;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            // Зарим тэмдэгт таарсны дараа таарахгүй байгаа
            if (j != 0) {
                // LPS ашиглан шаардлагагүй харьцуулалтыг алгасах
                j = lps[j - 1];
            } else {
                // Ямар ч таарахгүй, зөвхөн текстийн индексийг нэмэгдүүлэх
                i++;
            }
        }
    }
    return count;
}

// Boyer-Moore алгоритм
unordered_map<char, int> badCharacterTable(const string &pattern) {
    unordered_map<char, int> table;
    int m = pattern.size();
    for (int i = 0; i < m; i++) {
        // Тэмдэгт бүрийн хамгийн баруун байрлалыг хадгалах
        table[pattern[i]] = i;
    }
    return table;
}

int boyerMooreSearch(const string &text, const string &pattern) {
    unordered_map<char, int> badChar = badCharacterTable(pattern);
    int n = text.size(), m = pattern.size();
    int i = 0, count = 0;
    
    while (i <= n - m) {
        int j = m - 1;
        // Загварын төгсгөлөөс эхлэн харьцуулах
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }
        if (j < 0) {
            // Загвар бүтэн олдсон
            count++;
            if (i + m < n) {
                // Муу тэмдэгтийн дүрэмд тулгуурлан алгасах
                i += m - badChar[text[i + m]];
            } else {
                i += 1;
            }
        } else {
            // Муу тэмдэгтийн дүрэмд тулгуурлан алгасах
            i += max(1, j - badChar[text[i + j]]);
        }
    }
    return count;
}

// Гүйцэтгэл хэмжих функц
void measurePerformance(const string &text, const string &pattern) {
    // Алгоритмуудын нэр ба функцүүдийн жагсаалт
    vector<pair<string, int(*)(const string&, const string&)>> algorithms = {
        {"KMP", kmpSearch},
        {"Boyer-Moore", boyerMooreSearch}
    };
    
    for (const auto &[name, func] : algorithms) {
        auto start = chrono::high_resolution_clock::now();
        int occurrences = func(text, pattern);
        auto end = chrono::high_resolution_clock::now();
        double duration = chrono::duration<double, milli>(end - start).count();
        
        cout << name << ": Тохиолдлын тоо = " << occurrences 
             << ", Цаг (мс) = " << duration << endl;
    }
}

int main() {
    string text, pattern;
    
    cout << "Текст оруулна уу: ";
    getline(cin, text);
    
    cout << "Хайх дүр оруулна уу: ";
    getline(cin, pattern);

    measurePerformance(text, pattern);

    return 0;
}