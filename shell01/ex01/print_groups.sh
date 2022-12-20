#!/usr/bin/env zsh
#https://askubuntu.com/a/205698

id -Gn $FT_USER | tr '[[:blank:]]/' ',' | tr -d '\n'
