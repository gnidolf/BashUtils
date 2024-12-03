#!/bin/bash

make s21_grep
./s21_grep ^a ../tst3.txt > grep_test.txt
grep ^a ../tst3.txt > orig_grep_test.txt

if diff grep_test.txt orig_grep_test.txt; then
    echo "PASS"
else
    echo "FAIL"
fi


./s21_grep -e ^a ../tst3.txt > grep_test.txt
grep -e ^a ../tst3.txt > orig_grep_test.txt

if diff -q grep_test.txt orig_grep_test.txt; then
    echo "-e PASS"
else
    echo "-e FAIL"
fi


./s21_grep -v ^a ../tst3.txt > grep_test.txt
grep -v ^a ../tst3.txt > orig_grep_test.txt

if diff grep_test.txt orig_grep_test.txt; then
    echo "-v PASS"
else
    echo "-v FAIL"
fi


./s21_grep -i ^a ../tst3.txt > grep_test.txt
grep -i ^a ../tst3.txt > orig_grep_test.txt

if diff -q grep_test.txt orig_grep_test.txt; then
    echo "-i PASS"
else
    echo "-i FAIL"
fi


./s21_grep -l ^a ../tst3.txt > grep_test.txt
grep -l ^a ../tst3.txt > orig_grep_test.txt

if diff -q grep_test.txt orig_grep_test.txt; then
    echo "-l PASS"
else
    echo "-l FAIL"
fi


./s21_grep -c ^a ../tst3.txt > grep_test.txt
grep -c ^a ../tst3.txt > orig_grep_test.txt

if diff -q grep_test.txt orig_grep_test.txt; then
    echo "-c PASS"
else
    echo "-c FAIL"
fi


./s21_grep -n ^a ../tst3.txt > grep_test.txt
grep -n ^a ../tst3.txt > orig_grep_test.txt

if diff grep_test.txt orig_grep_test.txt; then
    echo "-n PASS"
else
    echo "-n FAIL"
fi


make clear
rm -f *.txt