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

{$I const.inc}
{$I ompi_types.inc}
{$I ompi_func.inc}

Var
  MPI_COMM_WORLD: TMPI_Comm;

implementation



end.
