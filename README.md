*This project has been created as part of the 42 curriculum by SEBAVARO*

# Get_next_line

## Description

`Get_next_line` is a function that allow us to read a file line by line.

The goal of this project is to help students understand how static variables work and parse a `file.txt`

---

## Objectifs

- 

---

## Function structure
|Prototype|Parameter|Return value|External functions|
|:--|:--|:--|--|
|`char *get_next_line(int fd)`|`fd`: file descriptor|Read line: correct behavior NULL: there is nothing else to read, or an error occurred|read, malloc, free|

---

## Project Structure

┌── `get_next_line.h` Header file with all function prototypes <br>
├── `get_next_line.c` Function implementations<br>
└── `get_next_line_utils.c` Requiered functions

---
## Instructions

Compile with:
```bash
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c
```
Run with:
```bash
./a.out
```

---
## Ressources

- peer to peer 
- youtube video
- static variable

---