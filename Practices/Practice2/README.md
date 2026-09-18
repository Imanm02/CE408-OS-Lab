# Practice 2: System calls

Session 2. Official instructions: [session2.md](https://github.com/Sharif-OS-Lab/session-1-2/blob/main/session2.md)

This session was about system calls: locating the syscall number table in the kernel headers, invoking a call directly by its number with `syscall()`, doing the same through the ordinary libc wrapper, and finally adding a new system call to the kernel and rebuilding it.

The four programs for section 2.3.4 are in this folder, one per task: `access_test.c` (`access`), `filework.c` (`open`, `write`, `close`), `memory.c` (`sysinfo`) and `cswitch.c` (`getrusage`).

`filework.c` is as we submitted it apart from the file-mode argument `0644`, added later because `open` needs one when `O_CREAT` is set; the screenshot in 2.3.4 still shows the original two-argument call.

---

Student Name of member 1: `Negar Babashah`

Student Name of member 2: `Iman Mohammadi`

- [x] Read Session Contents.

### Section 2.3.1

- [x] ![image](images/01.png)
- [x] ![image](images/02.png)

### Section 2.3.2
- [x] ![Screenshot (2443)](images/03.png)
- [x] ![Screenshot (2445)](images/04.png)

<div dir="rtl">

- [x] همان طور که در برنامه آمده است، یک دایرکتوری به نام testdir با دسترسی‌های کامل ساخته می‌شود. از آنجا که این عمل موفقیت‌آمیز بوده است، خروجی سیسکال صفر است.
- [x] ثابت <span dir="ltr">`__NR_mkdir`</span> در واقع شماره‌ی syscall مربوط به mkdir است.
- [x] به کمک این دستور می‌توان یک syscall موجود در سیستم را با داشتن شماره‌ی ثابت آن و ورودی دادن سایر ورودی‌های مربوط به این فراخوانی، صدا کرد. مقدار برگشتی آن همان چیزی است که خود آن فراخوانی برمی‌گرداند؛ برای <span dir="ltr">`mkdir`</span> در صورت موفقیت ۰ و در صورت بروز خطا <span dir="ltr">`-1`</span> است. اگر خطا رخ دهد <span dir="ltr">`errno`</span> هم ست می‌شود.

</div>

### Section 2.3.3
- [x] ![image](images/05.png)
- [x] ![image](images/06.png)

### Section 2.3.4
- [x] ![image](images/07.png)
- [x] ![image](images/08.png)
- [x] ![image](images/09.png)
- [x] ![image](images/10.png)
- [x] ![image](images/11.png)
- [x] ![image](images/12.png)
- [x] ![image](images/13.png)
- [x] ![image](images/14.png)

### Section 2.3.5

- [x] Do 13 subtasks from 1 to 13 and add screenshots of each:

    1. [x] ![image](images/15.png)
    
    2. [x] ![image](images/16.png)
    
    3. [x] ![image](images/17.png)
    
    4. [x] ![image](images/18.png)
    
    5. [x] ![image](images/19.png)

    - [x] ![image](images/20.png)

    - [x] ![image](images/21.png)
    
    7. [x] ![image](images/22.png)

    - [x] ![image](images/23.png)

    - [x] ![image](images/24.png)

    9. [x] ![image](images/25.png)

    10. [x] ![image](images/26.png)

    11. [x] ![image](images/27.png)

    12. [x] `بخش متناظر با core-y در Makefile من در پوشه‌ی کد منبع وجود نداشت که علت تفاوت نسخه‌ی کرنل (۶) با نسخه‌ی مورد نظر صورت سوال است. در عوض، در فایل Kbuild بخش obj-y را باید آپدیت کرد. به انتهای این فایل hello.o (و در ادامه adder.o) را اضافه کردم. `
    ![image](images/28.png)

    13. [x] ‍‍`این قسمت را در فایل 64 عوض کردم و با توجه به داکیومنت‌ها، به جای i386 از common استفاده کردم. بعدا adder را هم اضافه کردم:`
    ![Screenshot (2593)](images/29.png)

    14. [x] ![image](images/30.png)

    15. [x] ![image](images/31.png)
        - [x] ![image](images/32.png)
        - [x] ![image](images/33.png)
        - [x] ![image](images/34.png)
        - [x] ![image](images/35.png)

- [x] ![image](images/36.png)
- [x] ![image](images/37.png)

- [x] ![image](images/38.png)
- [x] ![image](images/39.png)
- [x] ![image](images/40.png)

- [x] ![Screenshot (2621)](images/41.png)
- [x] ![image](images/42.png)
- [x] ![image](images/43.png)
- [x] ![image](images/44.png)
- [x] ![image](images/45.png)
