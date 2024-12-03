#!/bin/bash

make s21_cat
./s21_cat ../tst3.txt > cat_test.txt
cat ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "PASS"
else
    echo "FAIL"
fi


./s21_cat -e ../bytes.txt > cat_test.txt
cat -e ../bytes.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "-e PASS"
else
    echo "-e FAIL"
fi


./s21_cat -t ../bytes.txt > cat_test.txt
cat -t ../bytes.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "-t PASS"
else
    echo "-t FAIL"
fi


./s21_cat -n ../tst3.txt > cat_test.txt
cat -n ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "-n PASS"
else
    echo "-n FAIL"
fi


./s21_cat -b ../tst3.txt > cat_test.txt
cat -b ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "-b PASS"
else
    echo "-b FAIL"
fi


./s21_cat -E ../tst3.txt > cat_test.txt
cat -E ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "-E PASS"
else
    echo "-E FAIL"
fi


./s21_cat -T ../tst3.txt > cat_test.txt
cat -T ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "-T PASS"
else
    echo "-T FAIL"
fi


./s21_cat -s ../tst3.txt > cat_test.txt
cat -s ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "-s PASS"
else
    echo "-s FAIL"
fi


./s21_cat --number-nonblank ../tst3.txt > cat_test.txt
cat --number-nonblank ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "--number-nonblank PASS"
else
    echo "--number-nonblank FAIL"
fi


./s21_cat --number ../tst3.txt > cat_test.txt
cat --number ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "--number PASS"
else
    echo "--number FAIL"
fi


./s21_cat --squeeze-blank ../tst3.txt > cat_test.txt
cat --squeeze-blank ../tst3.txt > orig_cat_test.txt

if diff -q cat_test.txt orig_cat_test.txt; then
    echo "--squeeze-blank PASS"
else
    echo "--squeeze-blank FAIL"
fi


make clear
rm -f *.txt