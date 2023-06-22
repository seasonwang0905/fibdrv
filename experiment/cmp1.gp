reset
set ylabel 'time(ns)'
set title 'fib algor cmp'
set key left top
set term png enhanced font 'Verdana,10'
set output 'cmp1.png'
plot [2:92][:] \
'cmp1.out' using 1:2 with linespoints linewidth 2 title "repeated addition",\
'' using 1:3 with linespoints linewidth 2 title "double fib1",\
'' using 1:4 with linespoints linewidth 2 title "double fib2",\