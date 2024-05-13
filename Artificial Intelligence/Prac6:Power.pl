

power(_,0,1).
power(N,1,N).

power(N,P,R):-P>0,P1 is P-1,power(N,P1,R1),R is N*R1.
