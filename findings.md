# Findings

- The intended header is 9 bytes: start(1), type(1), payload length(2), timestamp(4), CRC8(1).
- The current code writes multi-byte integer members through a structure, so wire bytes depend on host endianness.
- The protocol length field is 16-bit while allocation lengths use `size_t`; narrowing must be validated before conversion.
- CRC must be calculated after serialization, over the exact transmitted bytes.
- The packed structure can be removed entirely; fixed byte offsets avoid host byte order, padding, and unaligned-access dependencies.
- `crc_ref.c` already defines the CRC16 trailer as little-endian, so that trailer format remains unchanged.
- The VS Code task invokes `g++` for one active file; it must invoke `gcc` and link both C source files.
- A flexible-array frame can preserve the 9-byte header by storing multi-byte fields as byte arrays and writing them explicitly; the CRC16 trailer must remain outside the structure member list.

## Fixed-Pool List Refactor

- `main.c` currently allocates the pool object, block storage, and allocation bitmap on the heap through `pool_create`, `malloc`, and `calloc`.
- A fixed embedded pool can instead be initialized from statically allocated storage and usage-marker arrays supplied by the caller.
- `ListOps` needs callback context to let `create` and `destroy` allocate and release payloads through a fixed pool without hidden global state.
- The list-node pool and the integer-data pool should be separate because `ListNode` and `int` have different sizes.

## Final Simplified Pool

- The final version intentionally removes `ListOps`, `ListNode`, and the generic callback layer at the user's request.
- It exposes only `pool_create`, `pool_alloc`, `pool_free`, and `pool_destroy` with the requested opaque `MemoryPool` declaration.
- Backing storage is a fixed static array of max-aligned blocks, so no heap allocator is called.
- The implementation supports at most `MEMORY_POOL_MAX_INSTANCES` concurrent pools; block size and count are checked against compile-time limits.

## malloc/free Tracking Wrapper

- `main.c` now stores active allocations in a static fixed-size table, so the tracker does not allocate memory recursively.
- `TMALLOC(size)` captures `__FILE__` and `__LINE__`; `TFREE(ptr)` marks the matching record inactive before calling `free`.
- `mem_report` is registered once with `atexit` and reports each active address, size, and allocation location.
- Unknown and repeated frees are diagnosed and ignored to avoid an unsafe second `free`.

## File Copy Hardening

- `main.c` prints progress with `\r` and can jump to `cleanup` after `fwrite`, `fread`, or `fclose` errors.
- Before the fix, those failure paths could leave the cursor on an unterminated progress line and leave a partial destination file.
- Opening the destination with `"wb"` before copying destroys the source when both arguments identify the same file.
- `copied_size * 100` can overflow a 32-bit Windows `long`; progress now uses `long double` arithmetic.
