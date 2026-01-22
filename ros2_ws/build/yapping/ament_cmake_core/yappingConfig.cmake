# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_yapping_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED yapping_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(yapping_FOUND FALSE)
  elseif(NOT yapping_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(yapping_FOUND FALSE)
  endif()
  return()
endif()
set(_yapping_CONFIG_INCLUDED TRUE)

# output package information
if(NOT yapping_FIND_QUIETLY)
  message(STATUS "Found yapping: 0.0.0 (${yapping_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'yapping' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${yapping_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(yapping_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${yapping_DIR}/${_extra}")
endforeach()
