# Word Counting

For the following examples, I input `ctrl+D` to terminate program execution 
-- `ctrl+D` is read as `EOF` thus causing the while loop to exit.

Following are some test cases I'd write for this program.

## Nominal Case 1: Single Word
---
For example, a simple one-word input should easily count a single word and a 
single line:

**stdin**
```
word
```

Result: 
```
0 1 4
```

In the absence of a newline character, the line count is `0`. I feel this may
not be exactly right -- and I think in practice streams are usually suffixed
with a newline character.

## Nominal Case 2: Single Word Per Line
---
**stdin**
```
word1
word2
```

Result: 
```
1 2 11
```

Once again, here we can see that the number of lines seems to be off by one if 
the last line doesn't have a `\n` suffx.

## Edge Case 1: Special Characters
---
Beginning / ending the input with special characters could be another edge case.
These shouldn't affect the program if they're read in from stdin while the
program is in the "OUT" state, but verifying this behavior is important:

**stdin**
```
\t word \t \t
```

Result:
```
0 1 10
```

Assuming the line count is correct, this is the correct output. There are 10 
characters in the provided if you count spaces and tabs each as one character.

## Edge Case 2: Empty Lines
---
**stdin**
```




```

Result:
```
3 0 3
```

## Edge Case 3: Multiple Words Separated by Space
---

**stdin**
```
word1 word2
```

Result:
```
0 2 12
```

## Edge Case 4: Multiple Words Separated by Tab
---
**stdin**
```
word1\tword2
```

Result:
```
0 2 12
```

## Edge Case 5: Multiple Lines With Tabs
---
**stdin**
```
\t
\t

```

Result:
```
2 0 4
```
