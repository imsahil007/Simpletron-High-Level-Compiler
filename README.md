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
    SML instructions will always be positive.
    SML data can be positive or negative.
    The first two digits of the SML instruction are the operation code.
    The last two digits of the SML instruction are the operand (i.e memory location of the operand)
- Opcodes used:
     READ      : 10
     WRITE     : 11
     LOAD      : 20
     STORE     : 21
     ADD       : 10
     SUBTRACT  : 31
     DIVIDE    : 32
     MULTIPLY  : 33
     BRANCH    : 40
     BRANCHNEG : 41
     BRANCHZERO: 42
     HALT      : 43


## Assumptions:
- All constants used in program are positive
  > We can still use negative constansts by writing 0 - $constantvalue in place of -$constant



### Support:
What do you think about this? Contact:
- [Sahil](https://www.github.com/imsahil007)
