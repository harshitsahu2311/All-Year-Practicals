insert(I,1,L,[I|L]).
insert(I,N,[H|T],[H|R]):- N1 is N-1,
			  insert(I,N1,T,R).
