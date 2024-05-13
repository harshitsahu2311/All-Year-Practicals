gcd(0,Y,Y).
gcd(X,0,X).
gcd(X,X,X).
gcd(Y,Y,Y).
gcd(X,Y,G):- X>Y, R is X-Y,gcd(R,Y,G).
gcd(X,Y,G):-Y>0,Y>X, R is Y-X,gcd(X,R,G), write(G).
