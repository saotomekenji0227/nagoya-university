#set term X11
set term postscript portrait
set output '081531257saotomekenji.ps'
set title "081531257saotomekenji.ps"  
set size 1.0, 0.7
set xlabel "X"
set ylabel "Y"
set xtics -1, 0.5
set ytics -1, 0.5
set zeroaxis
plot [-2:2][-2:2] 'ex4.2.1.dat' title 'y=p8' with dots,'ex4.2.2.dat' title 'y=p10' with dots,'ex4.2.3.dat' title 'y=f(x)' with dots
#plot [-4:4][-5:5] 'data1.dat' title 'data 1' with points,'data2.dat' title 'data 2' with points 
