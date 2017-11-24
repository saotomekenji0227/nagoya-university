fun absList [] = []
  | absList (x::xs) = if(x > 0) then x::(absList xs)
                      else ~x::(absList xs);
fun abblist [] = []
  | abblist (c::cs) = if((Char.isAlphaNum c) andalso not (Char.isLower c)) then
			  c::(abblist cs)
		      else 
			  abblist cs;
fun abbreviate s = implode (abblist (explode s));
