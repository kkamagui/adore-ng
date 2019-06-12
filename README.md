```bash
  ▄▄▄      ▓█████▄  ▒█████   ██▀███  ▓█████        ███▄    █   ▄████ 
  ▒████▄    ▒██▀ ██▌▒██▒  ██▒▓██ ▒ ██▒▓█   ▀        ██ ▀█   █  ██▒ ▀█▒ 
  ▒██  ▀█▄  ░██   █▌▒██░  ██▒▓██ ░▄█ ▒▒███    ███  ▓██  ▀█ ██▒▒██░▄▄▄░ 
  ░██▄▄▄▄██ ░▓█▄   ▌▒██   ██░▒██▀▀█▄  ▒▓█  ▄  ▒▒▒  ▓██▒  ▐▌██▒░▓█  ██▓ 
   ▓█   ▓██▒░▒████▓ ░ ████▓▒░░██▓ ▒██▒░▒████▒      ▒██░   ▓██░░▒▓███▀▒ 
    ▒▒   ▓▒█░ ▒▒▓  ▒ ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░░░ ▒░ ░      ░ ▒░   ▒ ▒  ░▒   ▒ 
      ▒   ▒▒ ░ ░ ▒  ▒   ░ ▒ ▒░   ░▒ ░ ▒░ ░ ░  ░      ░ ░░   ░ ▒░  ░   ░ 
 	   ░   ▒    ░ ░  ░ ░ ░ ░ ▒    ░░   ░    ░            ░   ░ ░ ░ ░   ░ 
 	         ░  ░   ░        ░ ░     ░        ░  ░               ░       ░ 
 			            ░                                                       
                              Adore-ng v2.5 
```

Adore-NG v2.5
=============

Adore-ng v2.5 is a linux rootkit adapted for 2.6, 3.x, and 4.x (until 4.19). This rootkit was
upgraded for Shadow-box test. 

Shadow-box is a lightweight hypervisor-based kernel protector. Shadow-box was 
introduced at Black Hat Asia 2017, Black Hat Asia Arsenal 2017, and HITBSecConf
2017. 

Shadow-box is at GitHub below.
Project Link: https://github.com/kkamagui/shadow-box-for-x86

Usage
=====
```
# Run adore with full features.
$> sudo insmod adore.ko

# Run adore with no kernel patches. Only hiding PID and adore module works.
# This option is to test a detection feature of dynamic data area modification for Shadow-box.
$> sudo insmod adore.ko no_kern_patch=1 hide_pid=xxxx
```
