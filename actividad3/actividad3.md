Henderson Baten - 201019694

--------------------------------------------Parte 1: Gestión de Usuarios

hendr@LAPTOP-MB3128MT:~$ sudo adduser usuario1
[sudo] password for hendr:
Adding user `usuario1' ...
Adding new group `usuario1' (1001) ...
Adding new user `usuario1' (1001) with group `usuario1' ...
Creating home directory `/home/usuario1' ...
Copying files from `/etc/skel' ...
New password:
Retype new password:
passwd: password updated successfully
Changing the user information for usuario1
Enter the new value, or press ENTER for the default
        Full Name []: usuario1
        Room Number []: 1
        Work Phone []: 1
        Home Phone []: 1
        Other []:
Is the information correct? [Y/n] y
hendr@LAPTOP-MB3128MT:~$ sudo adduser usuario2
Adding user `usuario2' ...
Adding new group `usuario2' (1002) ...
Adding new user `usuario2' (1002) with group `usuario2' ...
Creating home directory `/home/usuario2' ...
Copying files from `/etc/skel' ...
New password:
Retype new password:
passwd: password updated successfully
Changing the user information for usuario2
Enter the new value, or press ENTER for the default
        Full Name []: 2
        Room Number []: 2
        Work Phone []: 2
        Home Phone []: 2
        Other []:
Is the information correct? [Y/n] y
hendr@LAPTOP-MB3128MT:~$ sudo adduser usuario3
Adding user `usuario3' ...
Adding new group `usuario3' (1003) ...
Adding new user `usuario3' (1003) with group `usuario3' ...
Creating home directory `/home/usuario3' ...
Copying files from `/etc/skel' ...
New password:
Retype new password:
passwd: password updated successfully
Changing the user information for usuario3
Enter the new value, or press ENTER for the default
        Full Name []: 3
        Room Number []: 3
        Work Phone []:
        Home Phone []: 3
        Other []:
Is the information correct? [Y/n] y
hendr@LAPTOP-MB3128MT:~$ sudo userdel -r usuario3
userdel: usuario3 mail spool (/var/mail/usuario3) not found

---------------------------------------------Parte 2: Gestión de Grupos


hendr@LAPTOP-MB3128MT:~$ sudo groupadd grupo1
hendr@LAPTOP-MB3128MT:~$ sudo groupadd grupo2
hendr@LAPTOP-MB3128MT:~$ sudo usermod -aG grupo1 usuario1
hendr@LAPTOP-MB3128MT:~$ sudo usermod -aG grupo2 usuario2
hendr@LAPTOP-MB3128MT:~$ groups usuario1
usuario1 : usuario1 grupo1
hendr@LAPTOP-MB3128MT:~$ groups usuario2
usuario2 : usuario2 grupo2
hendr@LAPTOP-MB3128MT:~$ sudo groupdel grupo2



---------------------------------------------Parte 3: Gestión de Permisos

hendr@LAPTOP-MB3128MT:~$ echo "content for user1" > ~/archivo1.txt
hendr@LAPTOP-MB3128MT:~$ mkdir ~/directorio1
hendr@LAPTOP-MB3128MT:~$ echo "content for user1 file2" > ~/directorio1/archivo2.txt
hendr@LAPTOP-MB3128MT:~$ ls -l ~/archivo1.txt
-rw-r--r-- 1 hendr hendr 18 Aug  4 23:17 /home/hendr/archivo1.txt
hendr@LAPTOP-MB3128MT:~$ ls -ld ~/directorio1
drwxr-xr-x 2 hendr hendr 4096 Aug  4 23:18 /home/hendr/directorio1
hendr@LAPTOP-MB3128MT:~$ chmod 640 ~/archivo1.txt
hendr@LAPTOP-MB3128MT:~$ chmod u+x ~/directorio1/archivo2.txt
hendr@LAPTOP-MB3128MT:~$ sudo chgrp grupo1 ~/directorio1/archivo2.txt
hendr@LAPTOP-MB3128MT:~$ chmod 740 ~/directorio1
hendr@LAPTOP-MB3128MT:~$ echo "content for user1" > ~/archivo1.txt
hendr@LAPTOP-MB3128MT:~$ mkdir ~/directorio1
hendr@LAPTOP-MB3128MT:~$ echo "content for user1 file2" > ~/directorio1/archivo2.txt
hendr@LAPTOP-MB3128MT:~$ ls -l ~/archivo1.txt
-rw-r--r-- 1 hendr hendr 18 Aug  4 23:17 /home/hendr/archivo1.txt
hendr@LAPTOP-MB3128MT:~$ ls -ld ~/directorio1
drwxr-xr-x 2 hendr hendr 4096 Aug  4 23:18 /home/hendr/directorio1
hendr@LAPTOP-MB3128MT:~$ chmod 640 ~/archivo1.txt
hendr@LAPTOP-MB3128MT:~$ chmod u+x ~/directorio1/archivo2.txt
hendr@LAPTOP-MB3128MT:~$ sudo chgrp grupo1 ~/directorio1/archivo2.txt
hendr@LAPTOP-MB3128MT:~$ chmod 740 ~/directorio1
