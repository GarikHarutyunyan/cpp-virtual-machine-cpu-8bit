Virtual machine for 8 bit CPU.

Virtual machine executes commands from Program.txt file.

This CPU has 6 Registers(r0,r1,r2,r2,r4,r5), Counter(which indicates the index of commands), Input and Output resgisters. 

Each command must have 8 bit length(e.g. 01110110), 

First two bits show the type of action - XX******
00****** - Immeadiate values (The immeadiate value is always saved on first register(r0))
  The next 6 bites show the number which must be saved in Register.
  
01****** - Arithmetical and Logical operations(AND, NAND, OR, NOR, ADD, SUB)
  The last 3 bits show which insturction must be done between r1 and r2, the result is saved on r3 
  ```
  01***000 - OR
  01***001 - NAND
  01***010 - NOR
  01***011 - AND
  01***100 - ADD
  01***100 - SUB
  ```
  
10****** - Copy from one register to another
  The next 6 bites show the source and destination registers,
  First 3 bits show the source resgiter
  ```
  10000*** - r0
  10001*** - r1
  10010*** - r2
  10011*** - r3
  10100*** - r4
  10101*** - r5
  10110*** - input
  ```
  
  Last 3 bits show the destination resgiter
  ```
  10***000 - r0
  10***001 - r1
  10***010 - r2
  10***011 - r3
  10***100 - r4
  10***101 - r5
  10***110 - output
  ```
11****** - Conditional operations (Never, =0, <0, <=0, Always true, !=0, >=0, >0), if the condition is true the value from r0 register will be coppied in Counter as a next operation index.
  The last 3 bits show the condition
  ```
  11***000 = Never
  11***001 = Reg 3 = 0
  11***010 = Reg 3 < 0
  11***011 = Reg 3 <= 0
  11***100 = Always
  11***101 = Reg 3 >= 0
  11***110 = Reg 3 > 0
  ```
