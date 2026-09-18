# Practice 7: Threads

Session 7. Official instructions: [session7.md](https://github.com/Sharif-OS-Lab/session-7/blob/main/session7.md)

The session was an introduction to POSIX threads: creating one with `pthread_create`, checking that all threads of a process report the same PID, seeing that global variables are shared between threads while a `fork`ed child gets its own copy, and passing several values into a thread through a struct.

The programs are in this folder, one per task, in the order the report uses them: `thread.c` (first thread), `thread2.c` (PIDs), `thread3.c` (a shared global), `thread4.c` (sum from 2 to n), `thread5.c` (five threads), `thread6.c` (two threads incrementing a shared `global_var`), `thread7.c` (threads next to `fork`) and `thread8.c` (passing a struct).

---

Student Name of member 1: `Negar Babashah`

Student Name of member 2: `Iman Mohammadi`

- [x] Read Session Contents.

## Section 7.4

### Section 7.4.1
- [x] Creating a thread using pthread
    - [x] <img width="530" alt="{9F1D75B8-7FBF-4A91-9963-E5E887FFD312}" src="images/01.png" />

   
- [x]  Checking the process ids
    - [x] <img width="949" alt="{76432CCB-4E43-4ABD-BFE2-7677D2353AF1}" src="images/02.png" />

    - [ ] This screenshot, the program's output, never finished uploading in the original
      report, so it is lost. The code it ran is `thread2.c` in this folder, and the
      screenshot above shows that source.

    - [x] همان طور که مشاهده می‌شود pidها یکسان هستند. دلیلش هم این است که دو ترد ایجاد شده هر دو متعلق به یک پراسس هستند.

- [x]  Shared variables
    - [x] <img width="959" alt="{145C6661-E64E-402E-AAB4-9F2FCA31B2E3}" src="images/03.png" />

    - [x] <img width="958" alt="{BEFD08F5-3771-4FB0-BD2F-F2206FB069CE}" src="images/04.png" />

    - [x]  همان طور که دیده می‌شود مقدارهای oslab در هر دو ترد یکسان است. بنابراین متغیرهای گلوبال در همه‌ی تردهای یک پردازه یکسان هستند و کپی جداگانه‌ای گرفته نمی‌شود.

- [x] Sum of 2 to n
    1. [x] <img width="944" alt="{F4E34EAC-3B0D-46B2-B6AF-347657CB4ED6}" src="images/05.png" />


    1. [x] <img width="959" alt="{BB1CEDD4-0E1F-40C9-9511-A33ABD6BCC9B}" src="images/06.png" />

### Section 7.4.2
- [x] Multiple threads    
    - [x] <img width="960" alt="{20D4290E-B3C1-43D6-BDE8-DC8F37266908}" src="images/07.png" />

    - [x] <img width="928" alt="{15DF2ED2-5159-46B0-B947-A69A353E8405}" src="images/08.png" />


### Section 7.4.3
- [x] Compiling the code
    - [ ] This screenshot never finished uploading in the original report, so it is lost.


- [x] global_param
    - [x] <img width="948" alt="{4B5634D2-6BA2-46E9-B06C-14193DEF06FE}" src="images/09.png" />

    - [x] <img width="924" alt="{18D05813-9833-4FEA-AEB1-199E9144325D}" src="images/10.png" />

- مشاهده می‌شود که مقدار متغیر گلوبال دو واحد تغییر کرده است. یعنی هر دو ترد آن را افزایش داده‌اند. بنابراین یعنی تردها به متغیرهای گلوبال یکسانی دسترسی دارند.

- [x] Forking
    - [x] <img width="954" alt="{0C1E5376-096A-4FA1-ACD0-5ADC99F08EBF}" src="images/11.png" />

    <img width="917" alt="{8C438690-5F77-42F2-AA7F-9342FA852AA9}" src="images/12.png" />

    - [x] <img width="956" alt="{F9FB3B54-E03C-427A-8829-B98F7B27463D}" src="images/13.png" />

- همان طور که مشاهده می‌شود مقادیر متغیرهای لوکال و گلوبال در پردازه‌ی پدر و فرزند متفاوت هستند. یعنی فرزند کپی خودش را از این متغیرها نگه می‌دارد و با چیزی که پدر نگه می‌دارد یکسان نیست. 

### Section 7.4.4
- [x] Passing multiple variables
    - [x] <img width="939" alt="{890BB8F3-497B-4272-988E-D17B9DC106F0}" src="images/14.png" />

    - [x] <img width="952" alt="{F2306823-2843-4C2F-AD10-CD132C02E6FE}" src="images/15.png" />
