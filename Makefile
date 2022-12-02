all: day1 day2

day1:
	/opt/homebrew/opt/llvm/bin/clang++ -std=c++17 ./src/2022-12-01.cpp -o ./bin/2022-12-01

day2:
	/opt/homebrew/opt/llvm/bin/clang++ -std=c++17 ./src/2022-12-02.cpp -o ./bin/2022-12-02