suml([],0):-!.
suml([H|T],S):-suml(T,S1),S is H+S1.
