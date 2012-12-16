set logscale x
set logscale y
set term png
set output 'nameblocking.png'
plot 'data/hist_lastname_firstname.txt', 'data/hist_lastname.txt', 'data/hist_lastname_firstinitial.txt'

set term svg
set output 'nameblocking.svg'
replot

set xrange [1:100]
set yrange [1:1e+07]
set term png
set output 'onetohundred.png'
replot

set term svg
set output 'onetohundred.svg'
replot

set xrange [1:50]
set yrange [100:1e+07]
set term png
set output 'onetofifty.png'
replot

set term svg
set output 'onetofifty.svg'
replot

