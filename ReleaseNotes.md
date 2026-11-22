# Updates & Features

## v2025r2

* CMake compatibility updated to versions 3.10 through 4.1.

## v2024r1m1

* Added TecIO-MPI capability to supply MPI File Info when opening a file.

# Bug Fixes

## v2026r1

* Fixed TecIO writing of user-defined face neighbors for 2D zones in
  .szplt files.

* Fixed a TecIO-MPI hang encountered when only the final two ranks
  owned zone partitions.

## v2025r1

* Fixed a TecIO-MPI crash encountered when a partitioned FEMixed zone
  had empty sections.

## v2024r1

* Fixed error while reading Partitioned FE and IJK zones in chunks
  instead of an entire variable at a time.

* Fixed error in new API encountered while writing grid and solution files.
