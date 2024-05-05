.PHONY: help all clean

all: main # Build all targets

help: # Show help for each of the Makefile recipes.
	@printf "\n"
	@grep -E '^[a-z].*:.*'  Makefile | while read -r l; do printf "\033[1;32m$$(echo $$l | cut -f 1 -d':')\033[00m:$$(echo $$l | cut -f 2- -d'#')\n"; done
	@printf "\n"

main: main.cpp # Build main file
	g++ -std=c++20 Employee.cpp Engineer.cpp Factory.cpp Personal.cpp Project.cpp main.cpp -O3 -o main -I ../include/json/include

clean: # Delete all builded files
	rm -f main