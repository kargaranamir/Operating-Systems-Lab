#!/bin/bash
mkdir -p $3

cp -r $1/* $3
echo "All $1 copied to $3"

cp -r $2/* $3
echo "All $2 copied to $3"

ls "./$3" | less
