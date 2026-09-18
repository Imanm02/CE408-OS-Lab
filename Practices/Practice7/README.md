Team Name: `99109325_99102207`

Student Name of member 1: `Negar Babashah`
Student No. of member 1: `99109325`

Student Name of member 2: `Iman Mohammadi`
Student No. of member 2: `99102207`

- [ ] Read Session Contents.

## Section 7.4

### Section 7.4.1
- [ ] Creating a thread using pthread
    - [ ] <img width="530" alt="{9F1D75B8-7FBF-4A91-9963-E5E887FFD312}" src="images/01.png" />

   
- [ ]  Checking the process ids
    - [ ] <img width="949" alt="{76432CCB-4E43-4ABD-BFE2-7677D2353AF1}" src="images/02.png" />

    - [ ] ![Uploading {73EF9B45-EB71-448C-93B9-8A7465DB4E52}.png…]()

    - [ ] همان طور که مشاهده می‌شود pidها یکسان هستند. دلیلش هم این است که دو ترد ایجاد شده هر دو متعلق به یک پراسس هستند.

- [ ]  Shared variables
    - [ ] <img width="959" alt="{145C6661-E64E-402E-AAB4-9F2FCA31B2E3}" src="images/03.png" />

    - [ ] <img width="958" alt="{BEFD08F5-3771-4FB0-BD2F-F2206FB069CE}" src="images/04.png" />

    - [ ]  همان طور که دیده می‌شود مقدارهای oslab در هر دو ترد یکسان است. بنابراین متغیرهای گلوبال در همه‌ی تردهای یک پردازه یکسان هستند و کپی جداگانه‌ای گرفته نمی‌شود.

- [ ] Sum of 2 to n
    1. [ ] <img width="944" alt="{F4E34EAC-3B0D-46B2-B6AF-347657CB4ED6}" src="images/05.png" />


    1. [ ] <img width="959" alt="{BB1CEDD4-0E1F-40C9-9511-A33ABD6BCC9B}" src="images/06.png" />

### Section 7.4.2
- [ ] Multiple threads    
    - [ ] <img width="960" alt="{20D4290E-B3C1-43D6-BDE8-DC8F37266908}" src="images/07.png" />

    - [ ] <img width="928" alt="{15DF2ED2-5159-46B0-B947-A69A353E8405}" src="images/08.png" />


### Section 7.4.3
- [ ] Compiling the code
    - [ ] ![Uploading {FF0102AC-174C-48C8-95B6-5DB274B8FB44}.png…]()


- [ ] global_param
    - [ ] <img width="948" alt="{4B5634D2-6BA2-46E9-B06C-14193DEF06FE}" src="images/09.png" />

    - [ ] <img width="924" alt="{18D05813-9833-4FEA-AEB1-199E9144325D}" src="images/10.png" />

- مشاهده می‌شود که مقدار متغیر گلوبال دو واحد تغییر کرده است. یعنی هر دو ترد آن را افزایش داده‌اند. بنابراین یعنی تردها به متغیرهای گلوبال یکسانی دسترسی دارند.

- [ ] Forking
    - [ ] <img width="954" alt="{0C1E5376-096A-4FA1-ACD0-5ADC99F08EBF}" src="images/11.png" />

<img width="917" alt="{8C438690-5F77-42F2-AA7F-9342FA852AA9}" src="images/12.png" />

    - [ ] <img width="956" alt="{F9FB3B54-E03C-427A-8829-B98F7B27463D}" src="images/13.png" />

- همان طور که مشاهده می‌شود مقادیر متغیرهای لوکال و گلوبال در پردازه‌ی پدر و فرزند متفاوت هستند. یعنی فرزند کپی خودش را از این متتغیرها نگه می‌دارد و با چیزی که پدر نگه می‌دارد یکسان نیست. 

### Section 7.4.4
- [ ] Passing multiple variables
    - [ ] <img width="939" alt="{890BB8F3-497B-4272-988E-D17B9DC106F0}" src="images/14.png" />

    - [ ] <img width="952" alt="{F2306823-2843-4C2F-AD10-CD132C02E6FE}" src="images/15.png" />
