# Command Line Shell

![License](https://img.shields.io/badge/license-MIT-blue.svg)

## Table of Contents

- [Introduction](#introduction)
- [Objectives](#objectives)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)

## Introduction

Welcome to the hsh project, a custom shell that serves as a basic UNIX command-line interpreter. It reads commands from either a file or standard input and executes them. hsh follows a structured development approach, breaking down the process into specific tasks to create a functional command-line interpreter. These tasks encompass handling user input, executing commands, managing arguments, resolving the PATH, and incorporating built-in commands like exit and env.

## Objectives

The `hsh` project aims to achieve the following objectives:

1. **Create a User-Friendly Shell:** Develop a custom Unix shell, providing users with a command-line interface to interact with the operating system.

2. **Robust Command Execution:** Implement a command execution system that can handle both built-in and external commands seamlessly, to perform operations like file manipulation, process management, and more.

3. **Handle Built-in Commands:** Implement interactive features, such as `cd`, `exit`, `setenv`, `unsetenv`, tab completion, command history, and user-friendly enhancements, to improve the user experience.

4. **Robust Error Handling:** Provide informative error messages and graceful error recovery to aid users in troubleshooting and understanding issues.

5. **Command Separators:** Support command separators like `;`, `&&`, and `||` to execute multiple commands in a controlled sequence.

6. **Alias Management:** Implement the `alias` command to allow users to define and manage custom command aliases for increased productivity.

7. **Variable Handling:** Handle variable replacement, including `$?` and `$$`, to provide information about exit statuses and process IDs.

8. **Comment Support:** Enable the handling of comments using the `#` symbol to allow users to add remarks to their command scripts.

9. **File Input Mode:** Allow the shell to take a file as a command-line argument, executing commands from the file and enhancing automation capabilities.

## Features

### Invocation
Usage: To invoke or use hsh, open your terminal and navigate to the directory where you've compiled the hsh shell (typically using gcc as shown in the "Getting Started" section). Once you're in the directory, run the shell using the following command:

Example: This command starts the hsh shell, and you'll see a shell prompt like this:
```shell
$ ./hsh
```

Now, you can start entering commands and interacting with the shell. hsh will read your input, process commands, and provide output as expected.

Example: Enter simple commands and see their execution results:
```shell
$ ./hsh
$ ls
file1.txt  file2.txt  directory
$
```

### Environment
In hsh, you have access to a range of environment variables, which are crucial for configuring and interacting with the system. Here are some of the commonly used environment variables:

#### HOME
The `HOME` environment variable points to the user's home directory. It represents the default location where a user's files and configurations are stored. You can use it to quickly navigate to your home directory.

Example: Environment variable in hsh
```shell
$ ./hsh
$ echo $HOME
/home/user
```

#### PWD
The `PWD` (Present Working Directory) environment variable reflects the current directory you are working in. It dynamically updates as you move between directories within hsh, allowing you to keep track of your location.

Example: Environment variable in hsh
```shell
$ ./hsh
$ echo $PWD
/home/user/documents
```

#### OLDPWD
The `OLDPWD` environment variable holds the path to the previous working directory. It's helpful for returning to your last location after navigating to a different directory.

Example: Environment variable in hsh
```shell
$ ./hsh
$ echo $OLDPWD
/home/user
```

#### PATH
The `PATH` environment variable specifies a colon-separated list of directories where executable files can be found. When you execute a command in hsh, it searches through the directories listed in `PATH` to locate and run the corresponding executable.

Example: Environment variable in hsh
```shell
$ ./hsh
$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
$
```

### Command Execution
The process of command execution in hsh is structured as follows:

1. User input is collected and parsed to identify the command and its accompanying arguments.
2. hsh patiently waits for input from the command line.
3. The user's input is divided into tokens, distinguishing between commands and their associated arguments.
4. The command and its arguments are identified, with the first token typically representing the command and subsequent tokens representing its arguments.
5. The recognized command is then compared to a list of supported built-in commands in hsh, such as `cd`, `exit`, `setenv`, `unsetenv`, and `alias`.
6. If the command is found to be a built-in command, the corresponding built-in function is executed directly by the shell.
7. If the command is not a built-in command, it is treated as an external command.

In hsh, you have the flexibility to execute a wide range of commands, both external and built-in, enabling interactions with the operating system. Here's a concise overview of how command execution functions in hsh:

- External Commands: Hsh has the capability to execute external commands by specifying the command's name, such as ls, cat, or echo. It searches for these commands in directories listed in the PATH environment variable. Upon finding a match, it proceeds to run the command.

- Built-in Commands: Hsh also includes built-in commands, which are commands inherent to the shell itself. Some examples of built-in commands in hsh are cd, exit, setenv, and unsetenv. These commands are executed directly by the shell, bypassing the need for an external process.

Example:
```shell
$ ./hsh
$ ls -l
total 56
-rwxrwxr-x 1 user user 18432 Oct 10 09:00 hsh
-rw-rw-r-- 1 user user   106 Oct 10 09:00 main.h
-rw-rw-r-- 1 user user   349 Oct 10 09:00 shell.c
-rw-rw-r-- 1 user user   296 Oct 10 09:00 README.md
$ echo "Hello, hsh!"
Hello, hsh!
$
```

### Exit Status
In hsh, managing the exit status of commands involves monitoring the results of executed processes or commands and conveying this information to the user. This exit status is a numerical value that signifies whether the command executed successfully or faced an error. Following the execution of a command, hsh delivers an exit status to signify the outcome of the command execution. This exit status, represented as an integer, aids in determining whether the command achieved success or encountered an issue.

#### Here's how you can access and interpret the exit status in hsh:

The exit status is stored in the special environment variable $?.
A value of 0 typically indicates a successful execution, while non-zero values indicate an error or failure. By checking the exit status, you can decide on further actions or script flows.

#### Here's an example of accessing the exit status in hsh:

Example: Run the ls command on a non-existent directory, which results in an exit status of 2, indicating an error.
```shell
$ ./hsh
$ ls non_existent_directory
ls: cannot access 'non_existent_directory': No such file or directory
$ echo $?
2
$
```

### Signals
signals are a form of asynchronous notifications that are sent to processes to notify them of specific events or conditions. Signals can be used for various purposes, including process management, interruption, and termination.

#### Handle common signals like Ctrl+C (SIGINT) and Ctrl+Z (SIGTSTP).

Ctrl+C (SIGINT)

- When the user presses Ctrl+C, the shell should not terminate but instead interrupt the currently running command. The user runs the long running command in the shell. When they press Ctrl+C, the shell receives the SIGINT signal and interrupts the running command, returning the user to the shell prompt.

Example:
```shell
$ ./hsh
$ long_running_command
^C
$
```

Ctrl+Z (SIGTSTP)

- When the user presses Ctrl+Z, the shell should suspend the currently running command, similar to how background processes are managed. The user runs the running command in the shell when Ctrl+Z is pressed the shell receives the 'SIGTSTP'  signal and suspends the command, allowing the user to continue working with the shell and and even run other commands to bring the suspended process back to the foreground.

Example:
```shell
$ ./hsh
$ running_command
^Z
[1]+  Stopped                 running_command
$ other_command
$
```

### Variable Handling
hsh allows variable replacement using special symbols. The `$?` symbol retrieves the exit status of the last executed command, providing valuable information about command success or failure. The `$$` symbol returns the Process ID (PID) of the current shell, enabling process management within scripts. There are two primary types of variable replacements supported:

#### $ENV_VARIABLE
You can access environment variables by prefixing their names with a dollar sign ($). For example, to access the `HOME` environment variable, use `$HOME`. hsh dynamically resolves these variables, providing you with information about the environment.

#### $?
The `$?` variable allows you to access the exit status of the last executed command. After executing a command, you can check the value of `$?` to determine whether the command succeeded (usually 0) or encountered an error (a non-zero value).

Example:
```shell
$ ./hsh
$ ls /some/directory
$ echo $?
0
$
```

#### $$
The `$$` variable provide information about exit statuses and process IDs.
The $$ represents a variable replacement feature that allows users to retrieve the process ID (PID) of the current running shell. Retrieve the PID and use it for various purposes, such as identifying and managing processes within scripts and commands executed in hsh. When parsing the user's input, search for the occurrence of $$. Once identified, replace it with the PID of the current shell.

Example:
```shell
./hsh
$ echo $$
12345
```
### Comment Support
Comments in hsh provide a way to add remarks and annotations to command scripts. They are ignored by the shell and are for informational purposes only. In hsh, comments are created using the `#` symbol, and everything following `#` on a line is treated as a comment:

Example: The text after `#` is a comment and is not processed as part of the command.
```shell
$ echo "Hello, World!"  # This is a comment
```

### Operators
Operators in hsh provides support for logical operators `&&` and `||`, enabling conditional execution of commands based on the success or failure of preceding commands. it control's the execution flow of commands. They allow you to sequence multiple commands, create conditional execution paths, and manage script behavior.

hsh supports the following operators:
#### ;
(Command Separator): The semicolon `;` is used to separate and execute multiple commands sequentially. Each command is executed one after the other, regardless of the success or failure of the previous command.

Example:
```shell
$ echo "Command 1" ; echo "Command 2"  # Executes both commands sequentially
```

#### &&
(AND Logical Operator): The `&&` operator is used to execute the second command only if the first command succeeds (returns 0). It's often used for conditional execution.

Example:
```shell
$ ls non_existent_file && echo "File exists"  # The second command is executed if the first succeeds
```

#### ||
(OR Logical Operator): The `||` operator is used to execute the second command only if the first command fails (returns a non-zero value). It's also used for conditional execution.

Example:
```shell
$ ls non_existent_file || echo "File does not exist"  # The second command is executed if the first fails
```

### Alias Management
#### alias
- Usage: alias [name[='value'] ...]
- Prints a list of all aliases, one per line, in the form name='value' if no arguments are provided.
- Prints the aliases name, name2, etc., one per line, in the form name='value if arguments are provided.
- Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value.
- Prints an error message on failure.

Examples:
#### Listing all aliases:
```shell
$ alias
name1='value1'
name2='value2'
```
#### Listing specific aliases:
```shell
$ alias name1 name2
name1='value1'
name2='value2'
```

#### Defining aliases:
```shell
$ alias my_alias='echo Hello, World!'
```

### Handle Built-in Commands
The hsh shell includes several built-in commands that are part of the shell itself. These built-ins provide essential functionality for users. Notable built-ins include:
  - `cd`: Change the current working directory.
  - `exit`: Terminate the shell, with optional status code.
  - `env`: Display the current environment variables.
  - `setenv`: Initialize or modify environment variables.
  - `unsetenv`: Remove environment variables.
  - `alias`: Manage command aliases for increased productivity.

#### cd
The cd command is used to change the current working directory of the hsh shell. It allows you to navigate the file system within the shell by specifying the directory you want to move to. If you run cd without specifying a directory, it changes to the user's home directory. If you provide a directory as an argument, the shell will change to that directory.

When a user enters a command in hsh, it check's if the command is "cd." by comparing the user's input with the string "cd.". The cd command can be used with or without an argument. If an argument is provided, it specifies the directory to which the user wants to change. If no argument is provided, cd navigate's to the user's home directory. it Check's the return value of the function to determine if the directory change was successful or print an error message if the directory change fails. The error message provide's information about the cause of the failure.

Usage:
```shell
$ cd [DIRECTORY]
```

Example:
```shell
$ ./hsh
$ cd /home/user/documents
$ pwd
/home/user/documents
$
```
In the example above, running cd /home/user/documents changes the current directory to /home/user/documents, as verified by the pwd (print working directory) command.

Example:
```shell
$ ./hsh
$ cd ..
$ pwd
/home/user
$
```
In this example, running cd .. moves up one directory, changing the current directory to /home/user.

#### exit
Usage:
```shell
$ exit [STATUS]
```
The exit command take's a status code as an argument, which is an integer value indicating the exit status.
If you run the exit command without specifying a status code, it will exit or terminate the hsh shell with a status code of 0 by default. If you provide a status code, the shell will exit with the specified status code.

Example: Running the exit command without specifying a status code exits the hsh shell, and you return to your system's default shell.
```shell
$ ./hsh
$ exit
$
```

Example: Running exit 2 exits the hsh shell with a status code of 2.
```shell
$ ./hsh
$ exit 2
$
```

#### env
- Usage: env
- print the current environment variables.

Example:
```shell
$ ./hsh
$ env
USER=your_username
HOME=/home/your_username
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
$
```
#### setenv
- Usage: `setenv VARIABLE VALUE`
- Initializes or modifies an environment variable.
- Prints an error message on failure.

Example:
```shell
$ setenv MY_VAR my_value
$ setenv NAME cat
$ echo $NAME
cat
```

#### unsetenv
- Usage: unsetenv VARIABLE
- Removes an environment variable.
- Prints an error message on failure.

Example:
```shell
$ unsetenv MY_VAR
$ unsetenv NAME
```

#### `getline`
The hsh shell features a custom `getline` function that efficiently processes user input by reading multiple characters at once, reducing the use of the `read` system call. This optimization enhances the overall performance and responsiveness of the shell.

## Getting Started
To get started with the hsh custom shell, follow these simple steps:

1. Clone this repository: `git clone https://github.com/YourUsername/simple_shell.git`

2. Compile the source code into an executable binary:
   ```shell
   gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
   ```

##  Usage
Run hsh in your terminal to test its functionality.
Here's an example of how to use hsh:
 ```shell
$ ./hsh
$ echo "Hello, hsh!"
Hello, hsh!
$ ls
file1  file2  file3
$ cd /path/to/directory
$ ls
subfile1  subfile2
$ exit
$
```

## License
This project is open source and available under the [MIT License](./LICENCE).
