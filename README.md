# Simpletron

Simpletron is a software based computer simulator which is capable of executing instructions written in Simpletron Machine Language (SML)

To initialize this code, use a command like this:
```
gcc main.c -o main
```
Then, execute the code i.e. compile SHL code like this:
```
./main $filename -o $outputfilename
```

Finally, for executing the SHL generated code, do this in Execution directory :
```
gcc main.c -o main
./main ../$outputfilename
```

##  About
- Simpletron contains an accumulator – a special register in which information is put before it uses in calculations and or examined in various ways
-	It has memory of size 100 words (can be extended) each word can be referenced by their location 00, 01, 02, ...., 99
-	Word is a signed four digit decimal number such as +3364, -1293, +0007, -0001
- SML instructions occupies one word of Simpletron's Memory
    > SML instructions will always be positive.
    > SML data can be positive or negative.
    > The first two digits of the SML instruction are the operation code.
    > The last two digits of the SML instruction are the operand (i.e memory location of the operand)
- Opcodes used:&nbsp;
    > READ      : 10&nbsp;
    > WRITE     : 11&nbsp;
    > LOAD      : 20&nbsp;
    > STORE     : 21&nbsp;
    > ADD       : 10&nbsp;
    > SUBTRACT  : 31&nbsp;
    > DIVIDE    : 32&nbsp;
    > MULTIPLY  : 33&nbsp;
    > BRANCH    : 40&nbsp;
    > BRANCHNEG : 41&nbsp;
    > BRANCHZERO: 42&nbsp;
    > HALT      : 43&nbsp;

## Assumptions:
- All constants used in program are positive&nbsp;
  > We can still use negative constansts by writing 0 - $constantvalue in place of -$constant&nbsp;


### Support:
What do you think about this? Contact:
- [Sahil](https://www.github.com/imsahil007)
