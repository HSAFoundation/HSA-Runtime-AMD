### AMD Heterogeneous System Architecture HSA - HSA Runtime Beta release for AMD 7000 series APUs

This package includes the user-mode API interfaces and libraries necessary for host applications to launch compute kernels to available HSA components. This version implements the 1.0 Provisional HSA Runtime Programmer's Reference Manual and targets AMD 7000 series APUs on supported platforms. The package is compatible with the 0.9 version of the HSA driver set. See the HSA-docs repository at https://github.com/HSAFoundation/HSA-docs/wiki for more information regarding target platforms, documentation and usage.

#### Package Contents

* hsa.h - Header file exposing the API interface of the HSA runtime's core functionality.
* hsa_ext_image.h - Header file exposing the API interface of the HSA runtime's image extension.
* hsa_ext_finalize.h - Header file exposing the API interface of the HSA runtime's HSAIL Finalization extension.
* libhsa-runtime.so.1 - The 32-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.
* libhsa-runtime64.so.1 - The 64-bit version of AMD's implementation of the hsa runtime shared library. Both core and extended finalizer functionality is exposed.
* vector_copy sample - A simple HSA sample illustrating how to load a BRIG module from an ELF container, create and finalize a HSA program and dispatch the resulting HSA kernel.

#### Target Platform

This release is intended for use with any hardware configuration that contains an AMD 7000 series APU. The motherboards must support the FM2+ socket, run the latest BIOS version and have the IOMMU enabled in the BIOS. The following is a reference hardware configuration that was used for testing purposes:

* APU: AMD A10-7850K APU
* Motherboard: ASUS A88X-PRO motherboard (ATX form factor)
* OS: Ubuntu 14.04, Fedora 21
* No discrete GPU present in the system

Refer to the https://github.com/HSAFoundation/HSA-docs/wiki/HSA-Platforms-&-Installation wiki page for additional information on platform support.

#### Installing and configuring the HSA Runtime

Download the HSA-Runtime-AMD from the repository: git clone https://github.com/HSAFoundation/HSA-Runtime-AMD.git

Install the appropriate package for the target operating system (Debian on Ubuntu 14.04 or RPM for Fedora 21). The libraries, header files and samples will be installed in the /opt/hsa directory of the system.

Ubuntu 14.04:

dpkg -i hsa-runtime_0.9_amd64.deb

Fedora 21:

rpm -i hsa-runtime-0.9-0.fc21.x86_64.rpm
 
Applications utilizing the HSA runtime must specify how the runtime is utilized, either as a explicitly loaded shared object or a library that is implicitly linked, and the runtime must be installed correctly for the application to appropriately utilize it. Please refer each application's specific documentation regarding runtime installation.

#### HSA Runtime / HSA Driver compatibility

The HSA Runtime interacts with the HSA drivers using an interface library, libhsakmt.so. This library is packaged with the HSA driver set, and is available in the HSA-Drivers-Linux-AMD repository at this link https://github.com/HSAFoundation/HSA-Drivers-Linux-AMD/tree/master/kfd-0.9/libhsakmt. The HSA Runtime is dynamically linked with this library, which must be compatible with both the runtime and the HSA driver to properly work. Any executable that uses the HSA runtime library will require that the directory containing a compatible version of libhsakmt.so is specified in the LD_LIBRARY_PATH environment variable.

#### Running the sample - vector_copy ####

A simple sample, vector_copy, is provided in the samples directory of this repository. The sample requires the libelf-dev package to build and execute. This package can be installed on Ubuntu by executing 'sudo apt-get install libelf-dev'. For Fedora 21, execute 'yum install elfutils-libelf-devel'.

To build the sample, simply issue the 'make' command in the sample directory. This will create the vectory_copy host executable. 

When executed, vectory_copy will load the vector_copy.brig ELF file, finalize the associated kernel and execute it on an available GPU device. Both the libhsa-runtime and libhsakmt shared object library directories must be in the LD_LIBRARY_PATH environment variable.

A successful execution will print messages similar to the following:

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

#### Q & A
1. **I keep getting an error saying *'error while loading shared libraries: libhsakmt.so.1: cannot open shared object file: No such file or directory'*?**
  * The libhsakmt.so.1 library directory isn't in the LD\_LIBRARY\_PATH or the version of libhsamkt.so.1 is incorrect.

