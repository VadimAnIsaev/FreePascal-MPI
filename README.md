# FreePascal-MPI
Headers of MPI (MPICH and OpenMPI) for FreePascal.

## MPICH
Ready for testing.
Changes:
- General function "MPI_*";
- Module for file functions\operations;
- Included file with redesined c-macros.
--------------------------------------------------------
- Functions for file manipulstions temporally not ready.

04.04.2019.
- MPICH. Small changes to the headers of functions working with arrays. 
------------------------------
## OpenMPI
30.09.2019.

The unit is compiling. In testing.

Function "MPI_File*" do not work correctly. Reason - the structure "ompi_file_t" is not fully defined. 

Structures related to "Infiniband" are temporarily undefined.
