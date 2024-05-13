fibonacci(0,1).
fibonacci(1,1).
fibonacci(N,T):- N>1,N1 is (N-1),fibonacci(N1,R1),N2 is (N-2),fibonacci(N2,R2), T is (R1+R2).
