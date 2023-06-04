gcc -shared -Os -s -o crypto.dll crypto.c 
gcc -Os -s bigramm.c crypto.dll -o crypto_start 

rm *.o