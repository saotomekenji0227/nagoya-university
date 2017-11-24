fun lowerchar [] = []
  | lowerchar (x::xs) = 
    let
	val c = Char.toLower x
	val cs = lowerchar xs
    in
	c::cs
    end;
fun lower s = 
    let
	val clist = explode s
	val t = lowerchar clist
    in
	implode t
    end;
fun upperchar [] = []
  | upperchar (x::xs) = 
    let
	val c = Char.toUpper x
	val cs = upperchar xs
    in
	c::cs
    end;
fun upper s =
    let
	val clist = explode s
	val t = upperchar clist
    in
	implode t
    end;
