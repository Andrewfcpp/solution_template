#if !defined NDEBUG
#error "Error: Debug mode is useless for benchmark! Change to Release mode."
#endif


#include <iostream>
#include <cstddef>
#include <cstdint>

//#pragma comment(lib, "external/benchmark/build/src/Release/benchmark.lib")
//#pragma comment(lib, "external/benchmark/build/src/Release/benchmark_main.lib")
//#pragma comment ( lib, "Shlwapi.lib" )
//#include "benchmark/benchmark.h"

#define BENCHMARK_STATIC_DEFINE //Important!
#include "benchmark/benchmark.h"




/*Simple fast operation for reference.*/
void bm_fast(benchmark::State& state)
{
    int a = 1;
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(++a);
        //v.push_back(42);
        //ClobberMemory(); //Force 42 to be written to memory.
    }
}




//Set as startup project and run in release mode!
int main(/*int argc, char** argv*/)
{
    std::cout << "Benchmark started." << '\n' << '\n';

    ///benchmark::Initialize();

    //BENCHMARK(bm_fast)->Unit(benchmark::kMillisecond); //Time units
    //benchmark::AddCustomContext("text1", "aaa"); //Add custom text after intro.




    std::cout << '\n' << '\n';
    BENCHMARK(bm_fast)->Name("Fast operation for reference"); //Register benchmark with custom name.
    //BENCHMARK(bm_fast)->Name("--------");





    benchmark::RunSpecifiedBenchmarks();
    benchmark::ClearRegisteredBenchmarks();
    benchmark::Shutdown();

    std::cout << '\n' << '\n' << "Exit benchmark." << '\n' << '\n';
    //system("pause 0");
    std::cin.get();
    return 0;
}