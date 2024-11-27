Copy the files and ensure this hierachy in the EFI partition:
- /limine.efi (renamed from limine/BOOTX64.EFI)
- /boot/myos
- /boot/limine/limine.conf
- /boot/limine/limine-bios.sys
- /boot/limine/limine-bios-cd.bin
- /boot/limine/limine-uefi-cd.bin

Additionally, this is the grub:
- /EFI/BOOT/BOOTX64.EFI

Then, reboot and enter grub, enter cmd mode (press c), run:
- chainloader (hd?,gpt?)/limine.efi
- boot
You now entered limine, select myOS, then press enter.
Now your kernel should boot.
