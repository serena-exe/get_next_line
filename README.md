*This project has been created as part of the 42 curriculum by SEBAVARO*

# Get_next_line

## Description

The `Get_next_line` function allows us to read a file line by line.

The goal of this project is to help students understand how static variables and read a file, `file.txt`.

---

## Objectives

- Understand how to read a file.
- Write clean, reusable, and robust code.
- Understand and use static variables.

---

## Function Structure
|Prototype|Parameter|Return Value|External Functions|
|:--|:--|:--|--|
|`char *get_next_line(int fd)`|`fd`: file descriptor|Read line: correct behavior `NULL`: there is nothing else to read, or an error occurred|`read`, `malloc`, `free`|

---

## Project Structure

┌── `get_next_line.h` Header file with all function prototypes <br>
├── `get_next_line.c` Function implementations<br>
└── `get_next_line_utils.c` Required functions

---
## Instructions

In order to run this code, you must create your own `main.c` file with your **main function** linked with the get_next_line.h. Don't forget to `#include "get_next_line.h"`.

Compile with:
```bash
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c
```
Run with:
```bash
./a.out
```

---
## Resources

- [Peer to peer](https://42angouleme.fr/admissions-42-angouleme/) 
- [This youtube video](https://www.youtube.com/watch?v=-Mt2FdJjVno)
- [Static variable in C](https://www.geeksforgeeks.org/c/static-variables-in-c/)

---
