# FreePascal-MPI
Headers of MPI (MPICH and OpenMPI) for FreePascal.

## MPICH
Ready for testing.
Changes:
- MPICH. General function "MPI_*";
- MPICH. Module for file functions\operations;
- MPICH. Included file with redesined c-macros.

04.04.2019.
- MPICH. Small changes to the headers of functions working with arrays. 
------------------------------
## OpenMPI
30.09.2019.
The unit is compiling. In testing.
Function "MPI_File*" do not work correctly. Reason - is the structure "ompi_file_t" is not fully defined. 
Structures related to "Infiniband" are temporarily undefined.
