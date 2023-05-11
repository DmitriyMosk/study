# study
My Learning Steps

lw_text_handl.c 
Поставленная задача: 

Создать файл, содержащий массив целых чисел. Найти
наименьшее из модулей отклонения чисел от их среднего
значения.

Многие функции вынесены в отдельные файлы
Запуск: 

gcc -c lw_binary_handl.c mylib/static_example/mytypes.c mylib/static_example/routes.c mylib/static_example/binary.c
либо 
gcc -c lw_binary_handl.c mylib/static_example/*.c
gcc -o lib_test *.o


Запуск, используя динамическую библиотеку

gcc -c lw_binary_handl.c
gcc -c -fPIC mylib/dynamic_example/*.c
gcc -shared -o mydlib.dll *.o

gcc -o dyn_example main.o -L. -lMY_PRINT -Wl,-rpath,.

//rm *.o -- удаление использованных объектных файлов 