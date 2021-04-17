appName = jump-n-run

outDir = source/build
srcDir = source/code/intern/src
extDir = source/code/extern/sfml/include

compiler = clang++
flags = -std=c++11 -Wall -Wextra

# ------------------------------------------------------------------------------

all:
	$(compiler) $(flags) -o $(outDir)/$(appName) -I$(srcDir) -I$(extDir) $(shell find $(srcDir) -name '*.cpp')