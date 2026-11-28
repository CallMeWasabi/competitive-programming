run: compile
	./a.out

compile: main.cpp
	g++ -std=c++17 -O2 -Wall -Wextra -fsanitize=address,undefined -D_GLIBCXX_DEBUG main.cpp
