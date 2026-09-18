# Practice 1: Installing Linux and rebuilding the kernel

Session 1. Official instructions: [session1.md](https://github.com/Sharif-OS-Lab/session-1-2/blob/main/session1.md)

The session asked us to install Debian in a virtual machine, work through a list of basic shell exercises, write up what seven common commands do, and then fetch the kernel source, configure it, and build and install a new kernel. We used VMware, and the kernel we built and installed was 5.15.163.

One thing worth knowing before reading: the spec asks for Debian, but the guest in most of these screenshots is Ubuntu 22.04, so the package names and repository URLs in them are Ubuntu's. Only the first screenshot is from the installer itself; the template asked for three and we kept one.

---

Student Name of member 1: `Iman Mohammadi`

Student Name of member 2: `Negar Babashah`

- [x] Read Session Contents.

### Section 1.3.1
- [x] Choose one of Virtual Machine Softwares, such as VirtualBox, VMware, ...
    1. [x] `VMware`
- [x] Install Debian on Virtual Machine, add three screenshots from install process
    1. [x] ![pic1](images/01.jpg)
    2. [x] ![pic2](images/02.jpg)

### Section 1.3.2

- [x] Do 13 subtasks from 1 to 13 and add screenshots of each:
    1. [x] ![pic3](images/03.jpg)
    1. [x] ![pic4](images/04.jpg)
    1. [x] ![pic5](images/05.jpg)
    1. [x] ![pic6](images/06.jpg)
    1. [x] ![pic7](images/07.jpg)
    1. [x] ![pic8](images/08.jpg)
    1. [x] ![pic9](images/09.jpg)
    1. [x] ![pic10](images/10.jpg)
    1. [x] ![pic11](images/11.jpg)
    1. [x] ![pic12](images/12.jpg)
    1. [x] ![pic13](images/13.jpg)
    1. [x] ![pic14](images/14.jpg)
    1. [x] ![pic15](images/15.jpg)
    1. [x] ![pic16](images/16.jpg)
    1. [x] ![pic17](images/17.jpg)
    1. [x] ![pic18](images/18.jpg)
    1. [x] ![pic19](images/19.jpg)
    1. [x] ![pic20](images/20.jpg)
    1. [x] ![pic21](images/21.jpg)
    1. [x] ![pic22](images/22.jpg)
    1. [x] ![pic23](images/23.jpg)
    1. [x] ![pic24](images/24.jpg)
    1. [x] ![pic25](images/25.jpg)
    1. [x] ![pic26](images/26.jpg)
    1. [x] ![pic27](images/27.jpg)
    1. [x] ![pic28](images/28.jpg)

- [x] For subtask 7 write difference between `>` and `>>`

<div dir="rtl">

تفاوت بین <span dir="ltr">`>`</span> و <span dir="ltr">`>>`</span> در لینوکس و سایر سیستم‌های مبتنی بر یونیکس مربوط به نحوه انتقال خروجی دستورات به فایل است:

- <span dir="ltr">`>`</span>:

این عملگر خروجی را به یک فایل هدایت می‌کند، اما اگر فایل از قبل وجود داشته باشد، محتوای آن را پاک کرده و با خروجی جدید جایگزین می‌کند. به عبارت دیگر، <span dir="ltr">`>`</span> باعث بازنویسی (overwrite) فایل می‌شود.
  
- <span dir="ltr">`>>`</span>:

این عملگر نیز خروجی را به یک فایل هدایت می‌کند، اما اگر فایل از قبل وجود داشته باشد، خروجی جدید را به انتهای فایل اضافه می‌کند. به این ترتیب، <span dir="ltr">`>>`</span> محتوای قبلی فایل را حفظ کرده و خروجی جدید را به آن اضافه می‌کند (append).

به عنوان مثال:
- `echo "Hello" > file.txt`

محتوای فایل `file.txt` را با کلمه "Hello" جایگزین می‌کند.
- `echo "World" >> file.txt`

کلمه "World" را به انتهای محتوای فایل `file.txt` اضافه می‌کند بدون اینکه محتوای قبلی پاک شود.

</div>

## Section 1.4 

- [x] Write (in English or Persian) about each command:

<div dir="rtl">

- [x] درباره هر دستور بنویسید (به انگلیسی یا فارسی):
    1. دستور `cut`:
دستور `cut` در لینوکس برای برش و استخراج بخش‌های مشخصی از هر خط از ورودی استفاده می‌شود. این دستور به شما اجازه می‌دهد که ستون‌های خاص یا کاراکترهای خاص را از یک فایل یا ورودی جدا کنید.

    2. دستور `find`:
دستور `find` برای جستجوی فایل‌ها و دایرکتوری‌ها در یک ساختار دایرکتوری به کار می‌رود. می‌توان با این دستور بر اساس نام، نوع، اندازه و سایر ویژگی‌های فایل جستجو انجام داد.

    3. دستور `head`:
دستور `head` اولین چند خط از یک فایل یا ورودی استاندارد را نمایش می‌دهد. به طور پیش‌فرض، ۱۰ خط اول را نشان می‌دهد، اما می‌توان تعداد خطوط را تغییر داد.

    4. دستور `tail`:
دستور `tail` آخرین چند خط از یک فایل یا ورودی استاندارد را نمایش می‌دهد. به طور پیش‌فرض، ۱۰ خط آخر را نشان می‌دهد، اما می‌توان تعداد خطوط را تنظیم کرد.

    5. دستور `touch`:
دستور `touch` برای ایجاد فایل‌های خالی جدید یا به‌روزرسانی زمان تغییرات فایل‌های موجود استفاده می‌شود.

    6. دستور `wc`:
دستور `wc` تعداد خطوط، کلمات و کاراکترهای یک فایل یا ورودی استاندارد را می‌شمارد و نمایش می‌دهد.

    7. دستور `kill`:
دستور `kill` برای ارسال سیگنال به یک پردازه (process) استفاده می‌شود. معمولاً برای خاتمه دادن به یک پردازه از این دستور استفاده می‌شود.

</div>


- [x] Write commands for these operations:
    - [x] `wc -l mybook.txt`
    - [x] `ls | grep -E "^(A+)" | wc --lines`
    - [x] `du -h mybook.txt`

### Section 1.4.1

- [x] Get kernel with apt-get
    - [x] ![pic29](images/29.jpg)
    - [x] ![pic30](images/30.jpg)
- [x] Get tools for compiling kernel
    - [x] ![pic31](images/31.jpg)
    - [x] ![pic32](images/32.jpg)
- [x] Do subtask 3
    - [x] ![pic33](images/33.jpg)
    - [x] ![pic34](images/34.jpg)
    - [x] ![pic35](images/35.jpg)

### Section 1.4.2

- [x] Compile kernel
    - [x] ![pic36](images/36.jpg)
    - [x] ![pic37](images/37.jpg)
    - [x] ![pic38](images/38.jpg)
    - [x] ![pic39](images/39.jpg)
    - [x] ![pic40](images/40.jpg)

- [x] Install compiled kernel
    - [x] ![pic41](images/41.jpg)
    - [x] ![pic42](images/42.jpg)
    - [x] ![pic43](images/43.jpg)
    - [x] ![pic44](images/44.jpg)
    - [x] ![pic45](images/45.jpg)
