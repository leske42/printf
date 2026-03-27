*This project has been created as part of the 42 curriculum by leske.*

## Description
`ft_printf` is a custom and simplified version of the standard C `printf` function, built as a static library for the 42 curriculum.

It is a very simple implementation, but I tried to refactor it to be a reference for avoiding the most common mistakes with the project including **passing `va_list` by value** to a subroutine (this leads to UB by Standard) or ignoring the return value of `write`. I also try to protect against abuses of invalid format strings with `format(printf)` function attribute.

Project goal:
- Understand and practice variadic functions with `stdarg.h`.
- Reproduce the core behavior of `printf` for a defined set of conversion specifiers.
- Build reliable low-level output routines using system calls and standard C basics.

This implementation supports the following conversions:
- `%c` character
- `%s` string (prints `(null)` for `NULL`)
- `%p` pointer (hexadecimal with `0x` prefix, `(nil)` for `NULL`)
- `%d` and `%i` signed decimal integer
- `%u` unsigned decimal integer
- `%x` unsigned hexadecimal (lowercase)
- `%X` unsigned hexadecimal (uppercase)
- `%%` literal percent sign

The function returns:
- Total number of printed characters on success.
- `-1` on write/format errors.

On passing `NULL` as the format string, the behavior is undefined.

## Instructions

Run `make` from the repository root. This creates the static library `libftprintf.a`.
Link library against your executable with 

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o hehe
```
If needed, include the header `"ft_printf.h"` in your source.

### Minimal usage example

```c
#include "ft_printf.h"

int main(void)
{
	int n;

	n = ft_printf("Hello %s, value=%d, hex=%x, ptr=%p, %%\n", "42", -12, 255, (void *)0);
	ft_printf("printed chars: %d\n", n);
	return (0);
}
```

## Resources
- man `printf`: https://man7.org/linux/man-pages/man3/printf.3.html
- man `stdarg`: https://man7.org/linux/man-pages/man3/stdarg.3.html


## AI usage disclosure:
AI was used to generate some parts of this README.

Furthermore, because the subject specifically asked me to include "**a detailed explanation and justification of the chosen algorithm and data structure**", which I found to be pretty absurd for this project, I asked Codex to generate this explanation which I will leave here because I found it to be very funny (and fitting of the weird requirements).

### Algorithm and Data Structure Choices (Detailed)
#### Overall parsing algorithm
The main `ft_printf` loop is a single left-to-right scan over the format string.

Why this approach:
- Time complexity is linear in the format length: $O(n)$.
- It is simple, deterministic, and easy to reason about for the mandatory conversion set.
- It minimizes state: only current index, total length, and variadic argument list are needed.

How it works:
1. Read one character at a time.
2. If the character is not `%`, print it directly.
3. If `%` is found, read the next character as the conversion type.
4. Validate the type against supported flags.
5. Dispatch to the dedicated print routine (`print_c`, `print_s`, `print_signed`, `print_unsigned`).
6. Accumulate the number of written characters.
7. If any print call fails (`write` error), immediately return `-1`.

#### Conversion dispatch strategy
A compact chain of conditionals maps each conversion specifier to the correct helper function.

Why this is justified here:
- The number of supported specifiers is small and fixed.
- It avoids extra indirection and keeps behavior explicit.
- It is straightforward to verify against 42 project requirements.

#### Number-to-string conversion strategy
For signed and unsigned output, numbers are converted by repeatedly dividing by the base and storing remainders into a fixed-size local buffer from right to left.

Why this algorithm:
- Classical, proven base-conversion method.
- No dynamic allocation required.
- Produces digits in correct order after reverse fill.
- Works for decimal and hexadecimal with the same logic by changing the base and alphabet.

Complexity:
- For each printed number: $O(k)$ time, where $k$ is number of output digits.
- Space: $O(1)$ extra space (fixed stack buffer).

#### Chosen data structures
1. `va_list` for variadic argument traversal.
- Required and idiomatic for C variadic functions.
- Provides portable sequential access to runtime argument values.

2. Fixed-size local `char` buffers for number formatting.
- In `print_signed`: enough capacity for sign and decimal digits of 32-bit integer values.
- In `print_unsigned`: enough capacity for 64-bit pointer/unsigned hexadecimal representation and terminator.
- Prevents heap overhead and fragmentation.

3. Primitive scalar state (`int`, `size_t`, `bool`) and index counters.
- Keeps implementation minimal and predictable.

#### Error-handling approach
Every write path returns character count or failure. `ft_printf` aggregates counts and short-circuits on errors.

Why this matters:
- Matches the expected `printf`-style contract where return value is meaningful.
- Prevents reporting partial success as total success when output fails.

#### Technical Choices
- Language: C
- Build system: Makefile
- Output backend: `write(1, ...)` from `<unistd.h>`
- Standard headers used: `<stdarg.h>`, `<stddef.h>`, `<stdbool.h>`

