#include <algorithm>
#include <iostream>
#include <charconv>
#include <fstream>
#include <vector>

int count_elf_calories(char *filename)
{
    // Read file into vector of lines.
    std::ifstream input(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    // For each value in vector, process result.
    std::vector<unsigned long> elf_calories{0};
    int curr_elf = 0;

    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        unsigned long val = 0;

        if (line.length() > 0) {
            std::from_chars_result result = std::from_chars(line.data(), line.data()+line.size(), val);
            elf_calories[curr_elf] += val;
            continue;
        }

        elf_calories.push_back(0);
        curr_elf++;
    }

    std::sort(elf_calories.begin(), elf_calories.end());
    std::reverse(elf_calories.begin(), elf_calories.end());
    for (int i = 0; i < elf_calories.size(); i++) {
        std::printf("Elf #%d: %lu calories\n", i + 1, elf_calories[i]);
    }

    unsigned long top_three_calories;
    for (int i = 0; i < 3; i++) {
        top_three_calories += elf_calories[i];
    }
    
    std::printf("\nTop Elf has %lu calories.\nTop three elves have %lu calories.\n" ,elf_calories[0], top_three_calories);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    return count_elf_calories(argv[1]);
}