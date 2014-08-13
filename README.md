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

#### HSA Runtime / HSA Driver compatibility

The HSA Runtime interacts with the HSA drivers using an interface library, libhsakmt.so. This library is packaged with the HSA driver set. The HSA Runtime is dynamically linked with this library, which must be compatible with both the runtime and the HSA driver to properly work. Any executable that uses the HSA runtime library will require that the directory containing a compatible version of libhsakmt.so is specified in the LD_LIBRARY_PATH environment variable.

#### Running the sample - vector_copy ####

A simple sample, vector_copy, is provided in the samples directory of this repository. The sample requires the libelf-dev package to build and execute. This package can be installed on Ubuntu by executing 'sudo apt-get install libelf-dev'.

To build the sample, simply issue the 'make' command in the sample directory. This will create the vectory_copy host executable. 

When executed, vectory_copy will load the vector_copy.brig ELF file, finalize the associated kernel and execute it on an available GPU device. Both the libhsa-runtime and libhsakmt shared object library directories must be in the LD_LIBRARY_PATH environment variable.

A successfull execution will print messages simillar to the following:

* Initializing the hsa runtime succeeded.
* Calling hsa_iterate_agents succeeded.
* Checking if the GPU device is non-zero succeeded.
* Querying the device name succeeded.
* The device name is Spectre.
* Querying the device maximum queue size succeeded.
* The maximum queue size is 131072.
* Creating the queue succeeded.
* Creating the brig module from vector_copy.brig succeeded.
* Creating the hsa program succeeded.
* Adding the brig module to the program succeeded.
* Finding the symbol offset for the kernel succeeded.
* Finalizing the program succeeded.
* Querying the kernel descriptor address succeeded.
* Creating a HSA signal succeeded.
* Registering argument memory for input parameter succeeded.
* Registering argument memory for output parameter succeeded.
* Finding a kernarg memory region succeeded.
* Allocating kernel argument memory buffer succeeded.
* Registering the argument buffer succeeded.
* Dispatching the kernel succeeded.
* Wating on the dispatch signal succeeded.
* Passed validation.
* Destroying the signal succeeded.
* Destroying the program succeeded.
* Destroying the queue succeeded.
* Shutting down the runtime succeeded.

An unsuccessful execution will indicate the step that failed.

#### Installation Q & A
* Q1. I keep getting an error saying 'error while loading shared libraries: libhsakmt.so.1: cannot open shared object file: No such file or directory'
* A1. The libhsakmt.so.1 library directory isn't in the LD_LIBRARY_PATH or the version of libhsamkt.so.1 is incorrect.

* Q2. I can initialize the runtime, using hsa_init, but there is no GPU device.
* A2. The /dev/kfd device is not properly initialized or it has the wrong permissions assigned to it. The command 'ls -l /dev/kfd' will list the permission on the kfd device. It should exist, and have 666 permissions assigned to it. Consult the HSA drivers README for information on how to configure the kfd devices permissions using udev.

#### Known Issues

* The HSAIL Linker Service Layer does not resolve inter-module dependencies. Modules cannot contain declarations that correspond to definitions in other modules.
* The hsa_vendor_extension_query and hsa_extension_query APIs are not implemented.
