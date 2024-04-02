
//Manual doctest switch. Comment to disable tests.
#define DOCTEST_ENABLE

#ifdef DOCTEST_ENABLE
//Enable tests
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_RUN doctest_run();
#else
//Disable tests and remove from binary
#define DOCTEST_CONFIG_DISABLE
#pragma message("Warning: All tests disabled in Release mode! Change to Debug mode.")
#define DOCTEST_RUN /*NOTHING*/
#endif

#include "doctest.h"



//Do not remove! Use DOCTEST_RUN; in main() to run all tests.
#ifdef DOCTEST_ENABLE
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
                    
    context.run(); //int res = context.run(); //Get test status.
}
#endif



#include <cstddef>
#include <cstdint>
#include <iostream>



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




int main(/*int argc, char** argv*/)
{
    std::cout << "Hello!" << '\n' << '\n';



    //Run tests
    DOCTEST_RUN;



    std::cout << '\n' << '\n' << "Exit." << '\n' << '\n';
    std::cin.get();
    return 0;
}