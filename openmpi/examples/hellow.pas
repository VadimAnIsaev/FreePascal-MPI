{$mode objfpc}
Uses mpi;

Var
    rank: integer;
    size: integer;
    MPI_COMM_F: integer;

Begin
    MPI_COMM_F:=0;
    MPI_Init(MPI_ARGC_NULL, NIL);
    MPI_COMM_WORLD:=MPI_Comm_f2c(MPI_COMM_F);
    MPI_Comm_rank(MPI_COMM_WORLD, @rank);
    MPI_Comm_size(MPI_COMM_WORLD, @size);
    Writeln('Hello world from process ', rank, ' of ', size);
    MPI_Finalize();
End.
