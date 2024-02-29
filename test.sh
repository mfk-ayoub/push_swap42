#!/bin/bash


num_blocks=30
delay=0.1
loading_animation() {
    local progress
    for ((progress = 1; progress <= num_blocks; progress++)); do
        printf "\r"
        printf "\e[38;5;154m█%.0s" $(seq 1 $progress)
        printf "\e[0m" 
        sleep $delay
    done
    printf "\n"
}
loading_animation
