type id = string
type binOp = Plus | Mult
type exp = Var of id
| ILit of int
| BinOp of binOp * exp * exp

let rec simplify = function
Var x -> Var x
| ILit i -> ILit i
| BinOp (op, exp1, exp2) -> 
  let arg1 = simplify exp1 in
  let arg2 = simplify exp2 in
  if arg1= ILit 0 then ( if op=Mult then ILit 0 else arg2 )
  else if arg2=ILit 0 then ( if op=Mult then ILit 0 else arg1 )
  else BinOp( op, arg1, arg2)
  (*if op = Mult then (if arg1 = ILit 0 || arg2 = ILit 0 then ILit 0)
  else if arg1 = ILit 0 then arg2
  else if arg2 = ILit 0 then arg1
  else BinOp(op, arg1, arg2)*)


let rec simp2 = function
  Var x -> Var x
  | ILit i -> ILit i
  | BinOp (op, exp1, exp2) -> 
    let arg1 = simp2 exp1 in
    let arg2 = simp2 exp2 in
    (match op with
    Plus -> (match arg1 with ILit 0 -> arg2 | _ -> (match arg2 with ILit 0 -> arg1 | _ -> BinOp(op, arg1, arg2)))
    | Mult -> (match arg1, arg2 with 
            ILit 0, _ -> ILit 0 
            | _, ILit 0 -> ILit 0 
            | _,_ -> BinOp(op, arg1, arg2)))