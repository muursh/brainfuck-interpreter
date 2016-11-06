# Brainfuck interpreter

An interpreter for the brainfuck langauge. 

The 8 commands of brainfuck:
'>' increment the data pointer;
'<' decrement the data pointer;
'+' increment the byte at the data pointer;
'-' decrement the byte at the data pointer;
'.' output the byte at the pointer;
',' take one byte of input;
'[' if the byte at the pointer is zero, jump to the command after the matching ']';
']' if the byte at the pointer in nonzero, jump back to command after the matching '['.

C equivalents of the brainfuck commands:
'>'   ++ptr;
'<'   --ptr;
'+'   ++*ptr;
'-'   --*ptr;
'.'   putchar(*ptr);
','   *ptr=getchar();
']'   }
'['   while(*ptr){

for more information see http://www.muppetlabs.com/~breadbox/bf/
