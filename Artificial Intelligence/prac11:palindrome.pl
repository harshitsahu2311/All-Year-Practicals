palin(L2,L2).
palin(L2,[H|L2]).
palin([H|T],T2):- palin(T,[H|T2]).
palindrome(L):- palin(L,T2).
