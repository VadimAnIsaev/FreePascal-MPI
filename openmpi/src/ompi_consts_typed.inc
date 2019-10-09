Const
  MPI_STATUS_IGNORE	= PMPI_Status(0);
  MPI_STATUSES_IGNORE	= PMPI_Status(0);

Var
  // Communicators
  MPI_COMM_WORLD: PMPI_Comm;
  MPI_COMM_SELF : PMPI_Comm;
  MPI_COMM_NULL : PMPI_Comm;
  
  // Datatypes
  // Integers
  MPI_BYTE		: PMPI_Datatype;
  MPI_SHORT		: PMPI_Datatype;
  MPI_INTEGER		: PMPI_Datatype;
  MPI_LONG_LONG_INT	: PMPI_Datatype;
  MPI_UNSIGNED		: PMPI_Datatype;
  // Floats
  MPI_FLOAT		: PMPI_Datatype;
  MPI_DOUBLE		: PMPI_Datatype;
  // Others
  MPI_CHARACTER 	: PMPI_Datatype;
  MPI_LOGICAL		: PMPI_Datatype;
    
  // Operation
  MPI_MAX	: PMPI_Op;
  MPI_MIN	: PMPI_Op;
  MPI_SUM	: PMPI_Op;
  MPI_PROD	: PMPI_Op;
  MPI_BAND	: PMPI_Op;
  MPI_LAND	: PMPI_Op;
  MPI_BOR	: PMPI_Op;
  MPI_LOR	: PMPI_Op;
  MPI_BXOR	: PMPI_Op;
  MPI_LXOR	: PMPI_Op;
  MPI_MAXLOC	: PMPI_Op;
  MPI_MINLOC	: PMPI_Op;
  MPI_REPLACE	: PMPI_Op;
  MPI_NO_OP	: PMPI_Op;
