#!/bin/bash


ARG="$1"

./push_swap $ARG | ./checker_linux $ARG
