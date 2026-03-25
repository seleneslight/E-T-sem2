#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::string> get_utf8_symbols(const std::string &text)
{
    std::vector<std::string> symbols;
    for (size_t i = 0; i < text.length();)
    {
        int len = 1;
        unsigned char c = text[i];
        if (c >= 0xF0)
            len = 4;
        else if (c >= 0xE0)
            len = 3;
        else if (c >= 0xC0)
            len = 2;

        if (c != '\n' && c != '\r' && c != ' ')
        {
            symbols.push_back(text.substr(i, len));
        }
        i += len;
    }
    return symbols;
}

struct SymbolFreq
{
    std::string symbol;
    int count;
};

void encrypt_file(const std::string &input_filename, const std::string &output_filename)
{
    std::map<char, std::string> reverse_map = {
        {'e', "8"}, {'t', ";"}, {'h', "4"}, {'o', "‡"}, {'s', ")"}, {'n', "*"}, {'a', "5"}, {'i', "6"}, {'r', "("}, {'d', "†"}, {'l', "1"}, {'g', "0"}, {'m', "2"}, {'y', "9"}, {'b', "3"}, {'u', ":"}, {'f', "?"}, {'c', "¶"}, {'p', "-"}, {'v', "."}};

    std::ifstream infile(input_filename);
    std::ofstream outfile(output_filename);
    if (!infile || !outfile)
        return;

    char c;
    while (infile.get(c))
    {
        char lower_c = std::tolower(c);
        if (reverse_map.count(lower_c))
        {
            outfile << reverse_map[lower_c];
        }
    }
}

int main()
{
    std::string cipher_text =
        "53‡‡†305))6*;4826)4‡.)4‡);80\n"
        "6*;48†8¶60))85;1‡(;:‡*8†83(88)\n"
        "5*†;46(;88*96*?;8)*‡(;485);5*†\n"
        "2:*‡(;4956*2(5*-4)8¶8*;40692\n"
        "85);)6†8)4‡‡;1(‡9;48081;8:8‡1\n"
        ";48†85;4)485†528806*81(‡9;48\n"
        ";(88;4(‡?34;48)4‡;161;:188;‡?;\n";

    std::ofstream out_msg("message.txt");
    out_msg << cipher_text;
    out_msg.close();
    std::cout << "Created 'message.txt' with the ciphered text.\n\n";

    std::ifstream in_msg("message.txt");
    std::string file_content((std::istreambuf_iterator<char>(in_msg)), std::istreambuf_iterator<char>());

    std::vector<std::string> symbols = get_utf8_symbols(file_content);

    std::map<std::string, int> frequency_map;
    for (const auto &sym : symbols)
    {
        frequency_map[sym]++;
    }

    std::vector<SymbolFreq> sorted_freqs;
    for (const auto &pair : frequency_map)
    {
        sorted_freqs.push_back({pair.first, pair.second});
    }

    std::sort(sorted_freqs.begin(), sorted_freqs.end(), [](const SymbolFreq &a, const SymbolFreq &b)
              {
        if (a.count != b.count) return a.count > b.count;
        return a.symbol < b.symbol; });

    std::cout << "symbols by frequencies\n\n";
    std::cout << "Symbol Count\n";
    for (const auto &sf : sorted_freqs)
    {
        std::cout << sf.symbol << " -> " << sf.count << "\n";
    }
    std::cout << "\n";

    std::vector<std::string> poe_letters = {
        "e", "a", "o", "i", "d", "h", "n", "r", "s", "t", "u", "y",
        "c", "f", "g", "l", "m", "w", "b", "k", "p", "q", "x", "z"};

    std::map<std::string, std::string> strict_freq_map;
    std::cout << "substitution by frequency\n\n";
    for (size_t i = 0; i < sorted_freqs.size() && i < poe_letters.size(); ++i)
    {
        strict_freq_map[sorted_freqs[i].symbol] = poe_letters[i];
        std::cout << sorted_freqs[i].symbol << " -> " << poe_letters[i] << "\n";
    }
    std::cout << "\n";

    std::string strict_deciphered = "";
    for (const auto &sym : symbols)
    {
        strict_deciphered += strict_freq_map[sym];
    }

    std::cout << "translation using map\n\n";
    std::cout << strict_deciphered << "\n\n";

    std::cout << "real solution\n\n";
    std::string poe_solution = "agoodglassinthebishopshostelinthedevilsseatfortyonedegreesandthirteenminutesnortheastandbynorthmainbranchseventhlimbeastsideshootfromthelefteyeofthedeathsheadabeelinefromthetreethroughtheshotfiftyfeetout";
    std::cout << poe_solution << "\n\n";

    std::ofstream out_eng("english.txt");
    out_eng << "A good glass in the bishop's hostel!";
    out_eng.close();

    encrypt_file("english.txt", "ciphered.txt");

    std::ifstream in_cip("ciphered.txt");
    std::string test_ciphered((std::istreambuf_iterator<char>(in_cip)), std::istreambuf_iterator<char>());
    std::cout << "encryption\n\n";
    std::cout << "English: A good glass in the bishop's hostel!\n";
    std::cout << "Ciphered: " << test_ciphered << "\n";

    return 0;
}