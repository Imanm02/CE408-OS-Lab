Student Name of member 1: `Iman Mohammadi`

Student Name of member 2: `Negar Babashah`

  - [x] Read Session Contents.
    1. [x] ![image](https://github.com/user-attachments/assets/4a52e831-cdd0-41b4-ae70-6549cb399fa6)
    2. [x] ![image](https://github.com/user-attachments/assets/d205f640-60c9-428b-929b-754193db621e)
    3. [x] ![image](https://github.com/user-attachments/assets/f50d14f5-cf3a-4370-bb17-bdf84f07cfb4)

### Section 5.3.1

- [x] Write the `Hello World!` program
    4. ![image](https://github.com/user-attachments/assets/bd0d12d9-907b-45da-b501-83f4669759c5)
    5. ![image](https://github.com/user-attachments/assets/27278a1a-5901-4fae-9aba-fa0c60ecc3e7)
    
- [x] Write the `ls` to `wc` program
    6. ![image](https://github.com/user-attachments/assets/83305b26-b44b-4ad9-9a93-394c82c2736c)
    7. ![image](https://github.com/user-attachments/assets/6de265f9-67aa-4e39-910e-27e7c9eeb3f5)

- [x] Investigate how to have a bi-direction pipe
    8. `Two separate pipes must be created to achieve bi-directional communication between two processes. Each pipe allows one-way communication. One pipe can be used for the parent to send data to the child, while the other pipe is used for the child to send data back to the parent. After creating the pipes, proper closing of unused read/write ends in both processes is crucial to avoid deadlocks.`
    
### Section 5.3.2

- [x] Describe the usecase of different signals:
    9. `SIGINT: This signal is sent when the user presses Ctrl + C. It is used to interrupt and terminate a running process.]`
    10. `[SIGHUP: This signal is sent when the terminal or controlling process is disconnected. It is often used to restart or reload configuration files in daemons.`
    11. `SIGSTOP: This signal stops (pauses) a process. It is sent by the system or via commands like kill -STOP. This signal cannot be caught or ignored.`
    12. `SIGCONT: This signal resumes the execution of a stopped process. It is used in conjunction with SIGSTOP to control process execution.`
    13. `SIGKILL: This signal forcibly terminates a process. It cannot be caught or ignored, ensuring the process is stopped immediately.`

- [x] Describe SIGALRM
    14. `The SIGALRM signal is sent to a process after the timer set by the alarm() system call expires. It is often used for timeouts or periodic tasks.`

- [x] Investigate the given code
    15. `This code sets an alarm to send SIGALRM after 5 seconds. The program enters an infinite loop and will terminate when the signal is received. The signal handler is not implemented, so the default action is to terminate the process.`
    16.
    ![image](https://github.com/user-attachments/assets/89a58a4e-d685-44f9-ac9e-90e21d93e917)

- [x] Modify the given program by handling SIGALRM
    17. ![image](https://github.com/user-attachments/assets/bc982189-2485-4627-b77a-862979bea22f)
    18. ![image](https://github.com/user-attachments/assets/855b6d08-1382-4d93-8777-1075bba54890)

- [x] Write a program that handles Ctrl + C
    19. ![image](https://github.com/user-attachments/assets/01957527-3f14-4813-8f21-6fe76f1d00be)
    20. ![image](https://github.com/user-attachments/assets/43c074b2-73a4-4424-8b3b-58e76ee0a7d9)