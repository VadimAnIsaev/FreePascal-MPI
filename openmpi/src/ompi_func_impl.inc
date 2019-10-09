procedure ConversionData();
Begin
  // Communicators
  MPI_COMM_WORLD	:= MPI_Comm_f2c(MPI_COMM_WORLD_F);
  MPI_COMM_SELF		:= MPI_Comm_f2c(MPI_COMM_SELF_F);
  MPI_COMM_NULL		:= MPI_Comm_f2c(MPI_COMM_NULL_F);
  
  // Datatypes
  // Integers
  MPI_BYTE		:= MPI_Type_f2c(MPI_BYTE_F);
  MPI_SHORT		:= MPI_Type_f2c(MPI_SHORT_F);
  MPI_INTEGER		:= MPI_Type_f2c(MPI_INTEGER_F);
  MPI_LONG_LONG_INT	:= MPI_Type_f2c(MPI_LONG_LONG_INT_F);
  MPI_UNSIGNED		:= MPI_Type_f2c(MPI_UNSIGNED_F);
  // Floats
  MPI_FLOAT		:= MPI_Type_f2c(MPI_FLOAT_F);
  MPI_DOUBLE		:= MPI_Type_f2c(MPI_DOUBLE_F);
  // Others
  MPI_CHARACTER 	:= MPI_Type_f2c(MPI_CHARACTER_F);
  MPI_LOGICAL		:= MPI_Type_f2c(MPI_LOGICAL_F);
    
  // Operation
  MPI_MAX	:= MPI_Op_f2c(MPI_MAX_F);
  MPI_MIN	:= MPI_Op_f2c(MPI_MIN_F);
  MPI_SUM	:= MPI_Op_f2c(MPI_SUM_F);
  MPI_PROD	:= MPI_Op_f2c(MPI_PROD_F);
  MPI_BAND	:= MPI_Op_f2c(MPI_BAND_F);
  MPI_LAND	:= MPI_Op_f2c(MPI_LAND_F);
  MPI_BOR	:= MPI_Op_f2c(MPI_BOR_F);
  MPI_LOR	:= MPI_Op_f2c(MPI_LOR_F);
  MPI_BXOR	:= MPI_Op_f2c(MPI_BXOR_F);
  MPI_LXOR	:= MPI_Op_f2c(MPI_LXOR_F);
  MPI_MAXLOC	:= MPI_Op_f2c(MPI_MAXLOC_F);
  MPI_MINLOC	:= MPI_Op_f2c(MPI_MINLOC_F);
  MPI_REPLACE	:= MPI_Op_f2c(MPI_REPLACE_F);
  MPI_NO_OP	:= MPI_Op_f2c(MPI_NO_OP_F);
End;

function MPI_Init2(): integer;
Begin
  Result := MPI_Init(MPI_ARGC_NULL, MPI_ARGV_NULL);
  If Result = MPI_SUCCESS Then
  Begin
    // Conversion
    ConversionData();
  End;
End;

function MPI_Init2_thread(required: integer; provided: Pinteger): integer;
Begin
  Result := MPI_Init_thread(MPI_ARGC_NULL, MPI_ARGV_NULL, required, provided);
  If Result = MPI_SUCCESS Then
  Begin
    // Conversion
    ConversionData();
  End;
End;
