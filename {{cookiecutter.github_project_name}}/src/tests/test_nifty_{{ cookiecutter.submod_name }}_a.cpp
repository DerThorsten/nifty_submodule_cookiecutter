#include "doctest.h"

#include "xtensor/xtensor.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xarray.hpp"
#include "xtensor/xtensor.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xutils.hpp"
#include "xtensor/xbuilder.hpp"

TEST_SUITE_BEGIN("nifty_{{ cookiecutter.submod_name }}");

TEST_CASE( "some test case" ) {


    auto image_in  = xt::ones<double>({100, 100});
    auto image_out = xt::xtensor<double, 2   >({100, 100});


}


TEST_SUITE_END();