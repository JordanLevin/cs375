#!/bin/bash

for value in input*.txt
do
    echo $value
    diff $value s$value
done
