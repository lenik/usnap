#!/bin/bash

for big in */*80.png; do
    stem="${big%80.png}"
    for size in 64 32; do
        small="$stem$size.png"
        convert -resize "${size}x${size}" "$big" "$small"
    done
done
