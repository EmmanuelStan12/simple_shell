# Simple Shell

Simple Shell is a project that seeks to simulate the functionality of a real Bourne Again Shell

## Compilation

In order to compile the program run

```bash
gcc *.c -o shell
```

## Usage

```
#list files in current directory
[codedev]~$ ls
README.md   append_path.c  join_strings.c  shell.c  temp_shell    tokenize.c
_execute.c  env.c          shell           shell.h  token_size.c

# run the command with the full directory of the command
[codedev]~$ /bin/ls
README.md   append_path.c  join_strings.c  shell.c  temp_shell    tokenize.c
_execute.c  env.c          shell           shell.h  token_size.c

# echo command
[codedev]~$ echo "Hello World"
"Hello World"
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
