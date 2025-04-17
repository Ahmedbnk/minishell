Sure! Here's a **well-organized documentation** tailored for the **mandatory part of the Minishell project**, with a checklist of **what you must handle**, **key behaviors**, and the **best advice** to succeed — all explained like a fellow 1337 student who’s got your back 💪🔥

---

# 📘 Minishell — Mandatory Part Documentation  

> 🎯 **Goal:** Recreate a simplified bash-like shell that can execute basic commands, with piping, redirection, environment handling, and signals.  

---

## 📋 1. ✅ Mandatory Features You MUST Implement

### 🧠 1.1. **Prompt**
- Show a prompt (e.g., `$ `) and **wait** for user input.
- Must redisplay after every command finishes.

> ✅ **Advice:** Use `readline()` if allowed. It handles line editing, history, and arrow keys.

---

### 🧠 1.2. **Command Execution**
- Must execute commands like `ls`, `echo`, `cat`, etc.
- Handle **absolute paths** (`/bin/ls`) and **search PATH** (`ls`).

> ✅ **Advice:**  
- Use `fork()` and `execve()`.  
- If a command is not found, print: `command not found`.

---

### 🧠 1.3. **PATH Lookup**
- If user types `ls`, search `$PATH` to find the full path like `/bin/ls`.

> ✅ **Advice:**  
Split `PATH` by `:` and try to join it with the command.

---

### 🧠 1.4. **Built-in Commands**
You must **implement** the following **yourself** (without calling `/bin/command`):

| Command      | Description                    |
|--------------|--------------------------------|
| `echo`       | Print arguments                |
| `cd`         | Change directory               |
| `pwd`        | Print current directory        |
| `export`     | Set an environment variable    |
| `unset`      | Remove environment variable    |
| `env`        | Print environment variables    |
| `exit`       | Exit the shell                 |

> ✅ **Advice:**  
- Don’t `fork()` for `cd`, `exit`, or `export` (they must affect the parent process).
- Store environment as your own data structure (linked list or array of strings).

---

### 🧠 1.5. **Redirections**
| Type          | Example                      | Meaning                                |
|---------------|------------------------------|----------------------------------------|
| `>`           | `ls > out.txt`               | Redirect stdout (overwrite)            |
| `>>`          | `ls >> out.txt`              | Redirect stdout (append)               |
| `<`           | `cat < input.txt`            | Redirect stdin                         |
| `<<` (heredoc)| `cat << EOF`                 | Input until delimiter is found         |

> ✅ **Advice:**  
Use `open()` + `dup2()` to redirect file descriptors.

---

### 🧠 1.6. **Pipes**
- Support pipelines: `ls | grep minishell | wc -l`

> ✅ **Advice:**  
Use `pipe()`, `fork()`, `dup2()` carefully and close file descriptors in the correct order.

---

### 🧠 1.7. **Signals**
| Signal    | Behavior in Minishell               |
|-----------|-------------------------------------|
| `Ctrl-C`  | Cancel current command but not exit |
| `Ctrl-\`  | Should not quit the shell           |

> ✅ **Advice:**  
Use `signal()` or `sigaction()` to catch `SIGINT`, `SIGQUIT`.

---

### 🧠 1.8. **Exit Status**
- Each command should return an exit code (`$?`).
- The shell must keep track of the last exit status.

> ✅ **Advice:**  
Use `waitpid()` and `WEXITSTATUS(status)`.

---

## 🧪 2. ❌ Things You Must NOT Do

- ❌ Use `system()`, `popen()`, or any wrapper around system commands.
- ❌ Use `execvp()`, `execlp()`, etc. — only `execve()` allowed.
- ❌ Memory leaks — use `valgrind` to check!
- ❌ Crashing on invalid input or missing files

---

## 💡 3. Best Advice from Experience

### 🔁 3.1. Build It in Layers (Step-by-Step)
1. Show prompt and read input ✅  
2. Execute basic commands ✅  
3. Add builtins ✅  
4. Add redirection ✅  
5. Add pipes ✅  
6. Add signals ✅  
7. Add environment handling ✅  

> 🧠 **Each layer should be fully working before adding the next.**

---

### 🧹 3.2. Memory Management
- Use `valgrind` every day.
- Free everything, especially after each command is executed.

---

### 🧪 3.3. Test like a beast
Test these cases:
- `ls | grep minishell > out`
- `cat < infile | wc > out`
- `echo hello > file >> file2`
- `cat << EOF`

Also test edge cases:
- `>` without file
- `|` at the end
- Wrong command
- Ctrl-C during heredoc

---

### 🛠️ 3.4. Structure Your Code
Split it into:
- Lexer
- Parser
- Executor
- Builtins
- Utils
- Env handling
- Signal handler

> 📁 Use folders and makefiles to keep it clean.

---

### 🧩 3.5. Understand Before You Code
Always understand:
- What shell behavior is expected?
- How would bash handle this?
- Where do redirections go?

---

## ✅ Summary Checklist

| Task                        | Done? ✅ |
|-----------------------------|---------|
| Prompt                     |         |
| Readline / Manual Input    |         |
| Execute External Commands  |         |
| Built-in Commands          |         |
| Redirections `< > >> <<`   |         |
| Pipes                      |         |
| Environment Handling       |         |
| Signal Handling            |         |
| Exit Status                |         |
| No Memory Leaks            |         |

---

If you'd like, I can also generate this into a `.md` file or help you create a clean `README.md` for your project!

Would you like to start working on the **parsing plan** now? (like tokens, quote handling, etc.)
we will add something later
2222222222
