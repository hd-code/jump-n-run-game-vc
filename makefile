appName = jump-n-run

outDir = source/build
srcDir = source/code/intern/src
extDir = source/code/extern
testDir = source/code/intern/test

compiler = clang++
flags = -std=c++11 -Wall -Wextra

# ------------------------------------------------------------------------------

all:
	$(compiler) $(flags) -o $(outDir)/$(appName) -I$(srcDir) -I$(extDir) $(shell find $(srcDir) -name '*.cpp')

test:
	$(compiler) $(flags) -o $(outDir)/test -I$(srcDir) -I$(extDir) -I$(testDir) $(testDir)/main.cpp