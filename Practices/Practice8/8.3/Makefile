obj-m += syscall_printer.o

build:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

remove:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean