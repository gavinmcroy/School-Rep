let rec exist elem lst =
  match lst with
  | [] -> -10000
  | hd::tl -> if(elem = hd) then 0 else 1 + exist elem tl;;

let rec first_duplicate lst =
  match lst with
   [] -> -10000
  | hd::tl -> if(exist hd tl >= -1) then List.nth tl (exist hd tl) else first_duplicate tl;;


let rec helper_2 = function
    ([], element, pre_list) -> if (List.mem (element) (pre_list)) then -10000 else element
    | (post_list, element, pre_list) -> if (List.mem (element) (post_list)) || (List.mem (element) (pre_list))
    then helper_2(List.tl post_list, List.hd post_list, element::pre_list)
    else element;;


let rec first_nonrepeating = function
    ([]) -> -10000
    | (hd::tl) -> helper_2(tl, hd, []);;


let rec sumOfTwo = function
    ([], _, _) -> false
    | (list1, list2, sum) -> if (List.mem (sum - (List.hd list1)) (list2))
    then true
    else sumOfTwo(List.tl list1, list2, sum);;


let rec helper_3 = function
    (og, num, list) -> if num < og -1 then helper_3(og, num+1, (og-num, num)::list)
    else (og-num, num)::list;;

let rec cyk_sublists = function
    (num) -> if num > 1 then helper_3(num, 1, []) else [];;
