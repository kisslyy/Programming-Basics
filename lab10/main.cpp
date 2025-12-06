#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::map<std::string, std::string> tr = {
		{"а","a"},{"б","b"},{"в","v"},{"г","g"},{"д","d"},{"е","e"},{"ё","yo"},
		{"ж","zh"},{"з","z"},{"и","i"},{"й","y"},{"к","k"},{"л","l"},{"м","m"},
		{"н","n"},{"о","o"},{"п","p"},{"р","r"},{"с","s"},{"т","t"},{"у","u"},
		{"ф","f"},{"х","h"},{"ц","ts"},{"ч","ch"},{"ш","sh"},{"щ","sch"},
		{"ъ",""},{"ы","y"},{"ь",""},{"э","e"},{"ю","yu"},{"я","ya"},

		{"А","A"},{"Б","B"},{"В","V"},{"Г","G"},{"Д","D"},{"Е","E"},{"Ё","Yo"},
		{"Ж","Zh"},{"З","Z"},{"И","I"},{"Й","Y"},{"К","K"},{"Л","L"},{"М","M"},
		{"Н","N"},{"О","O"},{"П","P"},{"Р","R"},{"С","S"},{"Т","T"},{"У","U"},
		{"Ф","F"},{"Х","H"},{"Ц","Ts"},{"Ч","Ch"},{"Ш","Sh"},{"Щ","Sch"},
		{"Ъ",""},{"Ы","Y"},{"Ь",""},{"Э","E"},{"Ю","Yu"},{"Я","Ya"}
};

std::string translit(const std::string &text) {
    std::string out;
    for (size_t i = 0; i < text.size(); ++i) {
        std::string ch(1, text[i]);
        if (tr.count(ch))
            out += tr[ch];
        else
            out += ch;
    }
    return out;
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::ofstream fstat("stat.txt");

    if (!fin.is_open()) {
        std::cout << "Не удалось открыть input.txt\n";
        return 1;
    }

    std::string inputText((std::istreambuf_iterator<char>(fin)),
                           std::istreambuf_iterator<char>());

    // 1) Перевод
    std::string outText = translit(inputText);
    fout << outText;

    // 2) Частоты
    std::map<char, int> freq;
    for (char c : outText) {
        if (std::isalpha((unsigned char)c))
            freq[c]++;
    }

    // Вектор для сортировки
    std::vector<std::pair<char, int>> vec(freq.begin(), freq.end());

    std::sort(vec.begin(), vec.end(),
              [](const std::pair<char,int> &a, const std::pair<char,int> &b) {
                  return a.second > b.second;
              });

    // Вывод
    for (auto &p : vec) {
        fstat << p.first << " - " << p.second << "\n";
    }

    return 0;
}
