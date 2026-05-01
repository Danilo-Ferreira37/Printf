# ft_printf

Reimplementation of the C standard library function `printf`, developed as part of the **42 School** curriculum.

This project builds a static library `libftprintf.a` providing `ft_printf()` and a small set of helper output functions.

---

## Table of Contents

- [Supported conversions](#supported-conversions)
- [Project structure](#project-structure)
- [Build](#build)
- [How to use](#how-to-use)
- [API](#api)
- [Return value & errors](#return-value--errors)
- [Notes](#notes)
- [Author](#author)

---

## Supported conversions

Implemented in this repo (see `handle_format()` in `ft_printf.c`):

- `%c` character
- `%s` string (prints `(null)` when argument is `NULL`)
- `%p` pointer address (hex, `0x...`; prints `(nil)` when pointer is `NULL`)
- `%d` / `%i` signed decimal integer
- `%u` unsigned decimal integer
- `%x` unsigned hexadecimal (lowercase)
- `%X` unsigned hexadecimal (uppercase)
- `%%` literal percent sign

---

## Project structure

- `ft_printf.c` — main `ft_printf()` + format dispatcher (`handle_format`).
- `ft_printf_utils.c` — basic printers (`ft_putchar`, `ft_putstr`, `ft_putnbr`).
- `ft_printf_utils2.c` — base/hex helpers (`ft_base`, `ft_print_adress`).
- `ft_printf.h` — public header.
- `Makefile` — builds `libftprintf.a`.

---

## Build

Compile the library:

```bash
make
```

This generates:

- `libftprintf.a`

Clean object files:

```bash
make clean
```

Remove objects + library:

```bash
make fclean
```

Rebuild from scratch:

```bash
make re
```

---

## How to use

1) Include the header:

```c
#include "ft_printf.h"
```

2) Compile your program linking with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
```

Example `main.c`:

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;
    ft_printf("Hello %s! n=%d hex=%x ptr=%p %%\n", "world", n, n, &n);
    return (0);
}
```

---

## API

Public functions (see `ft_printf.h`):

```c
int ft_printf(const char *s, ...);

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int nbr);
int ft_base(unsigned int n, unsigned int base, char *symbols);
int ft_print_adress(void *adrs, unsigned int base_len, char *base);
```

---

## Return value & errors

- `ft_printf()` returns the **number of characters written**, similar to `printf()`.
- Returns `-1` if:
  - the format string `s` is `NULL`, or
  - an unsupported conversion is found (the implementation returns `-1` from `handle_format`).

---

## Notes

- Output is written to **stdout** using `write(1, ...)`.
- `%s` prints `(null)` for `NULL` pointers.
- `%p` prints `(nil)` for `NULL` pointers.
- This repo currently contains a `main()` inside `ft_printf.c` used for local testing. In a real integration, you typically remove/comment this test `main` and compile only the library.

---

## Author

- GitHub: [Danilo-Ferreira37](https://github.com/Danilo-Ferreira37)