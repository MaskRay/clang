// RUN: %clang -target arm-linux-androideabi -### %s 2>&1 | \
// RUN:   FileCheck --implicit-check-not=--android-tls /dev/null
// RUN: %clang -target arm-linux-androideabi -fuse-ld=lld -### %s 2>&1 | \
// RUN:   FileCheck --check-prefix=TLS %s

// TLS: --android-tls
