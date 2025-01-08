# Custom Shell Project

## Project Overview
This project involves building a custom shell from scratch using the C programming language. A shell is a command-line interpreter that acts as an interface between the user and the operating system, enabling users to execute commands, manage processes, and interact with the system efficiently. The project aims to explore the fundamental components of a shell and provide a robust implementation while maintaining simplicity and extensibility.

## Features
The custom shell will include the following features:

### Core Features
1. **Command Parsing**
   - Parse user input into commands and arguments.
   - Handle whitespace and special characters appropriately.

2. **Built-in Commands**
   - Implement common built-in commands such as:
     - `cd`: Change directory.
     - `exit`: Terminate the shell.
     - `help`: Display usage instructions.

3. **External Command Execution**
   - Locate and execute external programs using the `$PATH` environment variable.
   - Manage foreground and background execution of processes.

4. **Redirection**
   - Redirect standard input, output, and error streams:
     - Input redirection: `<`
     - Output redirection: `>`
     - Append output: `>>`

5. **Piping**
   - Support pipelines to connect the output of one command to the input of another (e.g., `ls | grep txt`).

6. **Environment Variables**
   - Support the use of environment variables (e.g., `$HOME`, `$PATH`).
   - Provide commands to display or modify environment variables.

7. **Error Handling**
   - Provide informative error messages for invalid commands, missing files, or syntax errors.

### Advanced Features (Optional)
1. **Command History**
   - Allow users to navigate through previously executed commands.

2. **Autocompletion**
   - Implement basic command and file autocompletion using the Tab key.

3. **Job Control**
   - Support foreground and background process management:
     - Suspend and resume jobs.
     - Display active jobs.

4. **Configuration Files**
   - Read user-specific configuration files (e.g., `.myshellrc`) during initialization to set up aliases or environment variables.

5. **Scripting Support**
   - Enable execution of shell scripts.

## Project Workflow

### 1. Initialization
- Initialize environment variables and default settings.
- Display a customizable shell prompt.

### 2. Main Loop
- **Prompt**: Display the shell prompt to the user.
- **Input**: Read a line of input from the user.
- **Parsing**:
  - Split the input into tokens (command and arguments).
  - Handle special characters for redirection and piping.
- **Execution**:
  - Determine if the command is built-in or external.
  - Execute built-in commands directly.
  - For external commands, create a child process using `fork` and execute the command using `exec` family functions.
  - Handle redirection and pipelines.
- **Completion**: Wait for the process to complete or manage it in the background.

### 3. Cleanup
- Free allocated memory and close open file descriptors.
- Exit gracefully on user request.

## Key Concepts and System Calls
### Input and Output
- `read`, `write` for basic I/O operations.

### Process Management
- `fork` to create child processes.
- `execvp` or `execve` to execute commands.
- `wait` and `waitpid` to manage process completion.

### File Management
- `open`, `close`, `dup2` for file descriptors and redirection.
- `chdir` for directory changes.

### Signals
- `signal` and `kill` for handling interruptions and job control.

## Project Structure
```
myshell/
├── src/
│   ├── main.c           # Entry point of the shell.
│   ├── parser.c         # Command parsing logic.
│   ├── executor.c       # Command execution logic.
│   ├── builtins.c       # Implementation of built-in commands.
│   ├── jobs.c           # Job control management.
│   └── utils.c          # Utility functions.
├── include/
│   ├── shell.h          # Header file for global definitions.
│   ├── parser.h         # Header for parser functions.
│   ├── executor.h       # Header for executor functions.
│   ├── builtins.h       # Header for built-in commands.
│   └── utils.h          # Header for utility functions.
├── Makefile             # Build script.
└── README.md            # Project documentation.
```

## How to Build and Run
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd myshell
   ```

2. Build the project:
   ```bash
   make
   ```

3. Run the shell:
   ```bash
   ./myshell
   ```

## Future Enhancements
- Implement advanced features like scripting and autocompletion.
- Improve error handling and debugging capabilities.
- Add support for more built-in commands and features.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

---

Happy Hacking!

