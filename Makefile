all: day1

day1:
	/opt/homebrew/opt/llvm/bin/clang++ -std=c++17 ./src/2022-12-01.cpp -o ./bin/2022-12-01