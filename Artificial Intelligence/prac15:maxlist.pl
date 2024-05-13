maxlist([],0):-!.
maxlist([H|T],M):-maxlist(T,R),(H>=R->M is H;M is R).
