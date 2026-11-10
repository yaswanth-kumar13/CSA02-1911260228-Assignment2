# Q3 – Bitwise Operators

## Predicted Register Values

| Operation | Register (Binary) | Decimal |
|---|---|---:|
| Initial register | 00000000 | 0 |
| Switch LIGHT ON | 00000001 | 1 |
| Switch AC ON | 00000101 | 5 |
| Toggle FAN | 00000111 | 7 |
| Switch LIGHT OFF | 00000110 | 6 |

## Observed Output

00000101
00000110
AC is ON, PUMP is OFF

The observed output matches the predicted output.

## Operator Precedence

`reg & (1u << dev)` first shifts 1u to the required bit position, then performs bitwise AND.

`(reg & 1u) << dev` first checks only the lowest bit and then shifts the result. These expressions are not equivalent.

## Signedness

Using signed char and setting bit 7 can produce a negative value. Bitwise operations on signed values can have implementation-related issues. unsigned char is safer for an 8-bit register.

## Alternative Concept: Array

An alternative is `char state[8]`, where each device uses one byte.

| Storage method | Memory per home | Memory for 1,000,000 homes |
|---|---:|---:|
| Bitwise register | 1 byte | 1 MB |
| char state[8] | 8 bytes | 8 MB |

Each device ON/OFF operation takes O(1) time in both approaches. Counting ON devices takes O(1) for a fixed eight-bit register and O(8) for the array.

## Conclusion

Bitwise operators store eight device states in one byte and reduce memory usage.