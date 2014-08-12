### AMD Heterogenous System Architecture HSA - Linux HSA Runtime Alpha release for Kaveri

This package includes the user-mode API interfaces and libraries necessary for host applications to launch compute kernels to available HSA components. This version is consistent with the 1.0 Provisional HSA Runtime Programmer's Reference Manual and targets AMD Kaveri APUs on supported platforms, and is the 0.8 version of the HSA Runtime. This version is compatible with the 0.8 version of the HSA driver set. See the HSA-docs repository at https://github.com/HSAFoundation/HSA-docs/wiki for more information regarding target platforms, documentation and usage.

#### Package Contents

* hsa.h - Header file exposing the API interface of the HSA runtime's core functionality.
* hsa_ext_finalize.h - Header file exposing the API interface of the HSA runtime's HSAIL Finalization extension.
* libhsa-runtime.so.1 - The 32-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.
* libhsa-runtime64.so.1 - The 64-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.

#### Target Platform

This release is intended for use with any hardware configuration that contains a Kaveri APU. The motherboards must support the FM2+ socket, run latest BIOS version and have the IOMMU enabled in the BIOS. The following is a reference hardware configuration that was used for testing purposes:

* APU: AMD A10-7850K APU
* Motherboard: ASUS A88X-PRO motherboard (ATX form factor)
* OS: Ubuntu 14.04
* No discrete GPU present in the system

Refer to the https://github.com/HSAFoundation/HSA-docs/wiki/HSA-Platforms-&-Installation wiki page for additional information on platform support.

#### Installing and configuring the HSA Runtime

There are no explicit installation instructions for the HSA Runtime at this time. Applications utilizing the HSA runtime must specify how the runtime is utilized, either as a explicitly loaded shared object or a library that is implicitly linked, and the runtime must be installed correctly for the application to appropriately utilize it. Please refer each application's specific documentation regarding runtime installation.

#### Verify HSA Runtime / HSA Driver compatibility

The HSA Runtime interacts with the HSA drivers using an interface library, libhsakmt.so. The HSA Runtime is dynamically linked with this library, which must be compatible with both the runtime and the HSA driver to properly work.

#### Known Issues

* The HSAIL Linker Service Layer does not resolve inter-module dependencies. Modules cannot contain declarations that correspond to definitions in other modules.
* The hsa_vendor_extension_query and hsa_extension_query APIs are not implemented.
