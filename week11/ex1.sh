dd if=/dev/zero of=lofs.img bs=1024 count=51200 # the number of blocks
/sbin/mkfs lofs.img
mkdir lofsdisk
sudo mount -o loop lofs.img lofsdisk
sudo chmod 777 lofsdisk #add permission to edit
sudo chmod 777 lofsdisk/lost+found # add permission to edit 