2. **I can initialize the runtime, using hsa\_init, but there is no GPU device?**
  * The /dev/kfd device is not properly initialized or it has the wrong permissions assigned to it. The command 'ls -l /dev/kfd' will list the permission on the kfd device. The device /dev/kfd should exist and have 0666 permissions assigned to it. Consult the HSA driver documentation for information on how to configure the kfd device.

3. **How do you disassemble a finalized binary of an HSAIL program (in device native ISA)?**
  * You can either pass the "-cf-dump-isa" to options in hsa\_ext\_finalize\_program or set the environment variable CORE\_FINALIZER\_APPEND\_OPTIONS="-cf-dump-isa".

#### Known Issues

* The HSAIL Linker Service Layer does not resolve inter-module dependencies. Modules cannot contain declarations that correspond to definitions in other modules.
* Extension query not fully supported, specifically hsa_vendor_extension_query not supported.
* Asynchronous errors not supported.
* CPU finalization not possible.
* Added enums to hsa.h: HSA_AGENT_INFO_COUNT HSA_REGION_INFO_COUNT
* Added extension enum: HSA_EXT_AMD_PROFILE
* Added profiling extension.
* Added incoherent memory extension.
* Signals do not support multiple concurrent waiters.
* hsa_packet_header_t is defined with uint16_t bit fields rather than enums.
* By default HSA Runtime limits queue creation to 10, but can be changed by exporting HSA_MAX_QUEUES=<#queues> prior to running the app.

#### Disclaimer

The information contained herein is for informational purposes only, and is subject to change without notice. While every precaution has been taken in the preparation of this document, it may contain technical inaccuracies, omissions and typographical errors, and AMD is under no obligation to update or otherwise correct this information. Advanced Micro Devices, Inc. makes no representations or warranties with respect to the accuracy or completeness of the contents of this document, and assumes no liability of any kind, including the implied warranties of noninfringement, merchantability or fitness for particular purposes, with respect to the operation or use of AMD hardware, software or other products described herein. No license, including implied or arising by estoppel, to any intellectual property rights is granted by this document. Terms and limitations applicable to the purchase or use of AMD's products are as set forth in a signed agreement between the parties or in AMD's Standard Terms and Conditions of Sale.

AMD, the AMD Arrow logo, and combinations thereof are trademarks of Advanced Micro Devices, Inc. Other product names used in this publication are for identification purposes only and may be trademarks of their respective companies.

Copyright (c) 2014 Advanced Micro Devices, Inc. All rights reserved.

University of Illinois/NCSA 
Open Source License 
 
Copyright (c) 2010 Apple Inc. 
All rights reserved. 
 
Developed by: 
 
    LLDB Team 
 
    http://lldb.llvm.org/ 
 
Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal with 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do 
so, subject to the following conditions: 
 
    * Redistributions of source code must retain the above copyright notice, 
      this list of conditions and the following disclaimers. 
 
    * Redistributions in binary form must reproduce the above copyright notice, 
      this list of conditions and the following disclaimers in the 
      documentation and/or other materials provided with the distribution. 
 
    * Neither the names of the LLDB Team, copyright holders, nor the names of  
      its contributors may be used to endorse or promote products derived from  
      this Software without specific prior written permission. 
 
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS 
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE 
CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE 
SOFTWARE. 
 
Open source files: 
  DataBuffer.h 
  DataBufferHeap.cpp 
  DataBufferHeap.h 
  DataEncoder.cpp 
  DataEncoder.h 
  DataExtractor.cpp 
  DataExtractor.h 
  DataTypes.h 
  Dwarf.cpp 
  Dwarf.h 
  DWARFDebugLine.cpp 
  DWARFDebugLine.h 
  DWARFDefines.cpp 
  DWARFDefines.h 
  File.cpp 
  File.h 
  Flags.h 
  lldb-dwarf.h 
  lldb-enumerations.h 
  lldb-types.h 
  SmallVector.cpp 
  SmallVector.h 
  Stream.cpp 
  Stream.h 
  StreamBuffer.h 
  StreamFile.cpp 
  StreamFile.h 
  SwapByteOrder.h 
  type_traits.h

ANTLR 4 License
[The BSD License]
Copyright (c) 2012 Terence Parr and Sam Harwell
All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met: 

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. 

    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution. 

Neither the name of the author nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

