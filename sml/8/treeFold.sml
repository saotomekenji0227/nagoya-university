Control.Print.printDepth := 10;
Control.Print.stringDepth := 100;
Control.Print.printLength := 100;
datatype 'a tree =
	 Empty | Node of 'a * 'a tree * 'a tree;

fun treeFold f z Empty = z
  | treeFold f z (Node(x,L,R)) = f (x,treeFold f z L,treeFold f z R);

fun nodes T = treeFold (fn (x,y,z) => 1+y+z) 0 T;

fun mapTree f T = treeFold (fn(x,y,z) => Node(f x,y,z) ) Empty T;
