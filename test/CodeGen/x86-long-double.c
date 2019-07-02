// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 -mlong-double-64 | \
// RUN:   FileCheck --check-prefix=FP64-X32 %s
// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-apple-darwin9 | \
// RUN:   FileCheck --check-prefix=FP80 %s
// RUN: %clang_cc1 %s -emit-llvm -o - -triple=x86_64-linux-musl -mlong-double-64 | \
// RUN:   FileCheck --check-prefix=FP64-X64 %s
// RUN: %clang_cc1 %s -emit-llvm -o - -triple=x86_64-linux-musl | \
// RUN:   FileCheck --check-prefix=FP80 %s

// Check -malign-double increases the alignment from 4 to 8 on x86-32.
// RUN: %clang_cc1 %s -emit-llvm -o - -triple=i686-linux-musl -mlong-double-64 \
// RUN:   -malign-double | FileCheck --check-prefix=FP64-X64 %s
// RUN: %clang_cc1 %s -emit-llvm -o - -triple=x86_64-linux-musl -mlong-double-64 \
// RUN:   -malign-double | FileCheck --check-prefix=FP64-X64 %s

long double x = 0;
int size = sizeof(x);

// FP64-X32: @x = global double {{.*}}, align 4
// FP64-X32: @size = global i32 8
// FP64-X64: @x = global double {{.*}}, align 8
// FP64-X64: @size = global i32 8
// FP80: @x = global x86_fp80 {{.*}}, align 16
// FP80: @size = global i32 16
