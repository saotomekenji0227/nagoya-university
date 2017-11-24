fun sumList [] = 0
  | sumList (x::xs) = x + (sumList xs);

fun member x [] = false
  | member x (y::ys) = (x = y) orelse (member x ys); 

fun unique [] = []
  | unique (x::xs) =  if (member x (unique xs)) then unique xs
		      else x::(unique xs);

fun filter P [] = []
  | filter P (x::xs) = if (P x) then x::(filter P xs)
                       else filter P xs;
