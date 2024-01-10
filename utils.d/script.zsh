#!/bin/bash

# Check the operating system
if [[ $(uname -s) == "Darwin" ]]; then
    brew install readline
elif [[ $(uname -s) == "Linux" ]]; then
    sudo apt install libreadline-dev
else
    echo "Unsupported operating system"
    exit 1
fi

make 