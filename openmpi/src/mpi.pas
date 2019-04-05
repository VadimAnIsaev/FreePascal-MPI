{$mode objfpc}{$h+}
{$packrecords c}
Unit mpi;

interface

Uses {$IFDEF WINDOWS} Windows, {$ENDIF}SysUtils;

Const
{$IFDEF WINDOWS}  
  LIBMPI = 'cygmpi-40.dll';
{$ELSE}
  LIBMPI = 'mpi';
{$ENDIF}

{$I ompi_consts.inc}
{$I ompi_consts2.inc}
{$I ompi_types.inc}
{$I ompi_func.inc}
{$I ompi_consts_typed.inc}

Var
  MPI_COMM_WORLD: TMPI_Comm;
  MPI_COMM_SELF: TMPI_Comm;

implementation

Begin

end.
