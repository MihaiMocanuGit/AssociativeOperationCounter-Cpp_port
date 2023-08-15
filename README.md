# AssociativeOperationCounter-Cpp_port
In hopes of trying to make it faster, it's a cpp port of: https://github.com/MihaiMocanuGit/AssociativeOperationsCounter

Will count and show all possible associative operations on a finite set of N elements, where N <= 4 for now

# Compilation
To create a Makefile and run it using CMake:
* `cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug` 
* `make`
* `./AssociativeOperationCounter_Cpp_port`

### Notes:
To compile it under release mode in order to speed up running time use:
* `cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release` 

Although in my case, the first few times this caused the program to `SIGSEGV`.
I'm not sure if I was able to completely fix it. So please keep this in mind in case it crashes.

This was only tested on Linux.

# Output files
The program will create a file `output_<<N>>.txt` with all generated semigroups. 

The file will be located in the same directory as the executable, usually it will be in the parent directory. 
( but, for example, when running the program in CLion, the output files will actually be stored in `cmake-build-debug/`
or `cmake-build-release/`)

# Changing the cardinal of the set
To modify the cardinal of the set on which you are generating semigroups, please modify in `main.cpp` the line 
`constexpr int CARDINAL_SET = <<Insert New Cardinal>>;` and recompile the program.

# Optimisation ideas:
Similarly to how I computed isomorphisms from one semigroup to another. I could do the same to
the other non-associative grupoids. This way I refrain from checking associativity on a structure which is isomorphic to 
another non-associative structure.

The big downside for this would be heavy RAM/Heap usage
