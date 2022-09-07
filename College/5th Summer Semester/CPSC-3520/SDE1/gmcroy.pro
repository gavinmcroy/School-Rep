%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ECE3520/CpSc3520 SDE1: Prolog Declarative and Logic Programming

% Use the following Prolog relations as a database of familial 
% relationships for 4 generations of people.  If you find obvious
% minor errors (typos) you may correct them.  You may add additional
% data if you like but you do not have to.

% Then write Prolog rules to encode the relations listed at the bottom.
% You may create additional predicates as needed to accomplish this,
% including relations for debugging or extra relations as you desire.
% All should be included when you turn this in.  Your rules must be able
% to work on any data and across as many generations as the data specifies.
% They may not be specific to this data.

% Using SWI-Prolog, run your code, demonstrating that it works in all modes.
% Log this session and turn it in with your code in this (modified) file.
% You examples should demonstrate working across 4 generations where
% applicable.

% Fact recording Predicates:

% list of two parents, father first, then list of all children
%parent_list(?Parent_list,?Child_list).

% Data:

parent_list([fred_smith, mary_jones],
            [tom_smith, lisa_smith, jane_smith, john_smith]).

parent_list([tom_smith, evelyn_harris],
            [mark_smith, freddy_smith, joe_smith, francis_smith]).

parent_list([mark_smith, pam_wilson],
            [martha_smith, frederick_smith]).

parent_list([freddy_smith, connie_warrick],
            [jill_smith, marcus_smith, tim_smith]).

parent_list([john_smith, layla_morris],
            [julie_smith, leslie_smith, heather_smith, zach_smith]).

parent_list([edward_thompson, susan_holt],
            [leonard_thompson, mary_thompson]).

parent_list([leonard_thompson, lisa_smith],
            [joe_thompson, catherine_thompson, john_thompson, carrie_thompson]).

parent_list([joe_thompson, lisa_houser],
            [lilly_thompson, richard_thompson, marcus_thompson]).

parent_list([john_thompson, mary_snyder],
            []).

parent_list([jeremiah_leech, sally_swithers],
            [arthur_leech]).

parent_list([arthur_leech, jane_smith],
            [timothy_leech, jack_leech, heather_leech]).

parent_list([robert_harris, julia_swift],
            [evelyn_harris, albert_harris]).

parent_list([albert_harris, margaret_little],
            [june_harris, jackie_harrie, leonard_harris]).

parent_list([leonard_harris, constance_may],
            [jennifer_harris, karen_harris, kenneth_harris]).

parent_list([beau_morris, jennifer_willis],
            [layla_morris]).

parent_list([willard_louis, missy_deas],
            [jonathan_louis]).

parent_list([jonathan_louis, marsha_lang],
            [tom_louis]).

parent_list([tom_louis, catherine_thompson],
            [mary_louis, jane_louis, katie_louis]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SWE1 Assignment - Create rules for:

%%HELPFUL rules
male(X) :- 
	parent_list([X|_], _).

female(Y) :- 
	parent_list([_|Y],_).

child(X,Y) :- 
	parent(Y,X).




%[Parent,Child] W
parent(P, C) :- 
	parent_list(Plist, Clist), 
	member(P, Plist), 
	member(C, Clist).

%[Husband,Wife] W
 married(X, Y) :-
   child(Z, X), !,
   child(Z, Y),
   X \= Y.

%[Ancestor, Person] W
ancestor(A, P) :-
	parent(A,P).
	
ancestor(X,Y) :- %W
    parent(X, Z),
    ancestor(Z, Y).


%[Decendent,Person] W
 descendent(D, P) :- 
 	ancestor(P,D).

%[Person1,Person2,Ancestor] W
common_ancestor(A, B, C) :-
	ancestor(C,A),
	ancestor(C,B).

%[Person1,Person2] F/P
blood(X, Y) :-
	ancestor(Z, X),
    ancestor(Z, Y).
   


%[Person1,Person2] /* F/P TODO Rule prints twice?*/
sibling(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

%[Father,Child] W
father(F, C) :- 
	parent(F, C), 
	male(F).

%[Mother,Child]	% F /*TODO does not work since female does not work*/
 mother(M, C) :- 
 	parent(M, C), 
	female(M). 

%[Uncle,Person]  
brother(X,Y) :- 
	sibling(X,Y),
	male(X),
 	X \= Y.
	
uncle(X,Y) :- % F/P /*Will only find one uncle */.
	brother(X, Y).
uncle(X,Y) :- 
	brother(X, Z),
	child(Y,Z).

%[Aunt,Person] % F /*Cannot determine females but if it did it would find one aunt */
sister(X, Y) :-
    sibling(X, Y),
    female(X),
    X \= Y.
	
aunt(X, Y) :-
    sister(X, Z),
    child(Y, Z). % F

%[Cousin,Person]
grandparent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

cousin(X, Y) :- % F/P It finds some cousins but not all
	father(Z,X), 
	father(W,Y), 
	brother(Z,W).
	%parent(Z,X), parent(W,Y), sibling(Z,W).

%% 1st cousin, 2nd cousin, 3rd once removed, etc. %Unable to get functioning 

% cousin_type(+Person1, +Person2, -CousinType, -Removed).

greatgrandparent(X, Y) :-
    parent(Z, Y),
    grandparent(X, Z).
secondcousin(X, Y) :-
    greatgrandparent(Z, X),
    greatgrandparent(Z, Y),
    \+sibling(X, Y),
    \+cousin(X, Y),
    X \= Y.

