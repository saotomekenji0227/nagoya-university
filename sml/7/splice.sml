fun splice ([],s) = ""
  | splice ((x::[]),s) =x 
  | splice ((x::xs),s) = x^s^splice(xs,s);
