	val result = f arg
    in
	print (Real.toString(Time.toReal(#usr(Timer.checkCPUTimer timer))));
	print " sec.\n";
	result
    end;
