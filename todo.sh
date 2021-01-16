#!/bin/bash
function todo {
case $1 in
add | a)
echo $2>> ./code/todo.txt
;;
rem | remove | del)
sed -i "$2d" ./code/todo.txt
;;
"")
cat -n ./code/todo.txt
;;
esac
}
