type id = string
type binOpM = Plus | Mult
type binOpB = Eq
type exp = Var of id
| ILit of int
| BLit of bool
|BinOpM of binOpM * exp * exp
|BinOpB of binOpB * exp * exp
|LetExp of id * exp * exp
|IfExp of exp * exp * exp

type env = 
| Nil
| Lis of id * exp * env

exception Invalidtype
exception NotFound

let rec lookup env x = match env with
Nil -> raise Invalidtype
| Lis(id, exp, e2) -> (if id = x then exp else lookup e2 x)

let add env id exp = match env with
Nil -> Lis(id, exp, Nil)
| Lis(i1, e1, e2) -> Lis(id, exp, env)


let calcm(BinOpM(op, i1, i2))= match op with
Plus -> (match i1, i2 with ILit k1, ILit k2 -> let k = k1 + k2 in ILit k
          | _ -> raise Invalidtype)
| Mult -> (match i1, i2 with ILit k1, ILit k2 -> let k = k1 * k2 in ILit k
          | _ -> raise Invalidtype)

let rec eval_exp env = function
Var x -> (try (lookup env x) with _ -> raise NotFound)
| ILit i -> ILit i
| BLit b -> BLit b
| BinOpM (op, exp1, exp2) -> let arg1 = eval_exp env exp1 in
      let arg2 = eval_exp env exp2 in 
      calcm (BinOpM(op, arg1, arg2))

|LetExp(id, exp1, exp2) -> let arg1 = eval_exp env exp1 in
  eval_exp (add env id arg1) exp2
|IfExp(exp1, exp2, exp3) -> let arg1 = eval_exp env exp1 in (match arg1 with
  BLit true -> eval_exp env exp2
  |BLit false -> eval_exp env exp3
  | _ -> raise Invalidtype)

(*moduleの話*)
module Sample =
  struct
    let z t = t + 1
    let y x = x + 2
  end

module type S2WITHOUT_Y =
  sig
    (*type t  = Lf | Br of {left: t; value: int; right: t}*)
    type t
    val z : t -> string
    val y : int -> int
  end

module S2 : S2WITHOUT_Y =
  struct
    type t = Lf | Br of {left: t; value: int; right: t}
    let z t = match t with Lf -> "leaf" | Br{left = l; value = v; right = r} -> "tree"
    let y x = x + 2
  end
