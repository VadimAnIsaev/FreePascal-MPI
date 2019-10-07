{$mode objfpc}
Uses mpi;

Var
    rank: integer;
    size: integer;
    len: integer;
    processor: array[0..MPI_MAX_PROCESSOR_NAME] of Char;

Begin
    MPI_Init(MPI_ARGC_NULL, NIL);
    MPI_COMM_WORLD:=MPI_Comm_f2c(MPI_COMM_WORLD_FORTRAN);
    MPI_Comm_rank(MPI_COMM_WORLD, @rank);
    MPI_Comm_size(MPI_COMM_WORLD, @size);
    MPI_Get_Processor_Name(@processor[0], @len);
    Writeln('Hello world from process ', rank, ' of ', size);
    WriteLn('I am running on host ', processor);
    MPI_Finalize();
End.
