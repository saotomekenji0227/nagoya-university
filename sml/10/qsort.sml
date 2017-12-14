Control.Print.printDepth := 10;
Control.Print.stringDepth := 100;
Control.Print.printLength := 100; 
fun time f arg =
    let
	val timer = Timer.startCPUTimer()
	val result = f arg
    in
	print (Real.toString(Time.toReal(#usr(Timer.checkCPUTimer timer))));
	print " sec.\n";
	result
    end;

fun fixedSeq (m,n) =
    let
        val seed = (Random.rand (0,1))
        fun randomI() = (Random.randInt seed) mod m
    in
        Array.tabulate (n, fn x=>randomI())
    end;

fun sortedSeq m = Array.tabulate(m,fn x => x+1);
	

fun swap (ar,i,j) =
    let 
	val iv = Array.sub(ar,i)
    in 
	(Array.update(ar,i,Array.sub(ar,j));
	 Array.update(ar,j,iv))
    end;

fun partition (ar,p,a,b) =
    let
	val av = Array.sub(ar,a);
	val bv = Array.sub(ar,b);
    in case ( b<=a, av<=p, p<bv )
	of  ( true , _, _) => if(av <= p)then a else a-1
	| ( _, true , _) => 
	  partition(ar,p,a+1,b)
	| ( _, _, true) => 
	  partition(ar,p,a,b-1)
	| ( _, _, _) => 
	  (swap(ar,a,b);partition(ar,p,a+1,b-1))
    end;

fun qsort (ar,i,j) =
    if j <= i then ()
    else let
	val pivot = Array.sub(ar,i);
	val k = partition(ar,pivot,i+1,j);
	val _ = swap(ar,i,k);
    in
	(qsort (ar,i,k-1); qsort(ar,k+1,j))
    end;

fun sort (ar) =
    qsort (ar,0,Array.length(ar)-1);

fun qsort' (ar,i,j) =
    if j <= i then ()
    else let
	val _ = swap(ar,i,((i+j) div 2));
	val pivot = Array.sub(ar,i);
	val k = partition(ar,pivot,i+1,j);
	val _ = swap(ar,i,k);
    in
	(qsort (ar,i,k-1); qsort(ar,k+1,j))
    end;

fun sort' (ar) =
    qsort' (ar,0,Array.length(ar)-1);

fun sortchecks (ar,i) =
    if(i = Array.length(ar)-1 ) then true
    else if i = 0 then sortchecks(ar,i+1)
    else if Array.sub(ar,i-1) <= Array.sub(ar,i) then sortchecks(ar,i+1)
    else false;

fun sortcheck (ar) = sortchecks (ar,0);
