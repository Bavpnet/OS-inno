#!bin/bash
gcc ex3.c &
./a.out 5 &
for i in 1 2 .. 5
do
    pstree $$
    sleep 5
done