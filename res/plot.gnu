set terminal pngcairo size 1000,750 font "Arial,14"
set output "complexite.png"

set logscale xy
set grid lw 1.5 lc rgb "#E0E0E0"
set border lw 2                        
set xlabel "Nombre de mailles (N)" font "Arial,16,Bold"
set ylabel "Temps d'exécution (s)" font "Arial,16,Bold"
set title "Analyse de Complexité : Naïf vs Optimisé" font "Arial,18,Bold"
set key top left box lw 1.5            

k1 = 1.42 / (22528.0**2)
k2 = 0.0022 / 22528.0

plot "comparaison.txt" u 1:2 title "Naïf O(N^2)" w lp pt 7 ps 2 lw 3 lc rgb "#FF0000", \
     "comparaison.txt" u 1:3 title "Optimisé O(N)" w lp pt 7 ps 2 lw 3 lc rgb "#0000FF", \
     k1 * x**2 title "Pente théorique 2" lw 2 lc rgb "black" dt 2, \
     k2 * x    title "Pente théorique 1" lw 2 lc rgb "#606060" dt 4