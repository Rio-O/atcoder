(*抽象データ型*)
module type ABSTRACT_BST_VER1 =
  sig
    type t
    val find : t * int -> bool
    val insert : t * int -> t
    val delete : t * int -> t
  end;;