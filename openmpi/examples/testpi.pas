{$mode objfpc}
Uses mpi;

function f(a: double): double;
Begin
  Result:=4.0 / (1.0 + a * a);
End;

Const
  PI25DT : double = 3.141592653589793238462643;

Var
    n, myid, numprocs, i: integer;
    mypi, pi, h, sum, x: double;
    startwtime, endwtime: double;
    namelen: integer;
    processor_name: array [1..MPI_MAX_PROCESSOR_NAME] of Char;


Begin
    MPI_Init(NIL, NIL);
    MPI_COMM_WORLD := MPI_Comm_f2c(MPI_COMM_WORLD_Fortran);
    MPI_Comm_size(MPI_COMM_WORLD, @numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, @myid);
    MPI_Get_processor_name(@processor_name[1], @namelen);

    WriteLn('Process ', myid, ' of ', numprocs, ' is on ', processor_name);

    n := 100000000;  // default # of rectangles
    If myid = 0 Then
      startwtime := MPI_Wtime();

    MPI_Bcast(@n, 1, MPI_Type_f2c(MPI_INT), 0, MPI_COMM_WORLD);

    h := 1.0 / n;
    sum := 0.0;
    // A slightly better approach starts from large i and works back
    i := myid + 1;
    While i <= n Do
    Begin
        x := h * (i - 0.5);
        sum := sum + f(x);
        i := i + numprocs;
    End;
    mypi := h * sum;

    MPI_Reduce(@mypi, @pi, 1, MPI_Type_f2c(MPI_DOUBLE), MPI_Op_f2c(MPI_SUM), 0, MPI_COMM_WORLD);

    if myid = 0 Then 
    Begin
        endwtime := MPI_Wtime();
        WriteLn('pi is approximately ', pi:18:16, '. Error is ', abs(pi - PI25DT):18:16);
        WriteLn('wall clock time = ', (endwtime - startwtime):10:3, ' sec.');
    End;

    MPI_Finalize();

End.
