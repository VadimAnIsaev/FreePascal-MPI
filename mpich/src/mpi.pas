{$mode objfpc}{$h+}
{$packrecords c}
unit mpich;

interface

Const
{$IFDEF WINDOWS}  
  LIBMPI = 'msmpi.dll';
{$ELSE}
  LIBMPI = 'mpich';
{$ENDIF}

{$I mpich_types.inc}

{$I mpich_consts.inc}

{$I mpich_mpi_func.inc}

implementation

end.
