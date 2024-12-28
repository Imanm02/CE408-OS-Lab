Team Name: `99109325_99102207`

Student Name of member 1: `Negar Babashah`
Student No. of member 1: `99109325`

Student Name of member 2: `Iman Mohammadi`
Student No. of member 2: `[99102207`

- [ ] Read Session Contents.

### Section 4.4.1
- [ ] Investigate the ps command
    1. [ ] ![image](https://github.com/user-attachments/assets/e8255b80-f123-4b29-9730-082d7160e9d3)

   
- [ ] Infromation about processes with PID = 1
    1. [ ] می‌توان طبق تصویر زیر دید که پردازه با pid=1 همان init است. 
    ![image](https://github.com/user-attachments/assets/ca494c5a-6b0f-484d-80a7-b7899ff73d67)
حال با استفاده از man initاطلاعات مربوط به آن را پیدا می‌کنیم:
![image](https://github.com/user-attachments/assets/c75e51b4-2339-4488-8c43-6ff9df644763)
بنابراین این پردازه پردازه‌ای است که با اولین پردازه که در سیستم عامل لود شده و اجرا می‌شود. وظیفه‌ی اصلی آن مدیریت فرآیندها و سیگنال‌ها در سیستم عامل است. پردازه‌های بعدی از بچه‌های این پردازه به بعد به وجود می‌آیند.

- [ ] Program using getpid
    1. [ ] ![image](https://github.com/user-attachments/assets/c3d303e5-d047-4409-bc44-71c873bdbfec)
    ![image](https://github.com/user-attachments/assets/22395433-ef04-468f-b612-1781606923bf)


### Section 4.4.2


- [ ] Program using getppid
    1. [ ] ![image](https://github.com/user-attachments/assets/1fea21bc-b008-4afc-a2a7-77735ff81773)
    1. [ ] پردازه‌ی پدر این پردازه، همان bash است. چرا که ما آن را از طریق ترمینال اجرا کرده‌ایم. بنابراین bash می‌آید یک فرزندی می‌سازد که درواقع همان کدی است که زده‌ایم. طبق تصویر زیر، bash پردازه‌ای است که دستورها را از طریق ورودی استاندارد یا از طریق یک فایل اجرا می‌کند.     
![image](https://github.com/user-attachments/assets/ce8105b5-71e8-4627-94ef-0d058599fe54)

    1. [ ] ![image](https://github.com/user-attachments/assets/2bae3dca-cba4-44c9-ad58-086dff350147)


- [ ] Describe the C program (fork program)
    1. [ ] تابع fork() در خروجی خود به پردازه‌ی فرزند ۰ و به پردازه‌ی والد pid مربوط به فرزند را خروجی می‌دهد. بنابراین فرزند وارد if اول می‌شود ولی والد نمی‌شود. فرزند وقتی اجرا شود مقدار ۲۳ را برمی‌گرداند. والد که به بخش else رفته است، تا زمانی که فرزند اجرایش تمام نشده باشد wait می‌کند و چیزی که فرزند return کرده باشد را در rc می‌ریزد. که همان طور که نمایش داده شده است، ۲۳ است.
![image](https://github.com/user-attachments/assets/5162fed5-c145-4b35-b508-ed3c2c51b560)

- [ ] Program showing that memory of the parent and the child is seperate
    1. [ ] ![image](https://github.com/user-attachments/assets/a478b21b-289a-4fb9-b7a6-15a72d411c7f)
![image](https://github.com/user-attachments/assets/dce8e132-1ab1-413b-9ca2-4538a05ed04c)
توضیح: همان طور که مشاهده می‌شود، مقدار a در ابتدا ۱۰ بود. این مقدار در حافظه‌ی فرزند هم کپی می‌شود (برای آن تعریف شده است). ولی فرزند می‌تواند آن را تغییر دهد، بدون این که مقدار مورد نظر برای والد تغییر کند.

- [ ] Program printing different messages for parent and child process
    1. [ ] ![image](https://github.com/user-attachments/assets/46293097-3b39-4ec7-9303-d5f46bbe95ec)
![image](https://github.com/user-attachments/assets/6e8592d2-7222-4ae0-97e0-2c576bcd05d6)


- [ ] Program for the last task of this section
    1. [ ] ![image](https://github.com/user-attachments/assets/3823b68e-e14e-4100-84c8-4699204e993f)

    1. [ ] ![image](https://github.com/user-attachments/assets/00aea96d-0692-4b2e-be3c-6d01b51937e8)
همان طور که مشخص است، ۳ بار از fork استفاده شده است. هر fork متناظر با خودش، یک پردازه‌ی فرزند دیگر نیز اضافه می‌کند که می‌تواند fork های بعدی را هم اجرا کند. توجه کنید که اولین پردازه‌ی child وارد if کد بخش ۲ می‌شود و return 23 می‌کند. یعنی دیگر این پردازه forkهای بعدی را اجرا نمی‌کند. بنابراین پردازه‌های بعدی را parent این پردازه ساخته است. پس مقدار ret1 (خروجی اولین fork) برای سایر پردازه‌ها برابر با pid این پردازه (در اینجا ۳۵۹) است. پس از آن، دوباره یک fork اجرا می‌شود. مقدار ret2 برای پردازه‌ی پدرش برابر با pidاش بوده (در اینجا ۳۶۰) و برای پردازه‌ی جدید، ۰ است. حال هر دوی این پردازه‌ها،  به سراغ fork بعدی می‌روند و هر یک یک child جدید نیز ایجاد می‌کنند. بنابراین در نهایت ۴ پردازه خط آخر را اجرا می‌کنند که با استدلال مشابه قبل، ترکیب‌های مختلفی از مقدارهای ممکن برای ret2 , ret3 را می‌گیرند (۴ ترکیب در مجموع).

## Section 4.4.3

- [ ] Program using `wait` and counting from 1 to 100
    1. [ ] ![image](https://github.com/user-attachments/assets/356d57e3-1856-416b-a6f5-cafaa5d751f2)
    همان طور که مشخص است، پردازه‌ی پدر آنقدر منتظر می‌ماند تا پردازه‌ی فرزند کارش را انجام بدهد، و سپس از wait خارج می‌شود.
![image](https://github.com/user-attachments/assets/eba8555e-3408-4c59-a4f2-36886eb73210)

    1. [ ] `پارامتر اول تابع wait، از جنس int* به نام wstatus است. اگر این پوینتر null قرار داده نشود، اطلاعاتی از پردازه‌ای که برای آن wait کرده‌ایم (پردازه فرزند) در آن قرار داده می‌شود و مانند بخش ۴.۴.۱ گزارش کار، می‌توان با فراخوانی توابعی مانند WEXITSTATUS، اطلاعات مربوط به پردازه (مثلا این که با چه سیگنال یا کدی خارج شده است یا ...) را مشاهده کرد.`

- [ ] Program showing process adoption
    1. [ ] ![image](https://github.com/user-attachments/assets/d29c8747-24e0-4d86-b5d6-ee5e19db2d84)
    1. [ ] ![image](https://github.com/user-attachments/assets/849b0636-e691-4ef7-a0bd-6e2faf5729f5)
همان طور که مشاهده می‌شود، پردازه‌ی parent به پایان می‌رسد اما پس از آن همچنان child ادامه دارد و parent آن پردازه با pid=9 می‌شود. در خروجی ps aux مشاهده می‌شود که این پردازه همان init است.

### Section 4.4.4

- [ ] Describe following commands/APIs:
    1. `execv: این دستور برای اجرای یک فایل executableبا استفاده از لیستی از آرگومان‌ها به کار می‌رود که  آرگومان‌ها به صورت لیست به تابع پاس داده می‌شوند. آرگومان اول مسیر اجرایی فایل، آرگومان دوم اسم خود برنامه، و آرگومان سوم لیستی از آرگومان‌هایی است که باید به برنامه پاس داده شوند. پس از آن هم Null را می‌دهیم تا نشان دهیم آرگومان‌ها تمام شده‌اند. اگر اجرای این تابع موفقیت‌آمیز باشد، هیچ‌گاه به خط بعدی کد باز نمی‌گردد. در صورت بروز خطا، مقدار -1 برگردانده می‌شود و متغیر errno تنظیم می‌شود تا نوع خطا را مشخص کند.
`

    1. `execl: این دستور مشابه دستور execv برای اجرای یک فایل executableبا استفاده از لیستی از آرگومان‌ها به کار می‌رود که به صورت جداگانه به تابع پاس داده می‌شوند. آرگومان اول مسیر اجرایی فایل، آرگومان دوم اسم خود برنامه، و آرگومان سوم به بعد، آرگومان‌هایی هستند که باید به برنامه پاس داده شوند.
`
    1. `execvp:  این دستور مشابه با دستور execv است، اما فایل اجرایی را در مسیرهای مشخص شده در متغیر محیطی PATH جست‌و‌جو می‌کند. در واقع نیاز به مشخص کردن کامل آدرس فایل اجرایی نیست، به شرطی که در PATH تعریف شده باشد. 
`

    1. `execlp: این دستور هم مشابه با دستور execl است، اما فایل اجرایی را در مسیرهای مشخص شده در متغیر محیطی PATH جست‌و‌جو می‌کند. در واقع نیاز به مشخص کردن کامل آدرس فایل اجرایی نیست، به شرطی که در PATH تعریف شده باشد. 
`

- [ ] Program which forks and executues `ls` command
    1. [ ] ![image](https://github.com/user-attachments/assets/b5385be6-660b-48c6-bd1d-396ab1c26859)

    1. [ ] ![image](https://github.com/user-attachments/assets/e431d7c7-98d5-4fe9-801e-8bc85cdf3a22)


## Source Code Submission

please submit all your codes in a zip file

 - [ ] [session4.zip](https://github.com/user-attachments/files/17681101/session4.zip)
