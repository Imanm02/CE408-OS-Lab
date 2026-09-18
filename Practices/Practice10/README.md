Team Name: `99109325_99102207`

Student Name of member 1: `Negar Babashah`
Student No. of member 1: `99109325`

Student Name of member 2: `Iman Mohammadi`
Student No. of member 2: `99102207`

- [ ] Read Session Contents.

## Section 10.3
- [ ] "Hello World" linux driver
  
  - [ ] ابتدا فایل hello.c را می‌سازیم که قرار است در هسته اجرا شود. از هدر module.h هم استفاده می‌کنیم. 
      یک فایل Makefile هم می‌سازیم که در تصاویر محتوای آن مشخص است. پس از آن دستور make را می‌زنیم تا ماژول‌ها ساخته شوند. سپس، با استفاده از دستور insmod hello.ko، برنامه را به فضای کرنل اضافه می‌کنیم. به این صورت ماژول hello به لیست ماژول‌های فعال کرنل اضافه می‌شود.
  - [ ] کد فایل hello.c به شرح زیر است:
  ```c
  #include <linux/module.h>
  #include <linux/kernel.h>
  #include <linux/init.h>
  
  static int __init hello_init(void) {
      printk(KERN_INFO "Hello\n");
      return 0;
  }
  
  module_init(hello_init);
  MODULE_LICENSE("GPL");
  ```


    - [ ]  تصاویر اجرا:
 ![image](images/01.png)
![image](images/02.png)


    

## Section 10.4
- [ ] Network Sniffing Driver 

  - [ ]  گوش دادن به اطلاعات شبکه را به دو صورت انجام می‌دهیم.
     روش اول از netfilter استفاده می‌کند که در دستور کار هم آمده است و یک ماژولی اضافه می‌کنیم که در سطح کرنل اجرا می‌شود. در روش دوم که در سطح کاربر اجرا می‌شود از وایرشارک و یک سری پکت دیگر برای خواندن و ذخیره‌ی ارتباطات شبکه استفاده می‌کنیم. 

  - [ ]  کد این بخش به این صورت است که ساختار آن خیلی مشابه با قسمت ۱ است.
  
  ```c

  #include <linux/module.h>
  #include <linux/kernel.h>
  #include <linux/netfilter.h>
  #include <linux/netfilter_ipv4.h>
  #include <linux/skbuff.h>
  #include <linux/ip.h>
  #include <linux/fs.h>
  #include <linux/uaccess.h>
  
  static struct nf_hook_ops netfilter_ops;
  
  void log_packet(const char *data);
  
  void log_packet(const char *data) {
      struct file *file;
      loff_t pos = 0;
      file = filp_open("/var/log/packet_log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
      if (!IS_ERR(file)) {
          kernel_write(file, data, strlen(data), &pos);
          filp_close(file, NULL);
      } else {
          printk(KERN_ERR "%ld\n", PTR_ERR(file));
      }
  }
  
  static unsigned int packet_handler(void *priv, struct sk_buff *skb, const struct nf_hook_state *state) {
      struct iphdr *ip_header;
      char log_entry[256];
      if (!skb)
          return NF_ACCEPT;
      ip_header = ip_hdr(skb);
      if (ip_header) {
          snprintf(log_entry, sizeof(log_entry), "SRC: %pI4, DST: %pI4\n", &ip_header->saddr, &ip_header->daddr);
          log_packet(log_entry);
      }
      return NF_ACCEPT;
  }
  
  static int __init vnet_init(void) {
      netfilter_ops.hook = packet_handler;
      netfilter_ops.pf = PF_INET;
      netfilter_ops.hooknum = NF_INET_PRE_ROUTING;
      netfilter_ops.priority = NF_IP_PRI_FIRST;
      nf_register_net_hook(&init_net, &netfilter_ops);
      printk(KERN_INFO "My driver init\n");
      return 0;
  }
  
  static void __exit vnet_exit(void) {
      nf_unregister_net_hook(&init_net, &netfilter_ops);
      printk(KERN_INFO "My driver exit\n");
  }
  
  
  module_init(vnet_init);
  module_exit(vnet_exit);
  
  MODULE_LICENSE("GPL");
  ```

  - [ ] اجرای کد و مراحل اضافه کردن ماژول به کرنل (مشابه بخش ۱ است):
      
![image](images/03.png)

![image](images/04.png)

خروجی‌ها هم به این صورت هستند:
![image](images/05.png)

و به این ترتیب ارتباطات شبکه را توانستیم ببینیم.

  در روش دوم ابتدا پکیج‌های مورد نیاز برای این کار را نصب می‌کنیم. که یکی  tcpreplay است که برای ارسال ترافیک شبکه به درایور مجازی استفاده می‌شود، یکی دیگر هم tcpdump است که برای گوش دادن به ترافیک شبکه باید استفاده کنیم. 
      ![image](images/06.png)

  حال باید درایور مجازی را ایجاد کنیم. برای این کار از دستور ip استفاده می‌کنیم به این صورت:
![image](images/07.png)

حال برای گوش دادن به ترافیک شبکه یک bridge شبکه به نام br0 درست می‌کنیم و رابط‌های مجازی veth0 و veth1 را هم اضافه می‌کنیم. سپس br0 را فعال می‌کنیم.
![image](images/08.png)

در نهایت با استفاده از دستور tcpdump به ترافیک گوش می‌دهیم و خروجی آن را در یک فایل pcap می‌ریزیم.
![image](images/09.png)

حال می‌توان محتوای فایل را با استفاده از وایرشارک باز کرد (دستور wireshark traffic.pcap)
![image](images/10.png)


  - [ ]  کدی در این قسمت نوشته نشده است ولی دستورات اجرا شده به ترتیب زیر هستند:
 
```
    sudo apt-get install tcpreplay tcpdump
    
    sudo ip link add veth0 type veth peer name veth1
    sudo ip link set veth0 up
    sudo ip link set veth1 up
   
    sudo brctl addbr br0
    sudo brctl addif br0 veth0
    sudo brctl addif br0 veth1
    sudo ip link set br0 up
    
    sudo tcpdump -i veth0 -w traffic.pcap
    sudo tcpreplay -i veth1 traffic.pcap
    wireshark traffic.pcap
 ```

