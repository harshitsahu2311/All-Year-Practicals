merge([],L2,L2).
merge(L1,[],L1).
merge([H1|T1],[H2|T2],[H1|T3]):-H1 =< H2, merge(T1,[H2|T2],T3).
merge([H1|T1],[H2|T2],[H2|T3]):-H1>H2, merge([H1,T1],T2,T3).
