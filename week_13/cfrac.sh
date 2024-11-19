#!/bin/bash

# Function to evaluate a continued fraction represented by an array
evalcfrac() {
    local -a A=("$@")
    local n=${#A[@]}

    local p=1 q=${A[n-1]} r=0 s=1

    for ((i=n-2; i>=0; i--)); do
        local temp_p=$((A[i] * q + p))
        local temp_q=$q

        p=$q
        q=$temp_p

        r=$s
        s=$temp_q
    done

    echo "The continued fraction evaluates to $q / $p = $(bc -l <<< "scale=10; $q / $p")"
}

# Function to generate continued fraction expansion of a fraction
gencfrac() {
    read -p "Enter fraction (a / b). Enter the numbers as (a b) : " a b
    echo -n "The continued fraction expansion of $a / $b is: "

    local arr=()

    while [ $b -ne 0 ]; do
        local quotient=$((a / b))
        local remainder=$((a % b))

        arr+=("$quotient")
        a=$b
        b=$remainder
    done

    echo "${arr[@]}"
}

read -p "Enter the array of coefficients: " -a A
evalcfrac "${A[@]}"
gencfrac

