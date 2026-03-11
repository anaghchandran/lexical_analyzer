#  C Lexical Analyzer

A simple lexical analyzer (tokenizer) written in C. It reads a source file, tokenizes its contents, and classifies each token as a **keyword**, **operator**, or **special character**.

---

## Project Structure

| File | Description |
|------|-------------|
| `header.h` | Shared macros (`DONE`, `FAILED`) and function declarations |
| `lexical.c` | Core tokenization logic — keyword lookup, operator & special char detection |
| `main.c` | Entry point — handles CLI args, user input loop, and calls the lexer |
| `test.txt` | Sample C source file used as test input |

---

## How It Works

The analyzer reads a file token by token using `fscanf`, then classifies each whitespace-delimited token:

- **Keywords** — compared against 20 standard C keywords (`int`, `float`, `return`, `if`, `else`, `while`, etc.)
- **Operators** — detected if the first character is in: `+ - * / % = ! < > | &`
- **Special Characters** — detected if the first character is in: `, ; { } ( ) [ ]`
- **Other tokens** (identifiers, literals) — read but not explicitly labeled

---

## Build & Run

### Prerequisites
- GCC or any standard C compiler
- A Unix-like terminal (Linux, macOS, WSL)

### Compile
```bash
gcc main.c lexical.c -o lexer
```

### Run
```bash
./lexer test.txt
```

The program reads the file, prints token classifications, then enters an interactive loop to optionally process another file.

### Example Output
```
keyword -> int
keyword -> return
operators -> =
operators -> ;
```

---
# C Lexical Analyzer

A simple lexical analyzer (tokenizer) written in C. It reads a source file, tokenizes its contents, and classifies each token as a **keyword**, **operator**, or **special character**.

---

## Project Structure

| File | Description |
|------|-------------|
| `header.h` | Shared macros (`DONE`, `FAILED`) and function declarations |
| `lexical.c` | Core tokenization logic — keyword lookup, operator & special char detection |
| `main.c` | Entry point — handles CLI args, user input loop, and calls the lexer |
| `test.txt` | Sample C source file used as test input |

---

## How It Works

The analyzer reads a file token by token using `fscanf`, then classifies each whitespace-delimited token:

- **Keywords** — compared against 20 standard C keywords (`int`, `float`, `return`, `if`, `else`, `while`, etc.)
- **Operators** — detected if the first character is in: `+ - * / % = ! < > | &`
- **Special Characters** — detected if the first character is in: `, ; { } ( ) [ ]`
- **Other tokens** (identifiers, literals) — read but not explicitly labeled

---

## Build & Run

### Prerequisites
- GCC or any standard C compiler
- A Unix-like terminal (Linux, macOS, WSL)

### Compile
```bash
gcc main.c lexical.c -o lexer
```

### Run
```bash
./lexer test.txt
```

The program reads the file, prints token classifications, then enters an interactive loop to optionally process another file.

## Token Classification Reference

| Category | Examples | Detection Method |
|----------|----------|-----------------|
| Keyword | `int`, `float`, `if`, `while`, `return` | `strcmp` against `keywords[20]` array |
| Operator | `+ - * / % = ! < > \| &` | `strchr` on operators string |
| Special Char | `, ; { } ( ) [ ]` | `strchr` on specialCharacters string |
| Other | identifiers, literals, numbers | Falls through (not printed) |

---

## Known Limitations & Bugs

- `fscanf` splits on whitespace only — multi-character operators (`==`, `!=`, `<=`) are not handled correctly
- Preprocessor directives like `#include` are not classified
- String literals and comments in source files will be split and misclassified
- `checking_token()` in `lexical.c` is missing its return type declaration (implicit `int` — compiler warning)
- `read_and_validate()` has no explicit return at the end of the success branch (undefined behavior)
- In `main.c`, `strcmp(argv[1], string)` result is unused — should likely be `strcpy` to update the filename
- The interactive loop does not correctly update `argv[1]` with the new filename

---

## Author
**Anagh CS** — Embedded Systems Engineer  
[GitHub](https://github.com/anaghchandran) | [LinkedIn](https://www.linkedin.com/in/anagh-chandran)
