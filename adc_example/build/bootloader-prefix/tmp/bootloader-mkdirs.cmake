# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/UPBC/USER/esp-idf/components/bootloader/subproject"
  "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader"
  "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader-prefix"
  "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader-prefix/tmp"
  "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader-prefix/src/bootloader-stamp"
  "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader-prefix/src"
  "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/UPBC/USER/esp-idf/projects/adc_example/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
