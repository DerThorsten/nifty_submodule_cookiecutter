
#-------------------------------------------------------------------------------------------------------------------
# Setup unit testing
#-------------------------------------------------------------------------------------------------------------------

#------------------------------------
# download doctests
#-----------------------------------
ExternalProject_Add(
    external_doctest
    PREFIX ${CMAKE_BINARY_DIR}/external_projects/doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    TIMEOUT 10
    #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(external_doctest source_dir)
set(DOCTEST_INCLUDE_DIR ${source_dir}/doctest CACHE INTERNAL "Path to include folder for doctest")
MESSAGE(STATUS DOCTEST_INCLUDE_DIR ${DOCTEST_INCLUDE_DIR})
include_directories(${DOCTEST_INCLUDE_DIR})


# meta target for all to handle dependencies
add_custom_target(externl_headers_test)
add_dependencies(externl_headers_test
    externl_headers 
    external_doctest
)

#-------------------------------------------------------------------------------------------------------------------
# Add Unit Tests
#-------------------------------------------------------------------------------------------------------------------
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(REMOVE_ITEM files "test_nifty_{{ cookiecutter.submod_name }}")

# test executable
add_executable(test_nifty_{{ cookiecutter.submod_name }} test_nifty_{{ cookiecutter.submod_name }}.cpp ${files})

# declare the executable as test
add_test(NAME test_nifty_{{ cookiecutter.submod_name }} COMMAND test_nifty_{{ cookiecutter.submod_name }})

# add dependencies 
add_dependencies(test_nifty_{{ cookiecutter.submod_name }} externl_headers_test)