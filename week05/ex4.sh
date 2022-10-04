#!/bin/bash
gcc ex4.c -o ex4.o -pthread
>ex4.txt
start_time=$(date +%s)
./ex4.o 10000000 1
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex4.txt
start_time=$(date +%s)
./ex4.o 10000000 2
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex4.txt
start_time=$(date +%s)
./ex4.o 10000000 4
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex4.txt
start_time=$(date +%s)
./ex4.o 10000000 10
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex4.txt
start_time=$(date +%s)
./ex4.o 10000000 100
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex4.txt