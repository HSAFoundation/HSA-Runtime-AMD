### AMD Heterogenous System Architecture HSA - Linux HSAIL-Runtime Alpha release for Kaveri

This package includes the user-mode API interfaces and libraries necessary for host applications to launch compute kernels to available HSA components. This version is consistent with the 1.0 Provisional HSA Runtime Programmer's Reference Manual and targets AMD Kaveri APUs on supported platforms. See the HSA-docs repository at https://github.com/HSAFoundation/HSA-docs/wiki for more information regarding target platforms, documentation and usage.

#### Package Contents

* hsa.h - Header file exposing the API interface of the HSAIL runtime's core functionality.
* hsa_ext_finalize.h - Header file exposing the API interface of the HSAIL runtime's HSAIL Finalization extension.
* libhsa-runtime.so.1 - The 32-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.
* libhsa-runtime64.so.1 - The 64-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.

Target Platform

This release is intended for use with any hardware configuration that contains a Kaveri APU.

The motherboards must support the FM2+ socket, run latest BIOS version and have the IOMMU enabled in the BIOS.

The following is a reference hardware configuration that was used for testing purposes:

    APU: AMD A10-7850K APU
    Motherboard: ASUS A88X-PRO motherboard (ATX form factor)
    Memory: G.SKILL Ripjaws X Series 16GB (2 x 8GB) 240-Pin DDR3 SDRAM DDR3 2133
    OS: Ubuntu 14.04 / Fedora 21 64-bit edition
    No discrete GPU present in the system
