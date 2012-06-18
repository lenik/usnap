#!/bin/bash

for f in "$@"; do
    while IFS=, read type snd rem; do
        case "$type" in
        Q)
            echo -n $snd $rem
            ;;
        A)
            echo ",$snd,$rem"
            ;;
        *)
            echo "Bad: $type $snd $rem" >&2
            ;;
        esac
    done < "$f"
done
