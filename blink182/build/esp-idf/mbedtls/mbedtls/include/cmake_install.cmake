# Install script for directory: D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/blink182")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/UpBc/.espressif/tools/riscv32-esp-elf/esp-2022r1-11.2.0/riscv32-esp-elf/bin/riscv32-esp-elf-objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/build_info.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/compat-2.x.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/config_psa.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/constant_time.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/legacy_or_psa.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/lms.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/mbedtls_config.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/pkcs7.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/private_access.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/psa_util.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_composites.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_builtin_primitives.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_compat.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_config.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_common.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_composites.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_driver_contexts_primitives.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_extra.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_platform.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_se_driver.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_sizes.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_struct.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_types.h"
    "D:/UPBC/USER/esp-idf/components/mbedtls/mbedtls/include/psa/crypto_values.h"
    )
endif()

