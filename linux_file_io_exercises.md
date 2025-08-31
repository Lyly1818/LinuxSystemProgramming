# Linux File I/O System Calls - Practice Exercises

## Prerequisites
- Basic knowledge of C programming
- Linux environment with GCC compiler
- Understanding of file descriptors and system calls

## Exercise 1: Basic File Creation and Writing

**Objective**: Learn to use `open()`, `write()`, and `close()` system calls.

**Task**: Create a program that:
1. Opens a new file called "hello.txt" for writing
2. Writes "Hello, Linux File I/O!" to the file
3. Properly closes the file

**Key System Calls**: `open()`, `write()`, `close()`

**Sample Solution Structure**:
```c
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd;
    const char* message = "Hello, Linux File I/O!";
    
    // Open file for writing (create if doesn't exist)
    fd = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    // Write to file
    write(fd, message, strlen(message));
    
    // Close file
    close(fd);
    
    return 0;
}
```

**Learning Points**:
- File descriptor concept
- Open flags (O_WRONLY, O_CREAT, O_TRUNC)
- File permissions (0644)

---

## Exercise 2: Reading from Files

**Objective**: Learn to read data using `read()` system call.

**Task**: Create a program that:
1. Opens an existing file for reading
2. Reads the content into a buffer
3. Displays the content to stdout
4. Handles the case where file doesn't exist

**Key System Calls**: `open()`, `read()`, `close()`

**Requirements**:
- Use a buffer of appropriate size
- Handle partial reads properly
- Check for errors

**Challenge**: Read the file created in Exercise 1 and display its contents.

---

## Exercise 3: File Information with stat()

**Objective**: Learn to retrieve file metadata using `stat()` system call.

**Task**: Create a program that:
1. Takes a filename as command-line argument
2. Uses `stat()` to get file information
3. Displays:
   - File size
   - File permissions
   - Last modification time
   - File type (regular file, directory, etc.)

**Key System Calls**: `stat()`, `fstat()`

**Sample Output**:
```
File: hello.txt
Size: 23 bytes
Permissions: rw-r--r--
Last modified: 2024-01-15 10:30:45
Type: Regular file
```

---

## Exercise 4: Directory Operations

**Objective**: Learn directory manipulation with `mkdir()`, `rmdir()`, and `opendir()`.

**Task**: Create a program that:
1. Creates a new directory called "test_dir"
2. Creates a file inside that directory
3. Lists all files in the directory
4. Removes the file and directory

**Key System Calls**: `mkdir()`, `opendir()`, `readdir()`, `closedir()`, `rmdir()`, `unlink()`

---

## Exercise 5: File Copying with System Calls

**Objective**: Implement file copying using low-level I/O operations.

**Task**: Create a program that:
1. Takes source and destination filenames as arguments
2. Copies the source file to destination using `read()` and `write()`
3. Preserves file permissions
4. Handles large files efficiently with buffered I/O

**Requirements**:
- Use appropriate buffer size (e.g., 4096 bytes)
- Handle partial reads/writes
- Copy file permissions using `chmod()`
- Provide progress indication for large files

---

## Exercise 6: File Locking

**Objective**: Learn file locking mechanisms with `fcntl()`.

**Task**: Create two programs:
1. **Writer program**: Opens a file, acquires an exclusive lock, writes data slowly
2. **Reader program**: Attempts to read the same file with shared lock

**Key System Calls**: `fcntl()` with `F_SETLK`, `F_SETLKW`

**Learning Points**:
- Exclusive vs. shared locks
- Blocking vs. non-blocking locks
- Lock regions

---

## Exercise 7: File Positioning with lseek()

**Objective**: Learn random file access using `lseek()`.

**Task**: Create a program that:
1. Creates a file with numbered records (e.g., "Record 001", "Record 002", etc.)
2. Implements functions to:
   - Jump to a specific record
   - Read a record at given position
   - Update a record at given position
3. Demonstrates seeking from beginning, end, and current position

**Key System Calls**: `lseek()`, `SEEK_SET`, `SEEK_CUR`, `SEEK_END`

---

## Exercise 8: Memory-Mapped Files

**Objective**: Learn memory mapping with `mmap()` and `munmap()`.

**Task**: Create a program that:
1. Opens a text file
2. Maps it into memory using `mmap()`
3. Processes the file content directly from memory
4. Unmaps the file properly

**Key System Calls**: `mmap()`, `munmap()`

**Use Case**: Count word frequency in a large text file using memory mapping.

---

## Exercise 9: Pipe Communication

**Objective**: Learn inter-process communication using `pipe()`.

**Task**: Create a program that:
1. Creates a pipe using `pipe()`
2. Forks a child process
3. Parent writes data to pipe
4. Child reads data from pipe
5. Demonstrates bidirectional communication with two pipes

**Key System Calls**: `pipe()`, `fork()`, `dup2()`

---

## Exercise 10: Advanced File Operations

**Objective**: Combine multiple concepts in a practical application.

**Task**: Create a simple log file manager that:
1. Maintains multiple log files with rotation
2. Implements file locking for concurrent access
3. Provides search functionality
4. Compresses old log files
5. Monitors directory for changes using `inotify`

**Key System Calls**: Multiple from previous exercises plus `inotify_init()`, `inotify_add_watch()`

---

## Compilation and Testing Guidelines

### Compilation:
```bash
gcc -o program program.c
```

### Testing Tips:
1. Use `strace` to monitor system calls:
   ```bash
   strace ./program
   ```

2. Check file permissions:
   ```bash
   ls -l filename
   ```

3. Monitor file changes:
   ```bash
   watch -n 1 'ls -la'
   ```

### Error Handling Best Practices:
- Always check return values of system calls
- Use `perror()` or `strerror()` for error messages
- Clean up resources (close file descriptors)
- Handle EINTR (interrupted system calls)

### Common Pitfalls to Avoid:
- Forgetting to close file descriptors
- Not handling partial reads/writes
- Ignoring return values
- Buffer overflows
- Race conditions in concurrent access

## Additional Resources:
- `man 2 open` - Manual pages for system calls
- `/usr/include/fcntl.h` - Header file definitions
- Linux System Programming book
- Advanced Programming in the UNIX Environment

## Assessment Rubric:
- **Functionality**: Does the program work as specified?
- **Error Handling**: Are edge cases and errors handled properly?
- **Code Quality**: Is the code readable and well-structured?
- **System Call Usage**: Are system calls used correctly and efficiently?
- **Resource Management**: Are resources properly allocated and freed?
