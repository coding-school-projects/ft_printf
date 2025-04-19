# ft_printf

![C Language](https://github.com/senthilpoo10/badges/blob/main/badges/ft_printfe.png)  
*Reimplementing printf() — because `ft_putnbr()` and `ft_putstr()` aren’t enough!*

---

## Summary
This project involves recreating the standard C library function `printf()`, focusing on handling **variable arguments** and formatted output. The goal is to produce a lightweight version (`ft_printf`) that supports key conversions and adheres to strict performance and memory management standards.

---

## Features
### Mandatory Conversions
- `%c` : Character  
- `%s` : String  
- `%p` : Pointer address (hexadecimal)  
- `%d`, `%i` : Signed decimal integer  
- `%u` : Unsigned decimal integer  
- `%x`, `%X` : Hexadecimal (lowercase/uppercase)  
- `%%` : Percent sign  

### Bonus (Optional)
- **Flags**: `-0.` (left-justify, zero-pad, precision)  
- **Modifiers**: `# +` (alternate form, force sign, space padding)  

---

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/coding-school-projects/ft_printf.git
