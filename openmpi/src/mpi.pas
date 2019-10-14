{*********************************************
 Headers of MPI (library OpenMPI) for FreePascal.
 Unifying module.
  
 Copyright (C) 2019 by Vadim Isaev.

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 *********************************************}
{$mode objfpc}{$h+}
{$packrecords c}
{$define OpenMPI}
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

implementation

{$I ompi_func_impl.inc}

end.
