#include "gtest/gtest.h"
#include "ffi.h"

static int floating(int a, float b, double c, long double d)
{
    int i;

    i = (int) ((float)a/b + ((float)c/(float)d));

    return i;
}

TEST(function_call_test, float_test) {
    ffi_cif cif;
    ffi_type *args[4];
    void *values[4];
    ffi_arg rint;

    float f;
    signed int si1;
    double d;
    long double ld;

    args[0] = &ffi_type_sint;
    values[0] = &si1;
    args[1] = &ffi_type_float;
    values[1] = &f;
    args[2] = &ffi_type_double;
    values[2] = &d;
    args[3] = &ffi_type_longdouble;
    values[3] = &ld;

    EXPECT_TRUE(ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 4,&ffi_type_sint, args) == FFI_OK);

    si1 = 6;
    f = 3.14159;
    d = (double)1.0/(double)3.0;
    ld = 2.71828182846L;

    floating (si1, f, d, ld);

    ffi_call(&cif, FFI_FN(floating), &rint, values);

    EXPECT_TRUE(static_cast<int>(rint) == floating(si1, f, d, ld));
}