{$mode objfpc}{$h+}
{$packrecords c}
Unit mpi;

interface

Uses SysUtils;

Const
{$IFDEF WINDOWS}  
  LIBMPI = 'cygmpi-40.dll';
{$ELSE}
  LIBMPI = 'mpich';
{$ENDIF}

{$I const.inc}

{$I ompi_types.inc}


implementation


end.
