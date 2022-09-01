#!/bin/bash
date
sleep 3
mkdir ~/week1/folder1
date
sleep 3
touch ~/week1/folder1/root.txt
date
sleep 3
mkdir ~/week1/folder2
date
sleep 3
touch ~/week1/folder2/home.txt
ls / --sort=time -r > ~/week1/folder1/root.txt
cat  ~/week1/folder1/root.txt
ls ~ --sort=time -r > ~/week1/folder2/home.txt
cat ~/week1/folder2/home.txt
ls ~/week1/folder1/
ls ~/week1/folder2/
