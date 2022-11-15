echo "Alexandta Chupkova, BS-06" > _ex3.txt
touch ex3.txt
chmod a-x _ex3.txt #remove execute permission for all
ls -l _ex3.txt >> ex3.txt
chmod u=rwx _ex3.txt #get all permissions to owner
ls -l _ex3.txt >> ex3.txt
chmod o=rwx _ex3.txt #add all permissions to others
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt #set group permissions
ls -l  _ex3.txt >> ex3.txt
