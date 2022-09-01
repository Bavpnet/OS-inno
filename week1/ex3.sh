#!/bin/bash
mkdir ~/week1/folder1
touch ~/week1/folder1/root.txt
mkdir ~/week1/folder2
touch ~/week1/folder2/home.txt
ls / --sort=time -r > ~/week1/folder1/root.txt
cat  ~/week1/folder1/root.txt
ls ~/week1/folder1/
date
sleep 3
ls ~ --sort=time -r > ~/week1/folder2/home.txt
cat ~/week1/folder2/home.txt
ls ~/week1/folder2/
