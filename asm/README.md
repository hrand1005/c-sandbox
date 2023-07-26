# ASM

These assembly programs are intented to be used with NASM assembler, which uses
Intel syntax, ie 
```assembly
mov eax, 5
```
where eax is the destination and 5 is the source. 

By contrast, the AT&T syntax (usually used on UNIX systems) switches the source
and destination args:

```assembly
mov 5, %rax
```
