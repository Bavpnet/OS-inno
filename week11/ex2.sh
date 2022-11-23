cd lofsdisk
echo "Alexandra" > file1
echo "Chupkova" > file2
ls 
cat file1
cat file2
mkdir bin
mkdir lib
mkdir lib/aarch64-linux-gnu #M1 chip
mkdir lib64

cp /bin/bash bin/bash
cp /bin/ls bin/ls
cp /bin/cat bin/cat
cp /bin/echo bin/echo
cp /lib/aarch64-linux-gnu/libc.so.6 lib64/ #I have arm processor due to mac on M1 chip

ar=("bash" "ls" "cat" "echo") #array of command
for item in $ar
do
   list="$(ldd /bin/$item | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib)"
   #NF is a predefined variable whose value is the number of fields in the current record. 
   #awk updates the NF
   for j in $list
   do
      cp -v "$j" ".$j" #Outputs a message after the copy operation. 
   done
done

cd ..

gcc ex2.c -o ./lofsdisk/ex2.o

# ldd ./lofsdisk/ex2.o
sudo chroot ./lofsdisk ./ex2.o > ./lofsdisk/ex2.txt

./lofsdisk/ex2.o >> ./lofsdisk/ex2.txt
