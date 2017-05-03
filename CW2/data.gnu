set nokey 
set boxwidth 0.3
set style fill solid 1.00 
set title "Benchmarking sorting algorithms"
set ylabel "Time(seconds)"
set tic scale 0
plot "data.out" using 2:xtic(1) with boxes lt rgb "#DAA520"