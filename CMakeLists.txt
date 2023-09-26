cmake_minimum_required(VERSION 3.10)

project(DicomNode VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Find the DCMTK package
find_package(DCMTK CONFIG REQUIRED)

# Add your source files here
add_executable(DicomNode main.cpp)
# add_library(foo SHARED foo.cxx)
set_property(TARGET DicomNode PROPERTY CXX_STANDARD 17) # see this for why these lines are added. https://github.com/microsoft/vcpkg/issues/31395#issuecomment-1571881282
target_compile_options(DicomNode PUBLIC "/Zc:__cplusplus")

# Link the required DCMTK libraries to your executable
target_link_libraries(DicomNode PRIVATE DCMTK::DCMTK)


    # You may also need one or more of the following targets:
    # DCMTK::cmr DCMTK::i2d DCMTK::ijg8 DCMTK::config DCMTK::ofstd
    # DCMTK::oflog DCMTK::dcmdata DCMTK::dcmimgle DCMTK::dcmimage
    # DCMTK::dcmjpeg DCMTK::ijg12 DCMTK::ijg16 DCMTK::dcmjpls
    # DCMTK::dcmtkcharls DCMTK::dcmtls DCMTK::dcmnet DCMTK::dcmsr
    # DCMTK::dcmdsig DCMTK::dcmwlm DCMTK::dcmqrdb DCMTK::dcmpstat
    # DCMTK::dcmrt DCMTK::dcmiod DCMTK::dcmfg DCMTK::dcmseg
    # DCMTK::dcmtract DCMTK::dcmpmap DCMTK::dcmect

    if ("${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}" STREQUAL "/")
        message(WARNING "No vcpkg install dir found, DCMTK definitions are not set")
    else()
        target_compile_definitions(DicomNode
            PUBLIC
                "DCMTK_PREFIX=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}"
                "DCM_DICT_DEFAULT_PATH=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/dcmtk/dicom.dic:${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/dcmtk/private.dic"
                "DEFAULT_CONFIGURATION_DIR=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/etc/dcmtk/"
                "DEFAULT_SUPPORT_DATA_DIR=${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/dcmtk/"
        )
    endif()


