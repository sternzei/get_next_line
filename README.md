<h1 align="center">
get_next_line
</h1>

<h3 align="center">
  <a href="#about">About</a>
  <span> · </span>
  <a href="#usage">Usage</a>
  <span> · </span>
  <a href="#testing">Testing</a>
  <span> · </span>
  <a href="#bonus">Bonus</a>
</h3>

---

## About 📖

The **`get_next_line`** project is a core exercise in C programming, focused on efficient line-by-line reading from files. This function is a powerful tool for handling text files, configuration data, or any scenario where processing input line by line is beneficial.

**Key Concepts You'll Learn:**

* **File Descriptors:**  Understanding how files are represented in an operating system.
* **Buffering:** Efficiently reading chunks of data from files to optimize performance.
* **Memory Management:**  Dynamically allocating and freeing memory as you process lines.
* **Error Handling:**  Ensuring your code gracefully handles unexpected situations (e.g., file errors).
* **Static Variables:**  Using static variables to maintain state between function calls.

## Usage 🛠️

### 1. Including the Header

Add this to the top of your C source file:

```c
#include "get_next_line.h"
,,,

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```
