savedcmd_/root/my_softirq_module/my_softirq_module.mod := printf '%s\n'   my_softirq_module.o | awk '!x[$$0]++ { print("/root/my_softirq_module/"$$0) }' > /root/my_softirq_module/my_softirq_module.mod
