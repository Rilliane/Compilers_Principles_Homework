 const maxp=10000; {最大结点数}
　　var {变量定义}
　　p,c,s,t:longint; {p,结点数;c,边数;s:起点;t:终点}
　　a,b:array[1..maxp,0..maxp] of longint; {a[x,y]存x,y之间边的权;b[x,c]存与x相连的第c个边的另一个结点y}
　　d:array[1..maxp] of integer; {队列}
　　v:array[1..maxp] of boolean; {是否入队的标记}
　　dist:array[1..maxp] of longint; {到起点的最短路}
　　head,tail:longint; {队首/队尾指针}

procedure init;
　　var i,x,y,z:longint;
　　begin
　　	read(p,c); 
　　	for i := 1 to c do
　　	begin
　　		readln(x,y,z); {x,y:一条边的两个结点;z:这条边的权值}
　　		inc(b[x,0]); b[x,b[x,0]] := y; a[x,y] := z; {b[x,0]：以x为一个结点的边的条数}
　　		inc(b[y,0]); b[y,b[y,0]] := x; a[y,x] := z;
　　	end;
　　	readln(s,t); {读入起点与终点}
　　end;
 
　　procedure spfa(s:longint); {SPFA}
　　var i,,j,now,sum:longint;
　　begin
　　	fillchar(d,sizeof(d),0);
　　	fillchar(v,sizeof(v),false);
　　	for j := 1 to p do dist[ j ]:=maxlongint;
　　	dist[s] := 0; v[s] := true; d[1] := s; {队列的初始状态,s为起点}
　　	head := 1; tail := 1;
　　	while head<=tail do {队列不空}
　　	begin
　　		now := d[head]; {取队首元素}
　　		for i := 1 to b[now,0] do
　　		if dist[b[now,i]]>dist[now]+a[now,b[now,i]] then
　　		begin
　　			dist[b[now,i]]:= dist[now]+a[now,b[now,i]]; {修改最短路}
　　			if not v[b[now,i]] then {扩展结点入队}
　	　		begin
　　				inc(tail);
　　				d[tail] := b[now,i];
　　				v[b[now,i]] := true;
　　			end;
　　		end;
　　		v[now] := false; {释放结点}
　　		inc(head); {出队}
　　	end;
　　end; 

　　procedure print;
　　begin
　　	writeln(dist[t]);
　　end;
　　begin
　　	init;
　　	spfa(s);
　　	print;
　　end.