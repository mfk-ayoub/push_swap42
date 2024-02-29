#!/bin/bash

# Define the number of blocks to display
num_blocks=30

# Define the delay between each frame (adjust as needed)
delay=0.1

# Function to display the loading animation
loading_animation() {
    local progress
    for ((progress = 1; progress <= num_blocks; progress++)); do
        printf "\r"
        printf "\e[38;5;154m█%.0s" $(seq 1 $progress)  # Lime color code: \e[38;5;154m
        printf "\e[0m"  # Reset color
        sleep $delay
    done
    printf "\n"
}

# Start the loading animation
loading_animation
