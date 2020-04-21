# FreePascal-MPI
Headers of MPI (MPICH and OpenMPI) for FreePascal.

## MPICH
Version 3.3. Ready for testing.
Changes:
- In main unit "mpi.pas" included only general function "MPI_*";
- Functions for file manipulstions temporally not ready. Data structures for them are not yet ready.

04.04.2019.
- Small changes to the headers of functions working with arrays. 

07.10.2019.
- Insert "deprecated" for removed functions according to the standard MPI 3.1.

21.04.2020
- The function "MPI_Init ()" is unified with OpenMPI.

------------------------------
## OpenMPI
Version 4.0.1.  
30.09.2019.

The unit is compiling. In testing.

- Function "MPI_File*" do not work correctly. Reason - the structure "ompi_file_t" is not fully defined. 
- Structures related to "Infiniband" are temporarily undefined.
