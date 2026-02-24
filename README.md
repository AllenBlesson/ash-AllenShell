# ash - Allen's Shell

A simple Unix shell implementation in C that executes system commands and saves user preferences.

## Features

- Execute any system command (ls, pwd, echo, etc.)
- Set a custom codename that persists between sessions
- Codename is automatically loaded when you restart the shell
- Clean command-line interface with ash> prompt

## Requirements

- GCC compiler
- Linux or WSL environment

## Build

Compile the source code:
```bash
gcc main.c -o ash
```

This creates an executable named `ash`.

## Usage

Start the shell:
```bash
./ash
```

You'll see a prompt:
```bash
ash>
```

### Running Commands

Type any system command:
```bash
ash> ls
ash> pwd
ash> echo hello world
ash> whoami
```

### Setting Your Codename

Set a custom codename that will be remembered:
```bash
ash> codename Allen
Codename set to: Allen
```

Exit and restart the shell — it will greet you:
```bash
Welcome back, Allen!
ash>
```

### Exit

To quit the shell:
```bash
ash> exit
```

## How It Works

- Commands are parsed and executed using `fork()` and `execvp()`
- Your codename is stored in `~/.ashrc` for persistence
- Invalid commands print "ash: command not found"