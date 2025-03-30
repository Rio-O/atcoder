(* Defining the shape of trees *)
(*多相二分木のocaml表現*)
type 'elm tree =
    Lf       (* Leaf *)
  | Br of {  (* Branch *)
      left:  'elm tree;
      value: 'elm;
      right: 'elm tree;
    }

type itree =
  Lf       (* Leaf *)
  | Br of {  (* Branch *)
      left:  tree;
      value: int;
      right: tree;
    }

let rec find(t, n) = match t with
  Lf -> false
  | Br{left=l; value = v; right = r} -> (if v = n then true 
      else if n < v then find(l, n)
      else find(r,n))

(* (Recursive) function insert, which, given BST t and a new element n, returns
   a new binary search tree with n *)
let rec insert(t, n) =
match t with
  Lf -> Br {left=Lf; value=n; right=Lf}
| Br {left=l; value=v; right=r} ->
    if n = v then t
    else if n < v then Br {left=insert(l, n); value=v; right=r}
    else (* n > v *)   Br {left=l; value=v; right=insert(r, n)}

(* Function min, which, given BST t, returns the minimum value stored in t.
   If t is empty, it returns min_int. *)
let rec min t =
match t with
  Lf -> min_int  (* The smallest representable integer, which is predefined *)
| Br {left=Lf; value=v; right=_} -> v
| Br {left=l ; value=_; right=_} -> min l

let rec delete(t, n) =
  match t with
    Lf -> t
  | Br {left=l; value=v; right=r} ->
     if n = v then
       match l, r with
         Lf,   Lf   -> Lf
       | Br _, Lf   -> l
       | Lf,   Br _ -> r
       | Br _, Br _ ->
          let m = min r in
          Br {left=l; value=m; right=delete(r, m)}
     else if n < v then Br {left=delete(l, n); value=v; right=r}
     else (* n > v *)   Br {left=l; value=v; right=delete(r, n)}