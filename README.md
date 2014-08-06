HSAIL-Runtime
=============

Contains the user-mode API interfaces and libraries necessary for host applications to launch compute kernels to available HSA components.

Contents
=============

<b>include/</b>

hsa.h - Header file exposing the API interface of the HSAIL runtime's core functionality. This version is consistent with the 1.0 provisional HSA Runtime Programmer's Reference Manual.

hsa_ext_finalize.h - Header file exposing the API interface of the HSAIL runtime's HSAIL Finalization extension. This version is consistent with the 1.0 Provisional HSA Runtime Programmer's Reference Manual.

<b>lib/x86/</b>

libhsa-runtime.so - Link to the libhsa-runtime.so.1 shared library.

libhsa-runtime.so.1 - The 32-bit version of AMD's implementation of the hsa runtime shared library. This version is consistent with the 1.0 Provisional HSA Runtime Programmer's Reference Manual.

<b>lib/x86_64/</b>

libhsa-runtime64.so - Link to the libhsa-runtime.so.1 shared library.

libhsa-runtime64.so.1 - The 64-bit version of AMD's implementation of the hsa runtime shared library. This version is consistent with the 1.0 Provisional HSA Runtime Programmer's Reference Manual.
