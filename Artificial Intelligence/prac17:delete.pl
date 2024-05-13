delete(1,[_|T],T).
delete(N,[X|T],[X|R]):- N<0 ,write('Enter Valid Num');
				 N1 is N-1,   
				delete(N1,T,R).       
