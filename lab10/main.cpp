#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

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

void sortByFreq(std::vector<std::pair<char,int>> &v)
{
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j + 1 < v.size(); ++j) {
            if (v[j].second < v[j + 1].second) {
                std::pair<char,int> temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}



int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::ofstream fstat("stat.txt");

    if (!fin.is_open()) {
        std::cout << "Не удалось открыть input.txt\n";
        return 1;
    }

    char c;
    std::string inputText;
    while (fin.get(c)) {
        inputText += c;
    }

    std::string outText = translit(inputText);
    fout << outText;

    std::map<char, int> freq;
    for (char c : outText) {
        if (std::isalpha((unsigned char)c))
            freq[c]++;
    }

    // Вектор для сортировки
    std::vector<std::pair<char, int>> vec(freq.begin(), freq.end());

    sortByFreq(vec);

    // Вывод
    for (std::pair<char, int> &p : vec) {
        fstat << p.first << " - " << p.second << "\n";
    }

    return 0;
}
