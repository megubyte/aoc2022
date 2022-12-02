#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> read_file(char *filename)
{
    std::ifstream input(filename);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    return lines;
}

void require_input_file(int argc, char **argv)
{
    if (argc < 2) {
        std::fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}