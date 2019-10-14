{*********************************************
 Headers of MPI (library MPICH) for FreePascal.
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
{$define MPICH}
unit mpi;

interface

Const
{$IFDEF WINDOWS}  
  LIBMPI = 'msmpi.dll';		// MPICH from Microsoft
{$ELSE}
  LIBMPI = 'mpi';
{$ENDIF}

{$I mpich_types.inc}
{$I mpich_consts.inc}
{$I mpich_mpi_func.inc}

implementation

{$I mpich_mpi_func_impl.inc}  

end.
