### AMD Heterogenous System Architecture HSA - Linux HSAIL-Runtime Alpha release for Kaveri

This package includes the user-mode API interfaces and libraries necessary for host applications to launch compute kernels to available HSA components. This version is consistent with the 1.0 Provisional HSA Runtime Programmer's Reference Manual and targets AMD Kaveri APUs on supported platforms. See the HSA-docs repository at https://github.com/HSAFoundation/HSA-docs/wiki for more information regarding target platforms, documentation and usage.

#### Contents

<b>include/</b>

hsa.h - Header file exposing the API interface of the HSAIL runtime's core functionality.

hsa_ext_finalize.h - Header file exposing the API interface of the HSAIL runtime's HSAIL Finalization extension.

<b>lib/x86/</b>

libhsa-runtime.so - Link to the libhsa-runtime.so.1 shared library.

libhsa-runtime.so.1 - The 32-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.

<b>lib/x86_64/</b>

libhsa-runtime64.so - Link to the libhsa-runtime.so.1 shared library.

libhsa-runtime64.so.1 - The 64-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.
