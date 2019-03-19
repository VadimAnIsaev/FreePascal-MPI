
function MPI_Comm_c2f(comm: TMPI_Comm): TMPI_Fint;
Begin
  result:=TMPI_Fint(comm);
end;

function MPI_Comm_f2c(comm: TMPI_Fint): TMPI_Comm;
Begin
  result:=TMPI_Comm(comm);
End;

function MPI_Type_c2f(datatype: TMPI_Datatype): TMPI_Fint;
Begin
  result:=TMPI_Fint(datatype);
End;

function MPI_Type_f2c(datatype: TMPI_Fint): TMPI_Datatype;
Begin
  result:=TMPI_Datatype(datatype);
End;

function MPI_Group_c2f(group: TMPI_Group): TMPI_Fint;
Begin
  result:=TMPI_Fint(group);
End;

function MPI_Group_f2c(group: TMPI_Fint): TMPI_Group;
Begin
  result:=TMPI_Group(group);
End;

function MPI_Info_c2f(info: TMPI_Info): TMPI_Fint;
Begin
  result:=TMPI_Fint(info);
End;

function MPI_Info_f2c(info: TMPI_Fint): TMPI_Info;
Begin
  result:=TMPI_Info(info);
End;

function MPI_Request_f2c(request: TMPI_Fint): TMPI_Request;
Begin
  result:=TMPI_Request(request);
End;

function MPI_Request_c2f(request: TMPI_Request): TMPI_Fint;
Begin
  result:=TMPI_Fint(request);
End;

function MPI_Op_c2f(op: TMPI_Op): TMPI_Fint;
Begin
  result:=TMPI_Fint(op);
End;

function MPI_Op_f2c(op: TMPI_Fint): TMPI_Op;
Begin
  result:=TMPI_Op(op);
End;

function MPI_Errhandler_c2f(errhandler: TMPI_Errhandler): TMPI_Fint;
Begin
  result:=TMPI_Fint(errhandler);
End;

function MPI_Errhandler_f2c(errhandler: TMPI_Fint): TMPI_Errhandler;
Begin
  result:=TMPI_Errhandler(errhandler);
End;

function MPI_Win_c2f(win: TMPI_Win): TMPI_Fint;
Begin
  result:=TMPI_Fint(win);
End;

function MPI_Win_f2c(win: TMPI_Fint): TMPI_Win;
Begin
  result:=TMPI_Win(win);
End;

function MPI_Message_c2f(msg: TMPI_Message): TMPI_Fint;
Begin
  result:=TMPI_Fint(msg);
End;

function MPI_Message_f2c(msg: TMPI_Fint): TMPI_Message;
Begin
  result:=TMPI_Message(msg);
End;
