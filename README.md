This is the course project for the hardware/software co-desion instructed by Professor Paulo Garcia and is developed by Mahsa Layeghi.

# How to Build?

To build the code, run `make clean` and then `make all` commands in the terminal. This will compile and generate everything needed to run and test the compiler.

# How to Run and Test?

Execute the compiler using: `./a.exe tinylang.c`

# Brief Report

The following functionalities have been implemented:

1. *Scanner*
- Tokenizes everything and checks the validity of tokens
- If there is an undefined token, it raises an error!
2. *Parser*
- Builds a DST for each type
- Prints DST function and is implemented for the purpose of debugging and test
- When combining logical expressions, parenthesis is mandatory. However, a single logical expression should not have paranthesis.
3. *Semantic Analyzer*
- Checks semantic function by going through all the DST nodes and ultimately prints the number of errors found and a brief description of the errors.
- If no error is found, it goes to the next stage.
4. *IR Generator*
- Generates p-code from DST. 
- Print IR will show the generated IR code. 
5. *Interpreter*
- Fully implemented, but raises an error regarding labels.
