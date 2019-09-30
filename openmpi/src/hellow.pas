Uses mpi;

Var
    rank: integer;
    size: integer;

Begin
    MPI_Init(NIL, NIL);
    MPI_Comm_rank(MPI_COMM_WORLD, @rank);
    MPI_Comm_size(MPI_COMM_WORLD, @size);
    Writeln('Hello world from process ', rank, ' of ', size);
    MPI_Finalize();
End.
