# Task Plan

## Previous Goal
Use a C flexible-array structure for protocol frames while preserving the existing wire format, byte order, CRC behavior, and comment style.

## Previous Phases
- [complete] Inspect the current source and define the wire-format invariants.
- [complete] Replace the raw frame buffer with a flexible-array frame structure.
- [complete] Compile and run focused verification.

## Current Goal
Replace the over-engineered `main.c` example with a small fixed-capacity memory pool exposing exactly `pool_create`, `pool_alloc`, `pool_free`, and `pool_destroy`, without heap allocation.

## New Goal
Harden the `fread`/`fwrite` file-copy example: terminate progress output on failures, remove incomplete destination files, reject source/destination aliasing, and prevent large-file progress arithmetic overflow.

## New Phases
- [complete] Add failure cleanup, same-file protection, and overflow-safe progress calculation.
- [complete] Compile with warnings and run success, empty-file, same-file, and failure-path checks.
- [complete] Review the diff and summarize behavior changes.

## Current Phases
- [complete] Inspect the current allocation model and surrounding build setup.
- [complete] Replace the complex pool/list implementation with the requested four-function fixed-pool API.
- [complete] Build, run, and confirm that the simplified source has no heap-allocation calls.

## Errors Encountered
| Error | Attempt | Resolution |
|---|---:|---|
| Temporary test executable deletion rejected by the environment | 1 | Left only `pool_fixed_test.exe`; source and tests are unaffected. |
| Multi-file patch combined several updates to `main.c` | 1 | Applied the source-only patch separately; no partial source edit occurred. |

## malloc/free Tracking Wrapper

- [complete] Add fixed-capacity allocation records with address, size, file, and line metadata.
- [complete] Add `TMALLOC`/`TFREE` macros, safe release matching, and an `atexit(mem_report)` leak report.
- [complete] Compile and run normal-release, duplicate-free, and intentional-leak checks.
