Compile this:

> fpc hellow.pas 
>fpc testpi.pas 

Run this: 
On Windows:
> mpiexec -np 4 hellow 
> mpiexec -np 4 testpi 

On Unix: 
> mpirun -np 4 hellow 
> mpirun -np 4 testpi 

