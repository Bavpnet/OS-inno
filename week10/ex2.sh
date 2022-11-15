mkdir ../week01
echo "Alexandra Chupkova, BS-06" > _ex2.txt
cd ../week01
touch file.txt
link ../week01/file.txt _ex2.txt
find ../week01/file.txt -inum $(stat -c '%i' _ex2.txt) > ex2.txt
find ../week01/file.txt -inum $(stat -c '%i' _ex2.txt) -exec rm {} \; >> ex2.txt
cat ex2.txt
