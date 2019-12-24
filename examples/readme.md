Compile this:    

> fpc hellow.pas    
> fpc testpi.pas    

Run this:    
On Windows:     
> mpiexec -np 4 hellow
> mpiexec -np 4 testpi

On Unix (OpenMPI):    
> mpirun --use-hwthread-cpus hellow    
> mpirun --use-hwthread-cpus testpi    
(MPICH)
> mpirun -np 4 hellow    
> mpirun -np 4 testpi    

