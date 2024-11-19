#!/bin/bash
blink_counter=0
# Setting segments for digits
display_digit() {
    digit=$1
    i=$2
    if [ $i -eq 0 ]; then
        case $digit in
            0) echo -n "  ---  ";;
            1) echo -n "   .   ";;
            2) echo -n "  ---  ";;
            3) echo -n "  ---  ";;
            4) echo -n " .   . ";;
            5) echo -n "  ---  ";;
            6) echo -n "  ---  ";;
            7) echo -n "  ---  ";;
            8) echo -n "  ---  ";;
            9) echo -n "  ---  ";;
        esac
    elif [ $i -eq 1 ]; then
        case $digit in
            0) echo -e -n " |   | ";;
            1) echo -e -n "   |   ";;
            2) echo -e -n "     | ";;
            3) echo -e -n "     | ";;
            4) echo -e -n " |   | ";;
            5) echo -e -n " |     ";;
            6) echo -e -n " |     ";;
            7) echo -e -n "     | ";;
            8) echo -e -n " |   | ";;
            9) echo -e -n " |   | ";;
        esac
    elif [ $i -eq 2 ]; then
        case $digit in
            0) echo -n " |   | ";;
            1) echo -n "   |   ";;
            2) echo -n "  ---  ";;
            3) echo -n "  ---  ";;
            4) echo -n "  ---| ";;
            5) echo -n "  ---  ";;
            6) echo -n "  ---  ";;
            7) echo -n "     | ";;
            8) echo -n "  ---  ";;
            9) echo -n "  ---  ";;
        esac
    elif [ $i -eq 3 ]; then
        case $digit in
            0) echo -n " |   | ";;
            1) echo -n "   |   ";;
            2) echo -n " |     ";;
            3) echo -n "     | ";;
            4) echo -n "     | ";;
            5) echo -n "     | ";;
            6) echo -n " |   | ";;
            7) echo -n "     | ";;
            8) echo -n " |   | ";;
            9) echo -n "     | ";;
        esac
    elif [ $i -eq 4 ]; then
        case $digit in
            0) echo -n "  ---  ";;
            1) echo -n "   .   ";;
            2) echo -n "  ---  ";;
            3) echo -n "  ---  ";;
            4) echo -n "     . ";;
            5) echo -n "  ---  ";;
            6) echo -n "  ---  ";;
            7) echo -n "     . ";;
            8) echo -n "  ---  ";;
            9) echo -n "  ---  ";;
        esac
    fi
}

# Function to print the colon
display_colon() {
    i=$1
    if [ $i -eq 0 ]; then
        echo -n "       "
    elif [ $i -eq 1 ]; then
        if [ $((blink_counter % 2)) -eq 0 ]; then
            echo -n "   o   "
        else
            echo -n "       "
        fi
    elif [ $i -eq 2 ]; then
        echo -n "       "
    elif [ $i -eq 3 ]; then
        if [ $((blink_counter % 2)) -eq 0 ]; then
            echo -n "   o   "
        else
            echo -n "       "
        fi
    elif [ $i -eq 4 ]; then
        echo -n "       "
    fi
}

# Loop forever
while true; do
    clear


    # Get current date and time
    datetime=$(date +"%A %d %B %Y %I %M %S %p %Z")

    # Extract different fields
    read -r day date month year hour minute second ampm timezone <<< $datetime


    clock_height=8
    clock_width=64

    terminal_height=$(tput lines)
    terminal_width=$(tput cols)

    spaces=$(((terminal_width - clock_width)/2))
    lines=$(( (terminal_height - clock_height) / 2 ))


    for ((l=0; l<lines; l++))do
        echo
    done

    for ((l=0; l<spaces; l++))do
        echo -n " "
    done

    # Print the date as a string
    echo "$day $date $month $year"

    for ((l=0; l<spaces; l++))do
        echo -n " "
    done

    echo -n "+"
    for ((i=0;i<$((clock_width - 2));i++))do
        echo -n "-"
    done
    echo "+"

    for ((i=0; i<5; i++))do
        for ((l=0; l<spaces; l++))do
            echo -n " "
        done
        echo -n "|  "
        for ((j=0; j<${#hour}; j++)); do
            display_digit "${hour:$j:1}" "$i"
        done
        display_colon "$i"
        for ((j=0; j<${#minute}; j++)); do
            display_digit "${minute:$j:1}" "$i"
        done
        display_colon "$i"
        for ((j=0; j<${#second}; j++)); do
            display_digit "${second:$j:1}" "$i"
        done
        if [ $i != 4 ]; then
            echo "    |"
        fi
        ((blink_counter++))
    done

    echo "$ampm  |"

    for ((l=0; l<spaces; l++))do
        echo -n " "
    done

    echo -n "+"
    for ((i=0;i<$(((5*12)+2));i++))do
        echo -n "-"
    done
    echo "+"

    # Wait for the user to hit return
    read -t 0.5 -r && break
done