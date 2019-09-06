// RUN: %clang -target %itanium_abi_triple %s -static=c++stdlib,rtlib -### 2>&1 | \
// RUN:   FileCheck /dev/null --implicit-check-not=error:

// RUN: %clang -target %itanium_abi_triple %s -static=unknown -### 2>&1 | FileCheck --check-prefix=STATIC-UNKNOWN %s
// STATIC-UNKNOWN: error: unsupported argument 'unknown' to option 'static='
