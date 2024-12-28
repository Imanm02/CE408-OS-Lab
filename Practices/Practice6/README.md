Team Name: `99109325_99102207`

Student Name of member 1: `Negar Babashah`
Student No. of member 1: `99109325`

Student Name of member 2: `Iman Mohammadi`
Student No. of member 2: `99102207`

- [ ] Read Session Contents.

## Section 6.4

- [ ] Using `malloc` and `free` in program
    - [ ] ![image](https://github.com/user-attachments/assets/28797a45-1785-4881-91f6-899f1a839012)
    - [ ] ![image](https://github.com/user-attachments/assets/28797a45-1785-4881-91f6-899f1a839012)


    
- [ ]  Using `ps`
    - [ ] ![image](https://github.com/user-attachments/assets/0e3f28fa-299f-4f7d-9256-3dd87ce7f791)
    - [ ] USER: یوزرنیم کاربری که مالک پردازه است
    
VSZ: مقدار حافظه مجازی‌ به کیلوبایت که توسط پردازه استفاده میشود

RSS: مقدار حافظه‌ی فیزیکالی که پردازه اکنون در رم اشغال کرده است.

PMEM: درصدی از حافظه فیزیکال کل که پردازه مشغول کرده است

COMMAND: در واقع دستور یا فایل اجرایی که پردازه را اجرا کرده است

- [ ]  Getting started with memory segments
    - [ ] ![image](https://github.com/user-attachments/assets/c5a2fcba-fd31-453e-a41d-6bb0ade5a0d1)
    - [ ] ![image](https://github.com/user-attachments/assets/8047f6dc-bec3-4a9a-b8e3-96373ab3b166)
    - [ ]  دستور size اطلاعاتی درباره‌ی بخش heap و stack ارائه نمی‌دهد. چون این دو بخش در زمان اجرای پردازه مشخص می‌شوند و در زمان کامپایل اطلاعاتی درباره‌ی آن‌ها نداریم. 

- [ ] Getting started with memory sharing
    1. [ ] ![image](https://github.com/user-attachments/assets/2a1f2508-4b2e-4d03-849d-87980652c71c)
    1. [ ] ![image](https://github.com/user-attachments/assets/e51e491f-ef11-4fcf-9e9e-09f5d4405e79)
    1. [ ] ![image](https://github.com/user-attachments/assets/1d63f888-48ea-4c58-9852-635d36bc7505)
    2. [ ] ![image](https://github.com/user-attachments/assets/b9429301-ca91-4835-988e-d8ac119edc0f)



- [ ] Getting started with addresses

    1. [ ] ![image](https://github.com/user-attachments/assets/a4ece598-c134-4c42-a031-8ff6c1579926)
![image](https://github.com/user-attachments/assets/1d05f5b3-b38a-439a-82cc-546916ac650e)
همان طور که مشخص است، ترتیب قرار گیری ادرس‌ها از پایین به بالا text, initialized , uninitialized است که با قرارگیری در تصویر هم‌خوانی دارد.

    1. [ ] درباره‌ی کامنت: همان طور که در لینک گفته شده است،‌ این نمادها توسط لینکر آدرس‌دهی می‌شوند. اما ansi c می‌‌خواهد که کاربر اگر خواست بتواند متغیری مثل etext برای خودش تعریف کند. بنابراین اگر میخواهیم آن‌ها را به عنوان نماد استفاده کنیم بهتر از روش‌هایی مثل provide استفاده کنیم. حال اگر این کار را نکنیم، باید از یک تایپ مثل char برای تعریف آن‌ها استفاده کنیم، وگرنه کامپایلر warning می‌دهد. درواقع اگر با فلگ  -wall بیاییم gcc را اجرا کنیم این هشدارها هم نمایش داده می‌شوند و به مشکل می‌خوریم. بنابراین چیزی که کامنت می‌خواهد بگوید هم همین است.

متغیر یا نماد: تعریف متغیر مکان‌های ذخیره‌سازی است که مقادیر را نگه می‌دارند و تایپ خاصی دارند (مانند int). اما etext، edata و end نشان‌دهنده‌ی آدرس‌های خاصی هستند که توسط لینکر (یا توسط برنامه‌ای) تعریف شده‌اند، نه متغیرهایی که مقدار داشته باشند

درباره‌ی extern:    از آن در زبان C برای اعلام یک متغیر یا تابع استفاده می‌شود که در یک فایل دیگر تعریف شده است. بنابراین باید به کامپایلر اطلاع بدهیم که این نمادها وجود دارند اما در فایل فعلی تعریف نشده‌اند. 
    
    1. [ ] ![image](https://github.com/user-attachments/assets/f506049a-1d3f-4f10-8116-9256d3860080)
    ![image](https://github.com/user-attachments/assets/f8f51cf3-1a53-4928-8e98-be41d68736f5)

با وجود این که در سیستم من تعداد حلقه‌ها همان طور که انتظار می‌رفت ۱ بود، ولی ممکن است در سیستمی با توجه به مکانیزمی که برای malloc استفاده می‌شود، این اتفاق نیفتد. مثلا malloc یک pool داشته باشد و از روی آن حافظه‌های خالی را تخصیص دهد. در آن صورت تا زمانی که pool پر نشده است، آدرس خانه آخر هیپ تغییری نمی‌کند. 

    1. [ ] ![image](https://github.com/user-attachments/assets/d6d62f3d-4e5d-45c5-a50a-d7b5a0e4cd4a)
    
![image](https://github.com/user-attachments/assets/0639323c-9c3f-47ea-b3f6-72a5289de5b1)
![image](https://github.com/user-attachments/assets/46b6a68c-2b44-4988-83fa-3fa3e12f22bd)
همان طور که مشاهده می‌شود آدرس متغیر i در هر گام کمتر می‌شود. 
این به این دلیل است که استک از بالا به پایین رشد می‌کند. بنابراین وقتی یک فریم جدید به استک اضافه می‌شود، آدرس‌های متغیرهای تعریف شده در آن هم کمتر خواهند بود.


