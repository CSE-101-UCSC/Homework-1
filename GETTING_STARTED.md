# Getting Started: CSE 101 Programming Assignment 1

The full assignment description is in the handout PDF. This page explains how to use this repository.

## Setup

1. Create your own **private** repository from this template.
2. Open it in a GitHub Codespace: **Code → Codespaces → Create codespace on main**. The Codespace has the same compiler as Gradescope.
3. In the Codespace terminal, run `make`. You should see `Rule check passed.` followed by a successful build.

You can also work on your own Mac or Windows computer instead of a Codespace. See [Working on your own computer](#working-on-your-own-computer) below.

## What is in this repository

| File or folder | What it is | Can you edit it? |
|---|---|---|
| `main.cpp` | `main()`: reads the command line and input file, then uses your list functions. Starts as a `TODO`. | **Yes** |
| `movies.cpp` | Your linked list functions. Every function starts as a `TODO`. | **Yes** |
| `README.md` | Your answers to the handout's questions, and your citations | **Yes** |
| `movies.h` | Data types and the functions you must implement | No |
| `Makefile` | Checks the rules and builds `./LinkedList` | No |
| `run_tests.sh` | Runs the visible tests | No |
| `scripts/` | The rule checker used by `make` | No |
| `tests/` | One folder per visible test | No |

Gradescope uses the original copies of every file you cannot edit. If you change one by accident, restore it with `git checkout -- <file>`.

## Building

```
make          # check the rules, then build ./LinkedList
make clean    # remove the program and saved test output
```

`make` refuses to build if any rule is broken. It tells you which rule and how to fix it.

## Running your program

```
./LinkedList tests/10_dup_sample/input.txt
./LinkedList tests/16_filter_year/input.txt --year 1994
./LinkedList tests/20_filter_actor/input.txt --actor "Tom Hanks"
```

To save the output to a file as well as seeing it: `./LinkedList input.txt | tee my_output.txt`

## Testing

```
./run_tests.sh            # run every visible test
./run_tests.sh sort       # run only tests with "sort" in the name
./run_tests.sh 12         # run only test 12
./run_tests.sh --list     # list every test and what it checks
make test                 # same as ./run_tests.sh
```

For each failing test, the script shows the command, what the test checks, and a comparison:

```
--- expected
+++ your output
@@ -3,2 +3,2 @@
-1994 | Little Women | Christian Bale      <- this line was expected
+1994 | Pulp Fiction | John Travolta       <- your program printed this instead
```

When every test passes, it prints `All 26 tests passed!`. Your program's output for every test is saved in `test_output/`, and what it printed to `std::cerr` is saved next to it in a `.stderr.txt` file.

These are the visible tests only. Gradescope also runs hidden tests, so passing everything here does not guarantee full credit. Write extra input files of your own and check the results by hand.

## Rules enforced by `make`

- The only source files are `main.cpp` and `movies.cpp`. No other `.cpp` or `.h` files.
- `movies.h` must not be changed. Put helper functions in `main.cpp` or `movies.cpp` as `static` functions; do not declare them in `movies.h`.
- `main()` is defined in `main.cpp`, and every function in `movies.h` is defined in `movies.cpp` with the exact same name and parameters.
- Your files may include only `<string>`, `<iostream>`, `<fstream>`, `<sstream>`, `<cstring>`, `<cstdlib>`, and `"movies.h"`.
- No standard containers (`vector`, `list`, `map`, ...) and no library sorting (`std::sort`, `qsort`, ...).
- Code is compiled with `g++ -std=c++17 -Wall -Wextra -pedantic-errors`.

## Working on your own computer

A Codespace needs no setup and uses the same compiler as Gradescope, so it is the safest choice. If you would rather work on your own computer, set it up once as follows, then clone your private repository (`git clone <your repository URL>`) and use `make` and `./run_tests.sh` exactly as described above.

**macOS.** Open Terminal and run `xcode-select --install` to install Apple's compiler and `make`. On a Mac, `g++` is Apple's clang compiler rather than GNU g++. Code that builds on a Mac almost always builds on Gradescope, but Gradescope's result is the one that counts: if it reports a build error that your Mac did not, fix it and submit again.

**Windows.** Use WSL (Windows Subsystem for Linux), which gives you the same Linux tools as Gradescope:

1. Open PowerShell as administrator, run `wsl --install`, and restart your computer.
2. Open **Ubuntu** from the Start menu and run `sudo apt update && sudo apt install -y g++ make git`.
3. Clone your repository inside Ubuntu's home folder (run `cd ~` first), not in a Windows folder under `/mnt/c`.

Do your work in the Ubuntu terminal. VS Code can open the folder with the **WSL** extension.

## Submitting

1. Run `make clean`, then commit and push your work to your private repository.
2. On Gradescope, submit with the **GitHub** option and choose your repository and branch.
3. Gradescope grades the code at the moment you submit. If you push changes later, submit again.
