#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

std::map<std::string, std::string> tr = {
		{"à","a"},{"á","b"},{"â","v"},{"ã","g"},{"ä","d"},{"å","e"},{"¸","yo"},
		{"æ","zh"},{"ç","z"},{"è","i"},{"é","y"},{"ê","k"},{"ë","l"},{"ì","m"},
		{"í","n"},{"î","o"},{"ï","p"},{"ð","r"},{"ñ","s"},{"ò","t"},{"ó","u"},
		{"ô","f"},{"õ","h"},{"ö","ts"},{"÷","ch"},{"ø","sh"},{"ù","sch"},
		{"ú",""},{"û","y"},{"ü",""},{"ý","e"},{"þ","yu"},{"ÿ","ya"},

		{"À","A"},{"Á","B"},{"Â","V"},{"Ã","G"},{"Ä","D"},{"Å","E"},{"¨","Yo"},
		{"Æ","Zh"},{"Ç","Z"},{"È","I"},{"É","Y"},{"Ê","K"},{"Ë","L"},{"Ì","M"},
		{"Í","N"},{"Î","O"},{"Ï","P"},{"Ð","R"},{"Ñ","S"},{"Ò","T"},{"Ó","U"},
		{"Ô","F"},{"Õ","H"},{"Ö","Ts"},{"×","Ch"},{"Ø","Sh"},{"Ù","Sch"},
		{"Ú",""},{"Û","Y"},{"Ü",""},{"Ý","E"},{"Þ","Yu"},{"ß","Ya"}
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
        std::cout << "˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ input.txt\n";
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

    std::vector<std::pair<char, int>> vec(freq.begin(), freq.end());

    sortByFreq(vec);

    for (std::pair<char, int> &p : vec) {
        fstat << p.first << " - " << p.second << "\n";
    }

    return 0;
}
