#usr/bin/bash
echo 'Компилирую файл...'
gcc -Werror -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wenum-compare -Wfloat-equal -Wredundant-decls -Wsign-conversion -o a.out lab_01.c number.c divising.c
echo 'Компиляция окончена, проверьте созданный файл a.out'
