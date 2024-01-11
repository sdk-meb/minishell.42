# minishell.42

[**bash manual**](https://www.gnu.org/software/bash/manual/bash.html)

# ![the Linux mascot](Subject/tux.avif) ![mascot](Subject/tux.avif) ![mascot](Subject/tux.avif) ![mascot](Subject/tux.avif) ![mascot](Subject/tux.avif) ![mascot](Subject/tux.avif) ![mascot](Subject/tux.avif)

## Overview

Minishell is a simple shell implementation written in the C programming language. It aims to replicate some of the basic functionalities of popular shells like Bash.

## Key Features

The key features of this minishell include:

- Displaying a prompt when waiting for a new command.
- Implementing a working history feature.
- Searching and launching the right executable based on the PATH variable or using a relative or absolute path.
- Handling various redirections, including `<`, `>`, `<<`, and `>>`.
- Supporting pipes (`|`) to connect the output of one command to the input of the next.
- Handling environment variables (e.g., `$VAR`) and expanding them to their values.
- Handling special characters like quotes (`'` and `"`) to prevent interpretation of meta-characters.
- Implementing built-in commands like `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.

## Project Structure

- **Executor**: Contains code for command execution.

  - `Built_cmd.c`: Handles built-in commands.
  - `Err.c`: Error handling.
  - `echo.c`: Implementation of the 'echo' command.
  - `exuc.c`: Execution functions.
  - `pipe.c`: Handling pipes in command execution.
  - `rd_from_wr_in.c`: Reading from write end of a pipe.
  - `sig.c`: Signal handling.
  - `stat_loc.c`: Handling the status of executed processes.
  - `terminate.c`: Termination functions.

- **Include**: Stores header files for declarations.

  - `Exec.h`: Declarations for execution-related functions.
  - `Parser.h`: Declarations for parsing functions.
  - `Subsystem.h`: Declarations for subsystem-related functions.
  - `minishell.h`: Main header for the minishell program.

- **Makefile**: Makefile for building the project.

- **Parser**: Handles parsing of input commands.

  - **Lists**:
    - `list_env.c`: List-related functions for environment variables.
    - `list_tokens.c`: List-related functions for tokens.
  - **Tockenization_files**:
    - `expand.c`: Token expansion functions.
    - `expand_heredoc.c`: Heredoc token expansion.
    - `repair_line.c`: Line repair functions.
    - `tokenize_line.c`: Tokenization functions.
  - `ast.c`: Abstract Syntax Tree (AST) generation.
  - `call_shell.c`: Function for calling the shell.
  - **check_syntax_errors**:
    - `check.c`: Syntax checking functions.
    - `check_utils.c`: Utility functions for syntax checking.
  - **herdoc**:
    - `ft_herdoc.c`: Functions for handling heredoc.
    - `heredoc_utils.c`: Utility functions for heredoc handling.
  - `pop_spcs.c`: Function for popping spaces in parsed tokens.

- **Subsystems**: Contains code for various subsystems or components.

  - `b_expr.c`: Binary expression subsystem.
  - `env.c`: Environment variable subsystem.
  - `env1.c`: More environment variable functions.
  - `exp.c`: Expression evaluation subsystem.
  - `unset.c`: Functions for unsetting variables.

- **libft**: Likely a custom library for general-purpose functions.
  - (List of [library source](/libft) files and headers.)
  - [libft source on github](https://github.com/sdk-meb/libft.42)
- **main**: Main entry point of the minishell program.
