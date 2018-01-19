signature PRINT =
sig
    val printError : string -> unit
    val printIntList : int list -> unit
    val printIntListList : int list list -> unit
    val printStringList : string list -> unit
    val printIntArray : int array -> unit
    val printIntListArray : int list array -> unit
    val printStrInt : string -> int -> unit
    val printStrIntInf : string -> IntInf.int -> unit
    val printStrIntNonl : string -> int -> unit
    val printBoolArray : bool array -> unit
    val printResult : TextIO.outstream -> int list -> unit
end

structure Print : PRINT =
struct
local 
      open Array TextIO
in

(* ��å�������ɸ�२�顼���Ϥ˽��Ϥ��� *)
fun printError s = output(stdErr,s)

(* �����Υꥹ�Ȥ�ɸ����Ϥ˽��� *)
fun printIntListElem [] = print ""
  | printIntListElem [h] = print ((Int.toString h))
  | printIntListElem (h :: t) = (print ((Int.toString h) ^ ",");
			     printIntListElem t
			     )
fun printIntList l = (print "[";printIntListElem l;print "]\n")

(* �����Υꥹ�ȤΥꥹ�Ȥ�ɸ����Ϥ˽��� *)
fun printIntListListElem [] = print ""
  | printIntListListElem (h :: t) = (print "[";
				     printIntListElem h;
				     print "]";
				     printIntListListElem t
				     )
fun printIntListList l = (print "[";printIntListListElem l;print "]\n")

(* �����������ɸ����Ϥ˽��� *)
fun printIntArray ar =
    let
	val size = length(ar)
	fun prArrayN k =
	    if k < size - 1 then
		(print (Int.toString(sub(ar,k)) ^ ",");
		 prArrayN (k+1)
		 )
	    else 
		if k < size then
		    print (Int.toString(sub(ar,k)))
		else print ""
    in
	(print "[|";
	 prArrayN 0;
	 print "|]\n"
	 )
    end

(* �����ͤ������ɸ����Ϥ˽��� *)
fun printBoolArray ar =
    let
	val size = length(ar)
	fun boolString b = if b then "True" else "False"
	fun prArrayN k =
	    if k < size - 1 then
		(print (boolString(sub(ar,k)) ^ ",");
		 prArrayN (k+1)
		 )
	    else 
		if k < size then
		    print (boolString(sub(ar,k)))
		else print ""
    in
	(print "[|";
	 prArrayN 0;
	 print "|]\n"
	 )
    end

(* �����Υꥹ�Ȥ������ɸ����Ϥ˽��� *)
fun printIntListArray ar =
    let
	val size = length(ar)
	fun prListArrayN k =
	    if k < size - 1 then
		(print "[";
		 printIntListElem (sub(ar,k));
		 print "],";
		 prListArrayN (k+1)
		 )
	    else 
		if k < size then
		    (print "[";
		     printIntListElem (sub(ar,k));
		     print "]"
		     )
		else print ""
    in
	(print "[|";
	 prListArrayN 0;
	 print "|]")
    end

(* ʸ����Υꥹ�Ȥ����Ǥ򥳥�ޤǶ��ڤä�ɸ����Ϥ˽��� *)
fun printStringList [] = ()
  | printStringList [h] = (print h; print "\n")
  | printStringList (h :: t) = (print h; print ","; printStringList t)

(* ʸ����������ɸ����Ϥ˽��� *)
fun printStrInt s i = print (s ^ (Int.toString i) ^ "\n")

(* ʸ����IntInf ��ɸ����Ϥ˽��� *)
fun printStrIntInf s i = print (s ^ (IntInf.toString i) ^ "\n")

(* ʸ����������ɸ����Ϥ˽��Ϥ������Ԥ��� *)
fun printStrIntNonl s i = print (s ^ (Int.toString i) ^ " ")

(* ������ʸ������Ѵ� *)
(* ���� "-" �ˤ���  *)
fun intToString n = 
    if n < 0 then "-"^(Int.toString(~n)) 
    else Int.toString n

(* �ѿ��γ�����Ƥ�ɽ�� *)
(* �Ǹ�� 0 �����      *)
fun printResult outs rl =
    let
	fun pr [] k = output (outs, "0\n")
	  | pr (h :: t) k =
	    (output (outs, intToString(h * k));
	     output (outs, " ");
	     pr t (k+1))
    in
	pr rl 1
    end

(* ����ѿ�������Ƥ���� *)
fun printClauseValue cl vval =
    let
	val cllen = length cl
	fun pcv  cl n =
	    if n >= cllen then print "\n"
	    else
		let
		    val v = sub(cl,n)
		    val vid = abs v
		    val vv = sub(vval, vid)
		in
		    (print ((Int.toString vid) ^ ":" ^ (Int.toString vv) ^ " ");
		     pcv cl (n+1))
		end
    in
	pcv cl 0
    end

end

end
