#!/bin/bash
mkdir -p $3

cp -r $1/* $3
echo "All $1 files copied to $3"

cp -r $2/* $3
echo "All $2 files copied to $3"

