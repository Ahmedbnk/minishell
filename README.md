# minishell

A minimal Unix shell written in C - your own tiny bash powered by curiosity, code, and caffeine!

## ✨ Features

- Interactive shell prompt
- Built-in commands: `cd`, `echo`, `pwd`, `export`, `unset`, and more
- Command execution with arguments & environment
- Pipes and redirections support (`|`, `>`, `<`, `>>`, heredoc)
- Environment variable expansion (`$VAR`)
- Signal handling (Ctrl+C, Ctrl+\)
- Robust error handling and memory management
- Custom implementation, no external shell usage
- Inspired by the 42 School [minishell project](https://projects.intra.42.fr/projects/minishell)

## 🚀 Getting Started

### Prerequisites

- GCC or Clang (C compiler)
- GNU Make
- Linux or macOS environment

### Build

```sh
git clone https://github.com/Ahmedbnk/minishell.git
cd minishell
make
```

### Run

```sh
./minishell
```

## 💡 Usage

- Type commands as you would in bash or zsh!
- Use pipes and redirections to combine commands
- Supports environment variable expansion:  
  `echo $HOME`
- Builtin commands can be run without spawning extra processes

## 🛠️ Main Source Structure

- `main.c` - Entry point and core loop
- `src/` - Shell logic and command execution
- `include/` - Header files
- `Makefile` - Build instructions

## 📦 Example

```sh
minishell$ echo Hello, World!
Hello, World!

minishell$ export NAME=Coder
minishell$ echo Hi $NAME!
Hi Coder!

minishell$ ls -l | grep minishell > output.txt
```

## 🙏 Credits

- Made by [Ahmedbnk](https://github.com/Ahmedbnk) and [Nabil-Kasimi](https://github.com/Nabil-Kasimi)
- Built as part of the 42 Network curriculum

## 📝 License

This project is for educational purposes. See the repo for license info if added.

---

*Enjoy hacking your shell! 🚀*
