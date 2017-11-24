fun length [] = 0
  | length (x::xs) = 1 + length xs; 
fun isPrefix x y =
    let
	val xl = length (explode x)
	val yl = length (explode y)
    in 
	if xl > yl then
	    false
	else if x = substring(y,0,xl) then
	    true
	else
	    false
	end;
