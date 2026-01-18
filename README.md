# Custom Data Structures Implementation in C

## Project Overview

This repository contains a collection of core data structures implemented from scratch in **Standard C**.

The primary goal of this project was to bypass high-level abstractions and manually manage **dynamic memory**, **pointers**, and **node relationships**. It serves as a practical demonstration of low-level algorithms and memory efficiency, key concepts for systems programming and embedded environments.

## Technical Highlights

* **Manual Memory Management:** Extensive use of `malloc` and `free` to allocate and deallocate nodes dynamically, ensuring no memory leaks.
* **Double Pointers:** Implementation of functions using double indirection (e.g., `Node **root`) to modify list/tree heads directly within functions.
* **Standard C Portability:** Written in pure C (C99/C11 standards), removing dependency on Windows-specific libraries (like `<conio.h>`), making the code compilable on **Linux**, macOS, and Windows.

## Project Structure

### 1. Binary Search Tree (BST)

**File:** `src/binary_trees/binary_search_tree.c`

A complete implementation of a BST capable of organizing integer data.

* **Recursive Logic:** Uses recursion for insertion and searching to optimize code readability.
* **Traversals:** Implements In-order, Pre-order, and Post-order traversal algorithms.
* **Search Complexity:** Optimized for `O(log n)` search operations in balanced scenarios.

### 2. Priority Printer Queue

**File:** `src/queues/printer_queue.c`

A simulation of a printer job manager using a **Singly Linked List**.

* **Business Logic:** Unlike a standard FIFO queue, this implementation includes a custom **priority mechanism**.
* **Pointer Manipulation:** Features a "jump queue" function that physically moves a node from any position to the second spot (immediately after the active print job) by rearranging pointer links, rather than swapping data values.

## How to Compile & Run

Prerequisites: `gcc` compiler.

**To run the Binary Search Tree:**

```bash
gcc src/binary_trees/binary_search_tree.c -o bst_test
./bst_test

**To run the Printer Queue**

```bash
gcc src/queues/printer_queue.c -o queue_test
./queue_test

## Author

### José Ángel García Plascencia

* **Role:** Information Technologies Engineering Student @ UPSIN.
* **Contact:** jose.angel.git@gmail.com / https://www.linkedin.com/in/jose-angel-garcia-20aa01386/.
