(*
    排序算法
*)
Program example(input,output);
Var
a:array[1..20] of integer;
temp: integer;
i,j:integer;
Begin
For i:=1 to 20 do  //读入20个元素
read(a[i]);
For i:=1 to 19 do  {从第一个到倒数第二个依次确定每个数 }
For j:=i+1 to 20 do  {确定的数与它后面所有的数进行比较}
If a[i]<a[j]
Then  Begin
temp:= a[i];
a[i]:= a[j];
a[j]:=temp
End;
For i:=1 to 20 do   {输出排序后的结果}
Begin
write(a[i]:5);
If i mod 5=0    {控制每行输出5个数据}
Then writeln
End;
End.