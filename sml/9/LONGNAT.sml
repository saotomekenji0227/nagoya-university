signature LONGNAT = sig
    exception NegativeLongNat
    exception IllegalLongNat
    type longnat
	     
    val fromIntList : int list -> longnat
    val toString : longnat -> string
    val inc : longnat -> longnat
    val dec : longnat -> longnat
    val add : longnat * longnat -> longnat
end

structure LongNat :> LONGNAT = struct
exception NegativeLongNat
exception IllegalLongNat
type longnat = int list
		   
(* 各要素の最大値 *)
val emax = 9999
(* 各要素の最大桁数 = size (Int.toString emax) *)
val edigit = 4
	 
(* int list から longnat を生成する *)
fun fromIntList [0] = []
  | fromIntList l = 
    if List.all (fn x => x >=0 andalso x <= emax) l
    then l
    else raise IllegalLongNat
 
(* longnat を文字列に変換する *)
fun toString lnat =
    if null lnat then "0" else
    let
	val revlnat = rev lnat
        (* "0" を追加して桁をそろえる *)
	fun padding0 x =
	    let
		val xstr = Int.toString x
		val num0 = edigit - (size xstr)
		fun numstring (n,s) = if n < 1 then ""
				      else s ^ (numstring (n - 1, s))
	    in
		numstring(num0, "0") ^ xstr
	    end
    in
	Int.toString (hd revlnat) ^ concat (map padding0 (tl revlnat))
    end
(* 関数 inc, dec, add の定義を追加する *)

fun inc [] = [1]
  | inc (x::L) = if x = emax then 0::(inc L)
		 else (x+1)::L

fun dec [] = raise NegativeLongNat
  | dec [1] = []
  | dec (x::L) = if x = 0 then emax::(dec L)
		 else (x-1)::L
fun addc ([],[],0) = []
  | addc ([],[],c) =[c]
  | addc (x::xL,[],c) = if x+c > emax then 0::(addc (xL,[],c))
			else (x+c)::xL
  | addc ([],y::yL,c) = if y+c > emax then 0::(addc ([],yL,c))
			else (y+c)::yL
  | addc (x::xL,y::yL,c) = if x+y+c > emax then (x+y+c-emax-1)::(addc (xL,yL,1))
			   else (x+y+c)::(addc (xL,yL,0))

fun add (x,y) = addc (x,y,0)

end
