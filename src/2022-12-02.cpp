#include <algorithm>
#include <charconv>
#include "common.hpp"

struct game_t {
    public:
        constexpr game_t(char theirs, char yours): theirs(theirs), yours(yours) {}

    char theirs, yours;
};

int run_game(game_t game)
{
    if (game.theirs == 'A') {
        if (game.yours == 'X') { return 1 + 3; } // Rock + Draw
        if (game.yours == 'Y') { return 2 + 6; } // Paper + Win
        if (game.yours == 'Z') { return 3 + 0; } // Scissors + Loss
    } else if (game.theirs == 'B') {
        if (game.yours == 'X') { return 1 + 0; } // Rock + Loss
        if (game.yours == 'Y') { return 2 + 3; } // Paper + Draw
        if (game.yours == 'Z') { return 3 + 6; } // Scissors + Win
    } else if (game.theirs == 'C') {
        if (game.yours == 'X') { return 1 + 6; } // Rock + Win
        if (game.yours == 'Y') { return 2 + 0; } // Paper + Loss
        if (game.yours == 'Z') { return 3 + 3; } // Scissors + Draw
    }

    return 0;
}

char pick_based_on_guide(char theirs, char guide)
{
    bool should_lose = (guide == 'X'),
        should_draw = (guide == 'Y'),
        should_win = (guide == 'Z');

    if (should_win) {
        if (theirs == 'A') { return 'Y'; }
        if (theirs == 'B') { return 'Z'; }
        if (theirs == 'C') { return 'X'; }
    } else if (should_draw) {
        if (theirs == 'A') { return 'X'; }
        if (theirs == 'B') { return 'Y'; }
        if (theirs == 'C') { return 'Z'; }
    } else if (should_lose) {
        if (theirs == 'A') { return 'Z'; }
        if (theirs == 'B') { return 'X'; }
        if (theirs == 'C') { return 'Y'; }
    }

    return 'O';
}

int process_result(std::vector<std::string> lines)
{
    std::vector<game_t> games;
    int score = 0;

    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        games.push_back(game_t(line[0], line[2]));
    }

    for (int i = 0; i < games.size(); i++) {
        score += run_game(games[i]);
    }
    printf("Part 1 Final Score: %d\n", score);

    games.clear();
    score = 0;
    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        games.push_back(game_t(line[0], pick_based_on_guide(line[0], line[2])));
    }

    for (int i = 0; i < games.size(); i++) {
        score += run_game(games[i]);
    }
    printf("Part 2 Final Score: %d\n", score);

    return 0;
}

int main(int argc, char **argv)
{
    require_input_file(argc, argv);
    std::vector<std::string> lines = read_file(argv[1]);
    return process_result(lines);
}