/* Bismillah hir-Rahman nir-Rahim

For any exit i 
    For any Monster j
        if dist(P,Ei) < min {(Dist(Mj,Ei) } 

Time complexity: 
    For all the monster first find short distance from Monster j to all the exit/ to all nodes
    -> takes O( x * (n * m));
    For the person , find  the short distance from P to every node;
    -> takes O(1 * (n * m));

    For Exit(i) -> takes 2*(n+m);
        if( Dist(p,Ei) < min(D(Mj,Ei))) ;

    Total T.C = O( ( (x+1) * (n*m) ) + 2*(n+m) + X );
                O (X * N * M + (2*N))

               Worst Case = O(n*n*m*m) = O(n^2*m^2)

?? MSSP  - Multi Source Shortest Path Problem
    !Q For every S find closest E
    Ansi = min j(Si,Ej);
    put all Ej in the queue of BFS with dist 0
    ! for our problem
    Dist(p,Ei) < min(D(Mj,Ei)) ;
    For every exit i we want the closest monster
    ..so we create super node of monsters
*/