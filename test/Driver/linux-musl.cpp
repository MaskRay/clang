// RUN: %clangxx -no-canonical-prefixes %s -### -target x86_64-linux-musl 2>&1 \
// RUN:   -static=c++stdlib -stdlib=libc++ \
// RUN:   -ccc-install-dir %S/Inputs/basic_linux_tree/usr/bin \
// RUN:   --sysroot=%S/Inputs/basic_linux_libcxx_tree \
// RUN:   | FileCheck --check-prefix=CHECK-STATIC-LIBCXX %s
// CHECK-STATIC-LIBCXX: "-Bstatic" "-lc++" "-Bdynamic" "-lm" "-lgcc_s" "-lgcc" "-lc" "-lgcc_s" "-lgcc"

// RUN: %clangxx -no-canonical-prefixes %s -### -target x86_64-linux-musl 2>&1 \
// RUN:   -static=c++stdlib,rtlib -stdlib=libc++ \
// RUN:   -ccc-install-dir %S/Inputs/basic_linux_tree/usr/bin \
// RUN:   --sysroot=%S/Inputs/basic_linux_libcxx_tree \
// RUN:   | FileCheck --check-prefix=CHECK-STATIC-LIBCXX-RTLIB %s
// CHECK-STATIC-LIBCXX-RTLIB: "-Bstatic" "-lc++" "-Bdynamic" "-lm" "-lgcc" "-lgcc_eh" "-lc" "-lgcc" "-lgcc_eh"
