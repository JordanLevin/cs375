#!/bin/bash

for value in ./tests/*.txt
do
    ./BestFirstSearch $value ./outputs/${value#*/*/}
    ./other $value ./outputs/s${value#*/*/}
done
