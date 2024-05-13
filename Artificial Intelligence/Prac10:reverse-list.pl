conc([],L,L).
conc([H|T],L2,[H|R]):-conc(T,L2,R).
reverse([],[]).
reverse([H|T],R):-reverse(T,R1),conc(R1,[H],R).
