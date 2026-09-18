# CE408-OS-Lab

Solutions to Prof. Beigi's CE408: Operating Systems Lab (Sharif University of Technology - Fall 2024) Assignments

## About

This is my archive of the work Negar Babashah and I did for the Operating Systems Lab. The course ran on GitHub Classroom: every session had a public instruction document under the [Sharif-OS-Lab](https://github.com/Sharif-OS-Lab) organization plus a report template that each team filled in as an issue in its own private repository. Each `Practices/PracticeN/README.md` here is our filled-in report for session N, which is why the checkbox lists look the way they do. The checklists come from the official template; the answers are ours.

The screenshots started out as attachments on those private issues, so they stopped loading as soon as the reports were copied into this public repository. I have pulled them back out and committed them, and each practice now keeps its own images under `PracticeN/images/`.

Reports are a mix of Persian and English, since the templates allowed either.

## Practices

| Practice | Topic | Official instructions | Code |
| --- | --- | --- | --- |
| [1](Practices/Practice1) | Installing Linux, basic shell commands, rebuilding the kernel | [session1](https://github.com/Sharif-OS-Lab/session-1-2/blob/main/session1.md) | report only |
| [2](Practices/Practice2) | System calls, and adding one to the kernel | [session2](https://github.com/Sharif-OS-Lab/session-1-2/blob/main/session2.md) | 4 C files |
| [3](Practices/Practice3) | Reading kernel and process state from `/proc` | [session3](https://github.com/Sharif-OS-Lab/session-3-4/blob/master/session3.md) | 4 C files, 1 shell script |
| [4](Practices/Practice4) | Processes: `fork`, `wait` and the `exec` family | [session4](https://github.com/Sharif-OS-Lab/session-3-4/blob/master/session4.md) | 6 C files |
| [5](Practices/Practice5) | Inter-process communication: pipes and signals | [session5](https://github.com/Sharif-OS-Lab/session-5-6/blob/main/session5.md) | report only |
| [6](Practices/Practice6) | Memory management, segments, heap and stack | [session6](https://github.com/Sharif-OS-Lab/session-5-6/blob/main/session6.md) | 4 C files |
| [7](Practices/Practice7) | Threads with `pthread` | [session7](https://github.com/Sharif-OS-Lab/session-7/blob/main/session7.md) | 8 C files |
| [8](Practices/Practice8) | Kernel modules and system call hooking | [session8](https://github.com/Sharif-OS-Lab/session-8/blob/main/session8.md) | 2 modules |
| [9](Practices/Practice9) | Interrupts | [session9](https://github.com/Sharif-OS-Lab/session-9/blob/main/session9.md) | 3 C files |
| [10](Practices/Practice10) | Device drivers and a netfilter packet sniffer | [session10](https://github.com/Sharif-OS-Lab/session-10/blob/main/session-10.md) | listed in the report |

Practices 5 and 10 have no `.c` files of their own: for session 5 we answered with screenshots of the programs, and for session 10 both modules are written out in full inside the report.

## Instructions

`Instructions/Instructions.pdf` is the older printed lab manual (34 pages, Persian, 2021). It predates the GitHub version of the course, so where the two disagree, the session documents linked above are what we actually followed.

## Building and running

Most of the C programs are ordinary user-space Linux code, so `gcc file.c` is enough (`-pthread` for practice 7). The kernel modules in practices 8 and 9 have their own `Makefile` and need the headers for your running kernel. Build output is not committed.

Practices 8, 9 and 10 write to the live system call table, take over an IRQ line, or sit in the packet path. Load those only in a virtual machine you do not mind breaking.

## Maintainers

- [Iman Mohammadi](https://github.com/Imanm02)
- [Negar Babashah](https://github.com/Negarbsh)
