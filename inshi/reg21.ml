(* レジスタ番号 *)
type num = Z|I|II|III
(* (num*int)list でレジスタを表現 *)

(* aレジスタにnの値を格納　*)
let rec insert env a n =
   match env with
    [] -> []
    |(r,v)::rest -> if r=a then (r,n)::rest else (r,v)::(insert rest a n)

(* aレジスタの値を返す *)
let rec find env a = match env with (r,n)::rest -> if r=a then n else find rest a

(* レジスタbにaをコピー *)
let rec copy env a b = let n = find env a in insert env b n

(* aレジスタの値を1増やす　*)
let rec inc env a = match env with (r,n)::rest -> if r=a then (r,n+1)::rest else (r,n)::(inc rest a)

(* aレジスタの値を1減らす *)
let rec dec env a = match env with (r,n)::rest -> if r=a then (r,n-1)::rest else (r,n)::(dec rest a)

(*　命令型　*)
type i = 
  Copy of num * num
 |Inc of num
 |Dec of num

(* 長さ0以上の命令列を表現　*)
type is =
 End
 | Return
 | Whip of num * is * is (* whilepos num [ is ] is *)
 | Seq of i*is (* i; is..; *)

(* 評価値型:レジスタ環境か整数値 *)
type exval = Ans of int | E of (num*int)list

(* 命令を評価してレジスタ環境を返す　*)
let rec exec env i = match i with 
  Copy(a,b)-> E (copy env a b)
 |Inc a -> E (inc env a)
 |Dec a -> E (dec env a)

(* レジスタ環境:enviと命令列:isを受け取って命令列の値を評価　*)
let rec eval_exp envi is = match envi with E env ->( match is with
   Seq(i,is) -> eval_exp (exec env i) is
 | Return -> Ans (find env Z) (* ぜろレジスタの値を返す　*)
 | Whip(num, is1, is2) ->(
      if (find env num)>0 then
          let newenv = eval_exp (E env) is1 in
          eval_exp newenv (Whip(num, is1, is2))
      else eval_exp (E env) is2 )
 | End -> envi
)
|_-> envi