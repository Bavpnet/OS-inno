#!/bin/bash
gcc ex3.c -pthread -o ex3.o
>ex3.txt
start_time=$(date +%s)
./ex3.o 10000000 1
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex3.txt
start_time=$(date +%s)
./ex3.o 10000000  2
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex3.txt
start_time=$(date +%s)
./ex3.o 10000000  4
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex3.txt
start_time=$(date +%s)
./ex3.o 10000000 10
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex3.txt
start_time=$(date +%s)
./ex3.o 10000000 100
end_time=$(date +%s)
echo execution time was $(expr $end_time - $start_time) s. >>ex3.txt