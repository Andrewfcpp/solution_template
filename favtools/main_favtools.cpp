//    Author: Andrejs Fjodorovs (Andrew)
//    Mail:   andfjod@yahoo.com
//    Date:   2024, April, 1

#ifndef NDEBUG
//Enable tests
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_RUN doctest_run();
#else
//Disable tests and remove from binary
#define DOCTEST_CONFIG_DISABLE
#pragma message("Warning: All tests will be disabled in Release mode! To use tests set Debug mode.")
#define DOCTEST_RUN /*NOTHING*/
#endif

#include "doctest.h"



//Do not remove! Use DOCTEST_RUN; in main() to run all tests.
#ifndef NDEBUG
void doctest_run()
{
    doctest::Context context;

    context.setOption("abort-after", 5); // stop test execution after 5 failed assertions
    context.setOption("order-by", "file"); //Sort the tests by

    context.setOption("no-intro", true); //Doctest version etc.
    context.setOption("duration", true); //Print name and test time
    context.setOption("success", true); //Print test details
    context.setOption("no-path-filenames", true);
    context.setOption("no-breaks", true); // don't break in the debugger when assertions fail
    context.setOption("no-debug-output", true); //Disables output in the debug console when a debugger is attached

    //int res = context.run(); //Get test status.
    context.run();
}
#endif



//***********************************************************************/



#include <cstddef>
#include <cstdint>
#include <iostream>
#include <cstddef>
#include <cstdint>
#include <chrono>
#include <vector>
#include <limits>
#include <string>
#include <array>

//spdlog includes
#include "log_macros.h"
#include "log_manager.h"

//{fmt} includes
//#include <fmt/core.h>
//#include <fmt/format.h>
//#include <fmt/print.h>
#include <fmt/ranges.h>
#include <fmt/chrono.h>
#include <fmt/color.h>

//assertions
#include "include/assert_msg.h"



//***********************************************************************/



//Test function example.
int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

//Make tests.
TEST_CASE("Testing the factorial function")
{
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}



//size_t roundup(size_t n) { return (((n - 1) >> 21) + 1) << 21; }

//bool is_empty() { return true; }
//void test() { ASSERT_FN_MSG(is_empty(), "Returns true."); }



void test_logger()
{
    //Init at begin
    LogManager log_manager;
    log_manager.init();

    //Using SpdLog, examples.
    LOG_TRACE("Hello from favtools! ver.{}.{}.{}", 0, 0, 1);
    LOG_TRACE("LOG_TRACE");
    LOG_DEBUG("LOG_DEBUG");
    LOG_INFO("LOG_INFO");
    LOG_WARN("LOG_WARN");
    LOG_ERROR("LOG_ERROR");
    LOG_FATAL("LOG_FATAL");

    //Shutdown at end
    log_manager.shutdown();
}

void test_fmt()
{
    fmt::print("Hello from fmt! {}\n", 12345);

    std::array<int, 3> v{ 1,2,3 };
    //std::vector<int> v = { 1, 2, 3 };
    fmt::print("{}\n", v);
    
    auto now = std::chrono::system_clock::now();
    fmt::print("Date and time: {}\n", now);
    fmt::print("Time: {:%H:%M}\n", now);

    std::string s = fmt::format("I'd rather be {1} than {0}.\n", "right", "happy");
    // s == "I'd rather be happy than right."
    fmt::print(s);

    //fmt::print("{}\n", std::numeric_limits<double>::infinity());

    //For terminal with Unicode support. ???

    //fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, "Hello, {}!\n", "world");
    //fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) | fmt::emphasis::underline, "Hello, {}!\n", "friends");

    //std::string cpp = fmt::format(fg(fmt::rgb(0xFFFF00)), "RGB string \n");
    //fmt::print("{}", cpp);

    //fmt::print(fg(fmt::color::red), "{}/n", 123); // foreground color is red
    //fmt::print(bg(fmt::color::red), "{}/n", 123); // background is red
}


int main(/*int argc, char** argv*/)
{
    std::cout << "Hello!" << '\n' << '\n';



    DOCTEST_RUN;
    std::cout << '\n' << '\n';



    test_logger();
    std::cout << '\n' << '\n';



    test_fmt();
    std::cout << '\n' << '\n';



    std::cout << '\n' << '\n' << "Exit." << '\n' << '\n';
    //system("pause 0");
    std::cin.get();
    return 0;
}