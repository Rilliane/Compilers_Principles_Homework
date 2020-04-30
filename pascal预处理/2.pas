(*  pascal最短路径算法 *)
var
  f:array[1..100] of boolean;
  cost:array[1..100,1..100] of longint;
  fa,dist:array[1..100] of longint;
  n,m,r,a,b,c,i,j,p,min:longint;
begin
  readln(n,m,r);
  for i:=1 to m do begin
    readln(a,b,c);
    cost[a,b]:=c;
  end;

  fillchar(f,sizeof(f),false);
  for i:=1 to n do dist[i]:=maxlongint;{初始化距离为无穷大}
  dist[r]:=0;  
 //不写f[r]=true;！！！！！！！！！
  for i:=1 to n do begin
    if i<>r then begin
      min:=maxlongint;
      for j:=1 to n do
        if (not f[j]) and (dist[j]<min) then begin
          min:=dist[j];
          p:=j;
        end;
      f[p]:=true;
      for j:=1 to n do
        if (dist[j]>dist[p]+cost[p,j]) and (cost[p,j]<>0) then begin
          dist[j]:=dist[p]+cost[p,j];
          fa[j]:=p;
        end;
    end;
  end;
  for i:=1 to n do begin
    writeln(dist[i]);
    p:=i;
    write(i);
    while fa[p]<>0 do begin
      write('<--',fa[p]);
      p:=fa[p];
    end;
    writeln;
  end;
  readln;
end.