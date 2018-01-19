[作成課題 課題4.1]該当プログラム
	fun flipVar 0 = (0, [])
		  | flipVar n =
		    if(sub(varFlipped,n) = true) then
			flipVar (n-1)
		    else
			(update(varFlipped,n,true);(n,(~(hd(sub(assignStack,n))))::[]))
[作成課題 課題4.1]実行結果
- Nplsat.nplsat ("", ["test3_1.cnf"]);
Number of variables = 4
Number of clauses = 4
[~1,2]
[~2]
[1,2,~3,4]
[~4]
deduce at decision level 1
implicationQueue: [~1]
setVarValue 1 ~1
varValues: [|0,~1,0,0,0|]
clNumT: [|1,0,0,0|]
clNumF: [|0,0,1,0|]
conflicts: []
varDecLevel: [|~1,1,~1,~1,~1|]
assignStack at decision level 1 [~1]
deduce at decision level 2
implicationQueue: [~2]
setVarValue 2 ~1
varValues: [|0,~1,~1,0,0|]
clNumT: [|1,1,0,0|]
clNumF: [|1,0,2,0|]
	    conflicts: []
varDecLevel: [|~1,1,2,~1,~1|]
assignStack at decision level 2 [~2]
deduce at decision level 3
implicationQueue: [~3]
setVarValue 3 ~1
varValues: [|0,~1,~1,~1,0|]
clNumT: [|1,1,1,0|]
clNumF: [|1,0,2,0|]
conflicts: []
varDecLevel: [|~1,1,2,3,~1|]
assignStack at decision level 3 [~3]
deduce at decision level 4
implicationQueue: [~4]
setVarValue 4 ~1
varValues: [|0,~1,~1,~1,~1|]
clNumT: [|1,1,1,1|]
clNumF: [|1,0,3,0|]
conflicts: []
varDecLevel: [|~1,1,2,3,4|]
assignStack at decision level 4 [~4]
Decisions: 5
Conflicts: 0
Implications: 4
SATISFIABLE
-1 -2 -3 -4 0
Computation time is 1msec.
val it = 0 : OS.Process.status
- Nplsat.nplsat ("", ["test3_2.cnf"]);
Number of variables = 3
Number of clauses = 4
[~1,2]
[3]
[~2,~3]
[1,3]
deduce at decision level 1
implicationQueue: [~1]
setVarValue 1 ~1
varValues: [|0,~1,0,0|]
clNumT: [|1,0,0,0|]
clNumF: [|0,0,0,1|]
conflicts: []
varDecLevel: [|~1,1,~1,~1|]
assignStack at decision level 1 [~1]
deduce at decision level 2
implicationQueue: [~2]
setVarValue 2 ~1
varValues: [|0,~1,~1,0|]
clNumT: [|1,0,1,0|]
clNumF: [|1,0,0,1|]
conflicts: []
varDecLevel: [|~1,1,2,~1|]
assignStack at decision level 2 [~2]
deduce at decision level 3
implicationQueue: [~3]
setVarValue 3 ~1
varValues: [|0,~1,~1,~1|]
clNumT: [|1,0,2,0|]
clNumF: [|1,1,0,2|]
conflicts: [1,3]
varDecLevel: [|~1,1,2,3|]
assignStack at decision level 3 [~3]
deduce at decision level 3
implicationQueue: [3]
setVarValue 3 1
varValues: [|0,~1,~1,1|]
clNumT: [|1,1,1,1|]
clNumF: [|1,0,1,1|]
conflicts: []
varDecLevel: [|~1,1,2,3|]
assignStack at decision level 3 [3]
Decisions: 4
Conflicts: 1
Implications: 4
SATISFIABLE
-1 -2 3 0
Computation time is 1msec.
val it = 0 : OS.Process.status
- Nplsat.nplsat ("", ["test3_3.cnf"]);
Number of variables = 3
Number of clauses = 4
[1,2]
[~2]
[~1,2,3]
[~3]
deduce at decision level 1
implicationQueue: [~1]
setVarValue 1 ~1
varValues: [|0,~1,0,0|]
clNumT: [|0,0,1,0|]
clNumF: [|1,0,0,0|]
conflicts: []
varDecLevel: [|~1,1,~1,~1|]
assignStack at decision level 1 [~1]
deduce at decision level 2
implicationQueue: [~2]
setVarValue 2 ~1
varValues: [|0,~1,~1,0|]
clNumT: [|0,1,1,0|]
clNumF: [|2,0,1,0|]
conflicts: [0]
varDecLevel: [|~1,1,2,~1|]
assignStack at decision level 2 [~2]
deduce at decision level 2
implicationQueue: [2]
setVarValue 2 1
varValues: [|0,~1,1,0|]
clNumT: [|1,0,2,0|]
clNumF: [|1,1,0,0|]
conflicts: [1]
varDecLevel: [|~1,1,2,~1|]
assignStack at decision level 2 [2]
deduce at decision level 1
implicationQueue: [1]
setVarValue 1 1
varValues: [|0,1,0,0|]
clNumT: [|1,0,0,0|]
clNumF: [|0,0,1,0|]
conflicts: []
varDecLevel: [|~1,1,~1,~1|]
assignStack at decision level 1 [1]
deduce at decision level 2
implicationQueue: [~2]
setVarValue 2 ~1
varValues: [|0,1,~1,0|]
clNumT: [|1,1,0,0|]
clNumF: [|1,0,2,0|]
conflicts: []
varDecLevel: [|~1,1,2,~1|]
assignStack at decision level 2 [~2]
deduce at decision level 3
implicationQueue: [~3]
setVarValue 3 ~1
varValues: [|0,1,~1,~1|]
clNumT: [|1,1,0,1|]
clNumF: [|1,0,3,0|]
conflicts: [2]
varDecLevel: [|~1,1,2,3|]
assignStack at decision level 3 [~3]
deduce at decision level 3
implicationQueue: [3]
setVarValue 3 1
varValues: [|0,1,~1,1|]
clNumT: [|1,1,1,0|]
clNumF: [|1,0,2,1|]
conflicts: [3]
varDecLevel: [|~1,1,2,3|]
assignStack at decision level 3 [3]
deduce at decision level 2
implicationQueue: [2]
setVarValue 2 1
varValues: [|0,1,1,0|]
clNumT: [|2,0,1,0|]
clNumF: [|0,1,1,0|]
conflicts: [1]
varDecLevel: [|~1,1,2,~1|]
assignStack at decision level 2 [2]
Decisions: 4
Conflicts: 5
Implications: 8
UNSATISFIABLE
Computation time is 0msec.
val it = 0 : OS.Process.status
[作成課題 課題4.1]考察
 flipVarについて説明する。引数が0の時は(0,[])を返す。また、引数がn(nは0でない)のときはvarFlippedのn番目の要素がtrueかfalseの判定をし、trueの時は再帰呼び出しを行い、falseの時はvarFlippedの修正をかけたのちnとassignStackのn番目のlistの先頭について符号をひっくり返した要素1つをもつlistの組を返した。
 実行結果を見るとtest3_1.cnf及びtest3_2.cnfがSATISFIABLE、test3_3.cnfがUNSATISFIABLEとなった。課題3.3の1で考えた結果と比較するとすべて一致しており、論理式の充足可能性を判定できているといえる。そのため、正常に動作していると考えられる。

[作成課題 課題4.2]実行結果
ホスト名icec50.ice.nuie.nagoya-u.ac.jpの計算機において実行した結果を示す。

- Nplsat.nplsat ("", ["sudoku8993.cnf","sudoku8993.sat"]); 
Decisions: 99832
Conflicts: 99183
Implications: 199014
SATISFIABLE
Computation time is 228msec.
val it = 0 : OS.Process.status
- Nplsat.nplsat ("", ["sudoku11548.cnf","sudoku11548.sat"]); 
Decisions: 21375009
Conflicts: 21374360
Implications: 42749368
SATISFIABLE
Computation time is 42249msec.
val it = 0 : OS.Process.status

[作成課題 課題4.2]考察
diff sudoku8993.sat sudoku8993sample.satを実行した結果何も出力されなかった。そのため、数独を解き、かつその割り当てを正確に出力できていると考えられる。
与えられた数独により実行時間に100倍以上の実行時間差がついていることについて、Conflictsにも100倍以上の差がついていることが理由としてあげられる。つまり、SATの処理が最悪計算時間で指数オーダであるため、SATツールは解く問題との相性によって実行時間に大差がつくことが結果と考えられる。
