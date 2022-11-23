cd lofsdisk
echo "Alexandra" > file1
echo "Chupkova" > file2
ls 
cat file1
cat file2
mkdir bin
mkdir lib
mkdir lib/aarch64-linux-gnu
mkdir lib64

cp /bin/bash bin/bash
cp /bin/ls bin/ls
cp /bin/cat bin/cat
cp /bin/echo bin/echo
cp /lib/aarch64-linux-gnu/libc.so.6 lib64/ #I have arm processor due to mac on M1 chip

cmd="bash"
for i in $cmd
do
   list="$(ldd /bin/$i | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib)"
   for j in $list
   do
      cp -v "$j" ".$j"
   done
done

cmd="ls"
for i in $cmd
do
   list="$(ldd /bin/$i | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib)"
   for j in $list
   do
      cp -v "$j" ".$j"
   done
done
cmd="cat"
for i in $cmd
do
   list="$(ldd /bin/$i | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib)"
   for j in $list
   do
      cp -v "$j" ".$j"
   done
done
cmd="echo"
for i in $cmd
do
   list="$(ldd /bin/$i | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib)"
   for j in $list
   do
      cp -v "$j" ".$j"
   done
done
cd ..

gcc ex2.c -o ./lofsdisk/ex2.o

# ldd ./lofsdisk/ex2.o
sudo chroot ./lofsdisk ./ex2.o > ./lofsdisk/ex2.txt

./lofsdisk/ex2.o >> ./lofsdisk/ex2.txt
