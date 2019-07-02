// RUN: %clang_cc1 -triple powerpc64-linux-musl -emit-llvm -o - %s -mlong-double-64 | \
// RUN:   FileCheck --check-prefix=FP64 %s
// RUN: %clang_cc1 -triple powerpc64-linux-musl -emit-llvm -o - %s | \
// RUN:   FileCheck --check-prefix=IBM128 %s

struct S {
  char a;
  long double b;
};

// FP64: %struct.{{[a-zA-Z0-9]+}} = type { i8, double }
// IBM128: %struct.{{[a-zA-Z0-9]+}} = type { i8, ppc_fp128 }

long double load(struct S x) {
  return x.b;
}

// FP64: %{{[0-9]}} = load double, double* %{{[a-zA-Z0-9]+}}, align 8
// IBM128: %{{[0-9]}} = load ppc_fp128, ppc_fp128* %{{[a-zA-Z0-9]+}}, align 16
