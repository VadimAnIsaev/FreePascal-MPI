{$mode objfpc}{$h+}
{$packrecords c}
Unit mpi;

interface

Uses {$IFDEF WINDOWS} Windows, {$ENDIF}SysUtils;

Const
{$IFDEF WINDOWS}  
  LIBMPI = 'cygmpi-40.dll';
{$ELSE}
  LIBMPI = 'mpich';
{$ENDIF}

{$I const.inc}

{$I ompi_types.inc}
{$I ompi_func.inc}


implementation


end.
