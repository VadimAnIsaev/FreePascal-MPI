function PMPIO_Test(: PMPIO_Request; : Pinteger; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Test';
function PMPIO_Testall(: PMPIO_Request; : Pinteger; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Testall';
function PMPIO_Testany(: PMPIO_Request; : Pinteger; : Pinteger; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Testany';
function PMPIO_Testsome(: PMPIO_Request; : Pinteger; : Pinteger; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Testsome';
function PMPIO_Wait(: PMPIO_Request; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Wait';
function PMPIO_Waitall(: PMPIO_Request; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Waitall';
function PMPIO_Waitany(: PMPIO_Request; : Pinteger; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Waitany';
function PMPIO_Waitsome(: PMPIO_Request; : Pinteger; : Pinteger; : PMPI_Status): integer; cdecl; external LIBMPI name 'PMPIO_Waitsome';
function PMPI_File_f2c(): TMPI_File; cdecl; external LIBMPI name 'PMPI_File_f2c';
function PMPI_File_c2f(): TMPI_Fint; cdecl; external LIBMPI name 'PMPI_File_c2f';
function PMPI_Info_c2f(): TMPI_Fint; cdecl; external LIBMPI name 'PMPI_Info_c2f';
function PMPIO_Request_c2f(): TMPI_Fint; cdecl; external LIBMPI name 'PMPIO_Request_c2f';
function PMPI_Info_f2c(): TMPI_Info; cdecl; external LIBMPI name 'PMPI_Info_f2c';
function PMPIO_Request_f2c(): TMPIO_Request; cdecl; external LIBMPI name 'PMPIO_Request_f2c';
