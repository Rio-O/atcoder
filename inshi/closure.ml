let a = 2 in
let a = 0 in

let b = function x -> x + a in
(*closureの環境がa=0で固定*)

let a = 1 in

b 0;;