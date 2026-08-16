# Changelog

## [1.1.0] - 2026-08-16

### Added
- `set_compression_level()` on `basic_streambuf`, `basic_ogzip_streambuf`,
  `basic_oxz_streambuf` and `basic_ofstream`, replacing the hardcoded
  compression level.
- Regression tests for `swap()`, move construction of `istream` and the
  gzip/xz streambufs, reopening with a different extension, truncated and
  corrupt input, and compression levels.
- `ENABLE_EXAMPLE` CMake option that builds the `my-zcat` example.
- Clang support for the `-Wall -Wextra` warning flags.

### Fixed
- Compile errors in `basic_ifstream::swap()`/`basic_ofstream::swap()`
  (`.` on a `unique_ptr`) and in the move constructors of the gzip and xz
  input streambufs (pointer type mismatch).
- Moving an `istream` wrapping an uncompressed streambuf no longer leaves
  it without a buffer.
- Reopening an `ifstream`/`ofstream` with a different extension no longer
  leaves a stale decompressor behind.
- `swap()` now transfers the (de)compressor together with the file buffer.
- Compression format detection no longer relies on `in_avail()`, and
  truncated input reads terminate instead of hanging.
- Errors during compression are now propagated through `close()`.
- The header is now self-contained (missing standard includes added) and
  `kDefaultBufferSize` is `constexpr`.
- The example validated its command line arguments.
- Generated `gxrioConfig.cmake` is now written to the build directory
  instead of the source tree.

## [1.0.3]
- Clean up code, remove warnings, add forge actions

## [1.0.2]
- Support for concatenated gzip files.

## [1.0.1]
- Now compiles on Windows with MSVC

## [1.0.0] - 2022-08-29

Initial release.
