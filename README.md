# bacteria

## Project Description

This C/ASM project explores the principle of self-reproduction through the implementation of a quine, a program that produces a copy of its own source code as output.<br />
It delves into the challenges associated with self-replicating code and serves as an excellent introduction to more complex topics, including malware development, providing insights into the mechanisms and implications of self-replicating programs.

## Features

The project includes both C and ASM versions of the self-replicating program, named **bacteria**.

### Functionality

When executed, the program performs the following actions:

- It creates a file named `bacteria_X.c` or `bacteria_X.s`, where `X` is an integer defined in the source code.
- After creating the file, it compiles and runs the newly created program.

### Execution Rules

1. The program stops based on the file name: it executes only if the integer `X` is greater than or equal to 0.
2. The integer, initially set to 50, is decremented with each execution, controlling how many iterations the program performs.

## Usage
### Build and run

- Build the project using `make`:
   ```bash
   cd ASM/  # Or cd C/
   make
   ./bacteria
   ```

### Testing

To test if all generated files are quines (i.e., they produce the same code with only the variable value differing), run:
```bash
make test
```
in the ASM/C directory.<br /><br />

This command will execute the test suite to verify that each generated program correctly replicates its source code, differing only in the index variable.

### Usage

Run the program:
```bash
./bacteria
```

### Screenshots

1. **Before Execution**:
<img src="screenshots/initial-state.png" />
No replication has occurred yet. Index is at 50.

3. **After Execution**:
<img src="screenshots/after-replication.png" width=80 />
This shows the replicated files created by the program.
