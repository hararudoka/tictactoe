# Makefile is something like a script that is used to compile the code. like Dockerfile for docker image running, but for C++ code, i think
# build + execute + clean
run: build execute clean

# build program to binary
build:
# '@' means no output for the command
	@clang++ src/Main.cpp 

# execute binary
execute:
	@./a.out

# remove binary
clean:
	@rm -f a.out