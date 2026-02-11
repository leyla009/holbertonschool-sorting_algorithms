 <img height="50" align="right" src="https://raw.githubusercontent.com/fchavonet/fchavonet/refs/heads/main/assets/images/logo-holberton_school.webp" alt="Holberton School logo">

# Sorting Algorithms & Big O Analysis

This project is an in-depth exploration of data sorting logic and computational complexity. It involves implementing several sorting algorithms in **C**, evaluating their time and space complexity, and determining the most efficient approach for various data sets.



## Tech Stack

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-black?style=for-the-badge&logo=algorithms&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-blue?style=for-the-badge)
![Big O](https://img.shields.io/badge/Big_O-red?style=for-the-badge)
![Vim](https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white)

---

## Implemented Algorithms

Each algorithm is accompanied by a **Big O notation** file (`-O`) documenting its Best, Average, and Worst-case time complexities.

### Elementary Sorts
| Algorithm | File | Description |
| :--- | :--- | :--- |
| **Bubble Sort** | `0-bubble_sort.c` | Classical swap-based sorting. |
| **Insertion Sort** | `1-insertion_sort_list.c` | Efficient for small or nearly sorted linked lists. |
| **Selection Sort** | `2-selection_sort.c` | Minimizes memory writes by finding the minimum. |

### Efficient Sorts ($O(n \log n)$ and beyond)
| Algorithm | File | Description |
| :--- | :--- | :--- |
| **Quick Sort** | `3-quick_sort.c` | Divide and conquer using Lomuto partition. |
| **Shell Sort** | `100-shell_sort.c` | Uses Knuth’s sequence to optimize insertion sort. |
| **Merge Sort** | `103-merge_sort.c` | Stable, top-down divide and conquer approach. |
| **Heap Sort** | `104-heap_sort.c` | Utilizes a binary max-heap to sort in-place. |

### Advanced & Specialized Sorts
| Algorithm | File | Description |
| :--- | :--- | :--- |
| **Cocktail Shaker** | `101-cocktail_sort_list.c` | Bi-directional variation of Bubble Sort. |
| **Counting Sort** | `102-counting_sort.c` | Non-comparative integer sorting. |
| **Radix Sort** | `105-radix_sort.c` | Sorts data by individual digits (LSD). |
| **Bitonic Sort** | `106-bitonic_sort.c` | Parallel-focused sorting for power-of-2 arrays. |
| **Hoare Partition** | `107-quick_sort_hoare.c` | Optimized Quick Sort using Hoare's scheme. |
| **Sort Deck** | `1000-sort_deck.c` | Sorting a deck of cards using specialised `structs`. |

---

## Complexity Analysis (Big O)



I have documented the performance of these algorithms across four critical metrics:
* **Best Case:** The algorithm's performance on already sorted data.
* **Average Case:** Performance on randomised data sets.
* **Worst Case:** Performance on inversely sorted data.
* **Space Complexity:** The amount of auxiliary memory required by the algorithm.

## General Requirements
* **Compilation:** All files are compiled on Ubuntu 20.04 LTS using `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`.
* **Style:** Strict adherence to the **Betty Style Guide**.
* **Data Structures:** Definitions for `listint_t` and `deck_node_t` are included in `sort.h` and `deck.h`.

## How to Run
To test the Quick Sort implementation:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 3-main.c 3-quick_sort.c print_array.c -o quick
./quick
```
## Author
**LEYLA KHASPOLADOVA**
GitHub: [@leyla009](https://github.com/leyla009)
