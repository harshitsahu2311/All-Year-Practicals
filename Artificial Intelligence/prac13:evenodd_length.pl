leng([],0).
leng([H|T],R):-leng(T, F1), R is F1+1.
evenl(L):- leng(L, N), D is N mod 2, D == 0.
oddl(L):- leng(L,N), D is N mod 2, D==1.
