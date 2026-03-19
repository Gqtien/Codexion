*This project has been created as part of the 42 curriculum by gviola-l.*

# Codexion

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Command-line arguments](#command-line-arguments)
- [Logging format](#logging-format)
- [Resources](#resources)

---

## `🔍` Description

**Codexion** is a concurrency simulation written in C, inspired by the classic **Dining Philosophers problem**. In this scenario, multiple "coder" threads compete for a limited number of USB dongles to perform compilation tasks.

This implementation illustrates the philosopher theorem in practice: how multiple concurrent actors can safely share limited resources without deadlocks or starvation, while respecting strict timing constraints.

---

## `🚀` Instructions

Build with the provided Makefile. The project compiles with -Wall -Wextra -Werror and links pthread.

```bash
# from project root
make

# run the program (example)
./codexion 5 800 200 200 200 3 100 fifo
```

---

## `⚙️` Command-line arguments

All arguments are mandatory and must be positive integers except `scheduler` which must be `fifo` or `edf`.

1. number_of_coders | number of coders
2. time_to_burnout (ms) | deadline: if a coder does not start compiling before this window since their last compile or simulation start, they burn out
3. time_to_compile (ms)
4. time_to_debug (ms)
5. time_to_refactor (ms)
6. number_of_compiles_required | simulation ends when every coder reached this compile count
7. dongle_cooldown (ms) | after a dongle is released it is unavailable for this cooldown
8. scheduler | `fifo` (First In, First Out) or `edf` (Earliest Deadline First)

Example:

```bash
./codexion 4 1000 200 200 200 5 100 edf
```

---

## `📝` Logging format

Every state change is printed on its own line with a timestamp in milliseconds and the coder id. 

e.g:
```
0 1 has taken a dongle
1 1 has taken a dongle
1 1 is compiling
201 1 is debugging
401 1 is refactoring
1204 3 burned out
```

---

## `📁` Resources

- [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX threads documentation](https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html)

### AI usage

- Drafting and polishing this README and usage examples.
- Identifiying edge-case failures.
