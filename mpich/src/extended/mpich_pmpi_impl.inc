
function PMPI_Comm_c2f(comm: TMPI_Comm): TMPI_Fint;
Begin
  result:=TMPI_Fint(comm);
end;

function PMPI_Comm_f2c(comm: TMPI_Fint): TMPI_Comm;
Begin
  result:=TMPI_Comm(comm);
End;

function PMPI_Type_c2f(datatype: TMPI_Datatype): TMPI_Fint;
Begin
  result:=TMPI_Fint(datatype);
End;

function PMPI_Type_f2c(datatype: TMPI_Fint): TMPI_Datatype;
Begin
  result:=TMPI_Datatype(datatype);
End;

function PMPI_Group_c2f(group: TMPI_Group): TMPI_Fint;
Begin
  result:=TMPI_Fint(group);
End;

function PMPI_Group_f2c(group: TMPI_Fint): TMPI_Group;
Begin
  result:=TMPI_Group(group);
End;

function PMPI_Info_c2f(info: TMPI_Info): TMPI_Fint;
Begin
  result:=TMPI_Fint(info);
End;

function PMPI_Info_f2c(info: TMPI_Fint): TMPI_Info;
Begin
  result:=TMPI_Info(info);
End;

function PMPI_Request_f2c(request: TMPI_Fint): TMPI_Request;
Begin
  result:=TMPI_Request(request);
End;

function PMPI_Request_c2f(request: TMPI_Request): TMPI_Fint;
Begin
  result:=TMPI_Fint(request);
End;

function PMPI_Op_c2f(op: TMPI_Op): TMPI_Fint;
Begin
  result:=TMPI_Fint(op);
End;

function PMPI_Op_f2c(op: TMPI_Fint): TMPI_Op;
Begin
  result:=TMPI_Op(op);
End;

function PMPI_Errhandler_c2f(errhandler: TMPI_Errhandler): TMPI_Fint;
Begin
  result:=TMPI_Fint(errhandler);
End;

function PMPI_Errhandler_f2c(errhandler: TMPI_Fint): TMPI_Errhandler;
Begin
  result:=TMPI_Errhandler(errhandler);
End;

function PMPI_Win_c2f(win: TMPI_Win): TMPI_Fint;
Begin
  result:=TMPI_Fint(win);
End;

function PMPI_Win_f2c(win: TMPI_Fint): TMPI_Win;
Begin
  result:=TMPI_Win(win);
End;

function PMPI_Message_c2f(msg: TMPI_Message): TMPI_Fint;
Begin
  result:=TMPI_Fint(msg);
End;

function PMPI_Message_f2c(msg: TMPI_Fint): TMPI_Message;
Begin
  result:=TMPI_Message(msg);
End;
