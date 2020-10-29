dd if=/dev/zero of=MiOS.img bs=512 count=100

dd if=boot.flp of=MiOS.img conv=notrunc

pause