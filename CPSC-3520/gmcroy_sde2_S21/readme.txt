Pledge: On my honor I have neither given nor received aid on this assignment

2.1
Prototype: first_duplicate of a list returns -10000 if there are no duplicates in the integer list argument.Otherwise the first item that occurs more than once (duplicate)in the integer list is returned.

Signature: val first_duplicate : int list -> int = <fun>

Sample Use:
# first_duplicate [1;2;3;4;5;6;7;4;5;8;9];;: int = 4
# first_duplicate [1;2;3;4;5;6;7;4;5;2;9];;: int = 2
# first_duplicate [1;2;3;4;5;6;7;8;9;10];;: int = -10000


2.2
Prototype: first_nonrepeating of a list returns -10000 if there are no non-repeated (non-duplicated) element in the list.Otherwise it returns the first non-repeating element in the integer list.

Signature: val first_nonrepeating : int list -> int = <fun>

Sample Use:
# first_nonrepeating [1;2;3;2;7;5;6;1;3];;: int= 7
# first_nonrepeating [1;2;9;3;2;7;5;6;1;3];;: int = 9
# first_nonrepeating [1;2;9;3;2;7;5;6;10;30];;: int = 1
# first_nonrepeating [1;2;9;3;2;7;5;6;1;10;30];;: int = 9


2.3
Prototype: sumOfTwo(a,b,v) returns false if there does not exist andi ntegerin a, which added to any integer in b, equals v.  If there is an integer in a, and an integer in b that sum to v, return true.

Signature: val sumOfTwo : int list * int list * int -> bool = <fun>

SampleUse:
# sumOfTwo([1;2;3],[10;20;30;40],42);;: bool = true
# sumOfTwo([1;2;3],[10;20;30;40],40);;: bool = false
# sumOfTwo([1;2;3],[10;20;30;40],41);;: bool = true
# sumOfTwo([1;2;3],[10;20;30;40],43);;: bool = true


Prototpe: cyk_sublists n returns all of the positive integer pairs x and y that add up to n.  Pairs are returned as tuples.  Argument n must be larger than 1, otherwise return []

2.4
Signature: 
val cyk_sublists : int -> (int * int) list = <fun>

Sample Use:# cyk_sublists 4;;: 
(int * int) list = [(1, 3); (2, 2); (3, 1)]
# cyk_sublists 3;; (int * int) list = [(1, 2); (2, 1)]
# cyk_sublists 5;; (int *int) list = [(1, 4); (2, 3); (3, 2); (4, 1)]
# cyk_sublists(6);; (int * int) list = [(1, 5); (2, 4); (3, 3); (4, 2); (5, 1)]