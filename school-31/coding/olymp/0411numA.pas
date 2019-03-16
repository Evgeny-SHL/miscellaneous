var
	a			: array[1..100010] of longint;
	i, n, p, k	: longint;
	file1, file2	: text;
	
BEGIN
	assign(file1, 'race.out');
	assign(file2, 'race.out');
	reset(file1);
	rewrite(file2);
	readln(file1, n);
	for i := 1 to n do
		a[i] := 1;
	for i := 1 to n do
		begin
			read(file1, p);
			for k := i to p - 1 do
				a[i] := 0;
		end;
	k := 0;
	for i := 1 to n do
		if a[i] > 0 then //write({fo,} i,' ');
		inc(k);
	writeln(file2, k);
	for i := 1 to n do
		if a[i] > 0 then write(file2, i,' ');
//	close(fi);
//	close(fo);
	close(file1);
	close(file2);
END.
