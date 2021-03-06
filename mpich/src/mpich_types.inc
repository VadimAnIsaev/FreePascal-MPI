{*********************************************
 Headers of MPI (library MPICH) for FreePascal.
 Data Types.
 Main module - mpi.pas.
  
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

Type 
  
  TMPI_Aint       = longint;
//  MPI_Aint        = TMPI_Aint;	! Coincidence with a constant !
  PMPI_Aint       = ^TMPI_Aint;
  TMPI_Comm       = integer;
  PMPI_Comm       = ^TMPI_Comm;
  TMPI_Count      = int64;
  PMPI_Count      = ^TMPI_Count;
  TMPI_Datatype   = integer;
  PMPI_Datatype   = ^TMPI_Datatype;
  TMPI_Errhandler = integer;
  PMPI_Errhandler = ^TMPI_Errhandler;
  TMPI_Group      = integer;
  PMPI_Group      = ^TMPI_Group;
  TMPI_Fint       = integer;
  PMPI_Fint       = ^TMPI_Fint;
  TMPI_Info       = integer;
  PMPI_Info       = ^TMPI_Info;
  TMPI_Message    = integer;
  PMPI_Message    = ^TMPI_Message;
  TMPI_Offset     = int64;
  PMPI_Offset     = ^TMPI_Offset;
  TMPI_Op         = integer;
  PMPI_Op         = ^TMPI_Op;
  TMPI_Request    = integer;
  PMPI_Request    = ^TMPI_Request; 
  TMPI_Win        = integer;
  PMPI_Win        = ^TMPI_Win;
  
  MPI_Status = packed record
    count_lo              : integer;
    count_hi_and_cancelled: integer;
    MPI_SOURCE            : integer;
    MPI_TAG               : integer;
    MPI_ERROR             : integer;
  end;
  TMPI_Status = MPI_Status;
  PMPI_Status = ^TMPI_Status;
 
  MPI_F08_Status = packed record
    count_lo              : TMPI_Fint;
    count_hi_and_cancelled: TMPI_Fint;
    MPI_SOURCE            : TMPI_Fint;
    MPI_TAG               : TMPI_Fint;
    MPI_ERROR             : TMPI_Fint;
  end;
  TMPI_F08_Status = MPI_F08_Status;
  PMPI_F08_Status = ^MPI_F08_Status;

  TArrInteger3		= array[0..2] of Integer;
  TArr2Integer		= array of array of TArrInteger3;
  TArrMPI_Aint		= array of TMPI_Aint;
  TArrMPI_Datatype 	= array of TMPI_Datatype;
  TArrMPI_Info 		= array of TMPI_Info;
  TArrMPI_Request	= array of TMPI_Request;
  TArrMPI_Status	= array of TMPI_Status;


  MPI_Handler_function		= procedure( p1: PMPI_Comm; p2: Pinteger; args: array of const );
  PMPI_Handler_function		= MPI_Handler_function;
  MPI_Comm_errhandler_function	= procedure( p1: PMPI_Comm; p2: Pinteger; args: array of const );
  PMPI_Comm_errhandler_function	= MPI_Comm_errhandler_function;
  MPI_Win_errhandler_function	= procedure( p1: PMPI_Win; p2: Pinteger; args: array of const);
  PMPI_Win_errhandler_function	= MPI_Win_errhandler_function;
  MPI_User_function		= procedure( p1: Pointer; p2: Pointer; p3: Pinteger; p4: TMPI_Datatype ); 
  PMPI_User_function		= MPI_User_function;
  
  MPI_Comm_copy_attr_function		= function(p1: TMPI_Comm; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger): integer;
  PMPI_Comm_copy_attr_function		= MPI_Comm_copy_attr_function;
  MPI_Comm_delete_attr_function		= function(p1: TMPI_Comm; p2: integer; p3: Pointer; p4: Pointer): integer;
  PMPI_Comm_delete_attr_function	= MPI_Comm_delete_attr_function;
  MPI_Type_copy_attr_function		= function(p1: TMPI_Datatype; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger): integer;
  PMPI_Type_copy_attr_function		= MPI_Type_copy_attr_function;
  MPI_Type_delete_attr_function		= function(p1: TMPI_Datatype; p2: integer; p3: Pointer; p4: Pointer): integer;
  PMPI_Type_delete_attr_function	= MPI_Type_delete_attr_function;
  MPI_Win_copy_attr_function		= function(p1: TMPI_Win; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger): integer;
  PMPI_Win_copy_attr_function		= MPI_Win_copy_attr_function;
  MPI_Win_delete_attr_function		= function(p1: TMPI_Win; p2: integer; p3: Pointer; p4: Pointer): integer;
  PMPI_Win_delete_attr_function		= MPI_Win_delete_attr_function;
  MPI_Copy_function			= function(p1: TMPI_Comm; p2: integer; p3: Pointer; p4: Pointer; p5: Pointer; p6: Pinteger ): integer;
  PMPI_Copy_function			= MPI_Copy_function;
  MPI_Delete_function			= function(p1: TMPI_Comm; p2: integer; p3: Pointer; p4: Pointer ): integer;
  PMPI_Delete_function			= MPI_Delete_function;
  MPI_Grequest_cancel_function		= function(p1: Pointer; p2: integer ): integer; 
  PMPI_Grequest_cancel_function		= MPI_Grequest_cancel_function;
  MPI_Grequest_free_function		= function(p: Pointer): integer; 
  PMPI_Grequest_free_function		= MPI_Grequest_free_function;
  MPI_Grequest_query_function		= function(p1: Pointer; p2: PMPI_Status): integer; 
  PMPI_Grequest_query_function		= MPI_Grequest_query_function;
  MPI_Datarep_conversion_function	= function(p1: Pointer; p2: TMPI_Datatype; p3: integer; p4: Pointer; p5: TMPI_Offset; p6: Pointer): integer;
  PMPI_Datarep_conversion_function	= MPI_Datarep_conversion_function;
  MPI_Datarep_extent_function		= function(p1: TMPI_Datatype; p2: PMPI_Aint; p3: Pointer): integer;
  PMPI_Datarep_extent_function		= MPI_Datarep_extent_function;

  MPI_Comm_errhandler_fn	= MPI_Comm_errhandler_function;
  PMPI_Comm_errhandler_fn	= MPI_Comm_errhandler_fn;
  MPI_Win_errhandler_fn		= MPI_Win_errhandler_function;
  PMPI_Win_errhandler_fn	= MPI_Win_errhandler_fn;

